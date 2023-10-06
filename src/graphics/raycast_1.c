
#include "../../inc/cub3D.h"

void	cal_side_dist_x(t_player *player)
{
	t_global	*gl;
	t_raycast	*raycast;

	gl = g();
	raycast = &g()->raycast;
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

void	cal_side_dist_y(t_player *player)
{
	t_global	*gl;
	t_raycast	*raycast;

	gl = g();
	raycast = &g()->raycast;
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

void	dda(void)
{
	t_global	*gl;
	t_raycast	*raycast;

	gl = g();
	raycast = &g()->raycast;
	while (raycast->hit == 0)
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
		if (g()->map[raycast->map_x][raycast->map_y] > 0)
			raycast->hit = 1;
	}
}

void	wall_height(t_player *player)
{
	t_raycast	*raycast;

	raycast = &g()->raycast;
	if (raycast->side == 0)
		raycast->perpWallDist = (raycast->map_x - player->pos_x + (1
					- raycast->step_x) / 2) / raycast->ray_dir_x;
	else
		raycast->perpWallDist = (raycast->map_y - player->pos_y + (1
					- raycast->step_y) / 2) / raycast->ray_dir_y;
	raycast->lineHeight = (int)(VIEW_HEIGHT / raycast->perpWallDist);
}

void	calum_dist(void)
{
	t_raycast	*raycast;

	raycast = &g()->raycast;
	raycast->drawStart = -raycast->lineHeight / 2 + VIEW_HEIGHT / 2;
	if (raycast->drawStart < 0)
		raycast->drawStart = 0;
	raycast->drawEnd = raycast->lineHeight / 2 + VIEW_HEIGHT / 2;
	if (raycast->drawEnd >= VIEW_HEIGHT)
		raycast->drawEnd = VIEW_HEIGHT - 1;
	if (raycast->side == 0)
	{
		if (raycast->step_x > 0)
			raycast->texNum = 0;
		else
			raycast->texNum = 1;
	}
	else
	{
		if (raycast->step_y > 0)
			raycast->texNum = 2;
		else
			raycast->texNum = 3;
	}
}
