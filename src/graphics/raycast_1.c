/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:46:59 by oboucher          #+#    #+#             */
/*   Updated: 2023/10/11 11:47:01 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	cal_side_dist_x(t_player *player, t_raycast	*raycast)
{
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (player->pos_x - raycast->map_x)
			* raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = (raycast->map_x + 1.0 - player->pos_x)
			* raycast->delta_dist_x;
	}
}

void	cal_side_dist_y(t_player *player, t_raycast	*raycast)
{
	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (player->pos_y - raycast->map_y)
			* raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = (raycast->map_y + 1.0 - player->pos_y)
			* raycast->delta_dist_y;
	}
}

void	dda(t_global *gl, t_raycast	*raycast)
{
	while (1)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (gl->final_map[raycast->map_x][raycast->map_y] == 1)
			return ;
	}
}

void	wall_height(t_player *player, t_raycast	*raycast)
{
	if (raycast->side == 0)
		raycast->perp_wall = (raycast->map_x - player->pos_x + (1
					- raycast->step_x) / 2) / raycast->ray_dir_x;
	else
		raycast->perp_wall = (raycast->map_y - player->pos_y + (1
					- raycast->step_y) / 2) / raycast->ray_dir_y;
	raycast->line_height = (int)(VIEW_HEIGHT / raycast->perp_wall);
}

void	calum_dist(t_raycast *raycast)
{
	raycast->draw_start = -raycast->line_height / 2 + VIEW_HEIGHT / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->line_height / 2 + VIEW_HEIGHT / 2;
	if (raycast->draw_end >= VIEW_HEIGHT)
		raycast->draw_end = VIEW_HEIGHT - 1;
	if (raycast->side == 0)
	{
		if (raycast->step_x > 0)
			raycast->tex_num = 0;
		else
			raycast->tex_num = 1;
	}
	else
	{
		if (raycast->step_y > 0)
			raycast->tex_num = 2;
		else
			raycast->tex_num = 3;
	}
}
