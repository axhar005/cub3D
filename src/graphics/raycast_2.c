/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:47:09 by oboucher          #+#    #+#             */
/*   Updated: 2023/10/11 11:47:11 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

uint32_t	rgba_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

static void	init_raycast(int x, t_player *player, t_raycast *raycast)
{
	raycast->camera_x = 2 * x / (double)VIEW_WIDTH - 1;
	raycast->ray_dir_x = player->dir_x + player->plane_x * raycast->camera_x;
	raycast->ray_dir_y = player->dir_y + player->plane_y * raycast->camera_x;
	raycast->map_x = (int)player->pos_x;
	raycast->map_y = (int)player->pos_y;
	raycast->delta_dist_x = fabs(1 / raycast->ray_dir_x);
	raycast->delta_dist_y = fabs(1 / raycast->ray_dir_y);
	raycast->hit = 0;
	raycast->side = 0;
}

static void	cal_tex_x(t_player *player, t_global *gl, t_raycast *raycast)
{
	if (raycast->side == 0)
		raycast->wall_x = player->pos_y + raycast->perp_wall
			* raycast->ray_dir_y;
	else
		raycast->wall_x = player->pos_x + raycast->perp_wall
			* raycast->ray_dir_x;
	raycast->wall_x -= floor(raycast->wall_x);
	raycast->tex_x = (int)(raycast->wall_x
			* (double)gl->texture[raycast->tex_num]->width);
}

static void	draw_wall(int x, mlx_image_t *image, t_global *gl
	, t_raycast *raycast)
{
	int	d;
	int	y;

	y = raycast->draw_start;
	while (y < raycast->draw_end)
	{
		d = y * 256 - VIEW_HEIGHT * 128 + raycast->line_height * 128;
		raycast->tex_y = ((d * gl->texture[raycast->tex_num]->height)
				/ raycast->line_height) / 256;
		raycast->color = gl->texture[raycast->tex_num]->pixels + (raycast->tex_y
				* gl->texture[raycast->tex_num]->width + raycast->tex_x) * 4;
		raycast->new_color = rgba_color(raycast->color[0], raycast->color[1],
				raycast->color[2], raycast->color[3]);
		mlx_put_pixel(image, x, y, raycast->new_color);
		y++;
	}
}

void	raycast(t_player player, mlx_image_t *image)
{
	int			x;
	t_global	*gl;

	x = 0;
	gl = g();
	while (x < VIEW_WIDTH)
	{
		init_raycast(x, &player, &gl->raycast);
		cal_side_dist_x(&player, &gl->raycast);
		cal_side_dist_y(&player, &gl->raycast);
		dda(gl, &gl->raycast);
		wall_height(&player, &gl->raycast);
		calum_dist(&gl->raycast);
		cal_tex_x(&player, gl, &gl->raycast);
		draw_wall(x, image, gl, &gl->raycast);
		x++;
	}
}
