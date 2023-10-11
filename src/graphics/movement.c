/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:46:28 by oboucher          #+#    #+#             */
/*   Updated: 2023/10/11 11:46:30 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	w_s_movement(double *new_x, double *new_y, t_player *player,
		t_global *gl)
{
	if (mlx_is_key_down(gl->mlx, MLX_KEY_W))
	{
		*new_x = gl->player.pos_x + gl->player.dir_x * player->move_speed;
		*new_y = gl->player.pos_y + gl->player.dir_y * player->move_speed;
		if (gl->final_map[(int)(*new_x + gl->player.dir_x
				* HITBOX)][(int)gl->player.pos_y] == 0)
			gl->player.pos_x = *new_x;
		if (gl->final_map[(int)gl->player.pos_x][(int)(*new_y + gl->player.dir_y
			* HITBOX)] == 0)
			gl->player.pos_y = *new_y;
	}
	if (mlx_is_key_down(gl->mlx, MLX_KEY_S))
	{
		*new_x = gl->player.pos_x - gl->player.dir_x * player->move_speed;
		*new_y = gl->player.pos_y - gl->player.dir_y * player->move_speed;
		if (gl->final_map[(int)(*new_x + gl->player.dir_x * -HITBOX)]
			[(int)gl->player.pos_y] == 0)
			gl->player.pos_x = *new_x;
		if (gl->final_map[(int)gl->player.pos_x]
			[(int)(*new_y + gl->player.dir_y * -HITBOX)] == 0)
			gl->player.pos_y = *new_y;
	}
}

static void	a_d_movement(double *new_x, double *new_y, t_player *player,
		t_global *gl)
{
	if (mlx_is_key_down(gl->mlx, MLX_KEY_A))
	{
		*new_x = gl->player.pos_x - gl->player.dir_y * player->move_speed;
		*new_y = gl->player.pos_y + gl->player.dir_x * player->move_speed;
		if (gl->final_map[(int)(*new_x - gl->player.dir_y * HITBOX)]
			[(int)gl->player.pos_y] == 0)
			gl->player.pos_x = *new_x;
		if (gl->final_map[(int)gl->player.pos_x]
			[(int)(*new_y + gl->player.dir_x * HITBOX)] == 0)
			gl->player.pos_y = *new_y;
	}
	if (mlx_is_key_down(gl->mlx, MLX_KEY_D))
	{
		*new_x = gl->player.pos_x + gl->player.dir_y * player->move_speed;
		*new_y = gl->player.pos_y - gl->player.dir_x * player->move_speed;
		if (gl->final_map[(int)(*new_x + gl->player.dir_y * HITBOX)]
			[(int)gl->player.pos_y] == 0)
			gl->player.pos_x = *new_x;
		if (gl->final_map[(int)gl->player.pos_x]
			[(int)(*new_y - gl->player.dir_x * HITBOX)] == 0)
			gl->player.pos_y = *new_y;
	}
}

void	player_movement(void)
{
	t_global	*gl;
	t_player	*player;
	double		new_x;
	double		new_y;

	gl = g();
	player = &g()->player;
	if (mlx_is_key_down(gl->mlx, MLX_KEY_LEFT_SHIFT))
		player->move_speed = MAX_SPEED;
	else
		player->move_speed = MIN_SPEED;
	w_s_movement(&new_x, &new_y, player, g());
	a_d_movement(&new_x, &new_y, player, g());
}
