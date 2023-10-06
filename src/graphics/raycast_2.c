#include "../../inc/cub3D.h"

uint32_t	rgba_color(uint32_t color)
{
	return (((color & 0xFF000000) >> 24) 
		| ((color & 0x00FF0000) >> 8)
		| ((color & 0x0000FF00) << 8)
		| ((color & 0x000000FF) << 24));
}

void	init_raycast(int x, t_player *player)
{
	t_global	*gl;
	t_raycast	*raycast;

	gl = g();
	raycast = &g()->raycast;
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

void	cal_tex_x(t_player *player)
{
	t_global	*gl;
	t_raycast	*raycast;

	gl = g();
	raycast = &g()->raycast;
	if (raycast->side == 0)
		raycast->wallX = player->pos_y + raycast->perpWallDist
			* raycast->ray_dir_y;
	else
		raycast->wallX = player->pos_x + raycast->perpWallDist
			* raycast->ray_dir_x;
	raycast->wallX -= floor(raycast->wallX);
	raycast->tex_x = (int)(raycast->wallX
			* (double)gl->texture[raycast->texNum]->width);
}

void	draw_wall(int x, mlx_image_t *image)
{
	t_global	*gl;
	t_raycast	*raycast;
	int			d;
	int			y;

	gl = g();
	raycast = &g()->raycast;
	y = raycast->drawStart;
	while (y < raycast->drawEnd)
	{
		d = y * 256 - VIEW_HEIGHT * 128 + raycast->lineHeight * 128;
		raycast->tex_y = ((d * gl->texture[raycast->texNum]->height)
				/ raycast->lineHeight) / 256;
		raycast->color = *((uint32_t *)gl->texture[raycast->texNum]->pixels
				+ (raycast->tex_y * gl->texture[raycast->texNum]->width
					+ raycast->tex_x));
		raycast->new_color = rgba_color(raycast->color);
		mlx_put_pixel(image, x, y, raycast->new_color);
		y++;
	}
}

void	raycast(t_player player, mlx_image_t *image)
{
	int			x;
	t_global	*gl;
	t_raycast	*raycast;

	x = 0;
	while (x < VIEW_WIDTH)
	{
		gl = g();
		raycast = &g()->raycast;
		init_raycast(x, &player);
		cal_side_dist_x(&player);
		cal_side_dist_y(&player);
		dda();
		wall_height(&player);
		calum_dist();
		cal_tex_x(&player);
		draw_wall(x, image);
		x++;
	}
}
