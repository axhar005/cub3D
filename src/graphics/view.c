/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:47:20 by oboucher          #+#    #+#             */
/*   Updated: 2023/10/11 12:05:31 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	rotate_view(double theta)
{
	t_player	*player;
	double		old_dir_x;
	double		old_plane_x;

	player = &g()->player;
	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(theta) - player->dir_y * sin(theta);
	player->dir_y = old_dir_x * sin(theta) + player->dir_y * cos(theta);
	player->plane_x = player->plane_x * cos(theta) - player->plane_y
		* sin(theta);
	player->plane_y = old_plane_x * sin(theta) + player->plane_y * cos(theta);
}

void	player_rotation(void)
{
	int	rot_speed;

	if (mlx_is_key_down(g()->mlx, MLX_KEY_LEFT_SHIFT))
		rot_speed = MAX_ROT_SPEED;
	else
		rot_speed = MIN_ROT_SPEED;
	if (mlx_is_key_down(g()->mlx, MLX_KEY_LEFT))
	{
		rotate_view(rot_speed * M_PI / 180.0);
	}
	if (mlx_is_key_down(g()->mlx, MLX_KEY_RIGHT))
	{
		rotate_view(-rot_speed * M_PI / 180.0);
	}
}

void	mouse_view_rotation(double xpos, double ypos, void *param)
{
	static double	prev_x = 850;

	(void)ypos;
	(void)param;
	if (g()->tab == false)
	{
		rotate_view(((prev_x - xpos) * (M_PI / 180.0)) * SENSIBILITY);
		prev_x = xpos;
	}
}

static void	set_player_dir(double dir_x, double dir_y, double plane_x,
		double plane_y)
{
	g()->player.dir_x = dir_x;
	g()->player.dir_y = dir_y;
	g()->player.plane_x = plane_x;
	g()->player.plane_y = plane_y;
}

void	change_player_dir(char c)
{
	if (c == 'E')
		set_player_dir(0, 1, 0.85, 0);
	else if (c == 'N')
		set_player_dir(-1, 0, 0, 0.85);
	else if (c == 'S')
		set_player_dir(1, 0, 0, -0.85);
	else
		set_player_dir(0, -1, -0.85, 0);
}
