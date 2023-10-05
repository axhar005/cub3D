#include "../../inc/cub3D.h"

static void	w_s_movement(double *new_x, double *new_y, t_player *player,
		t_global *gl)
{
	if (mlx_is_key_down(gl->mlx, MLX_KEY_W))
	{
		*new_x = gl->player.posX + gl->player.dirX * player->move_speed;
		if (gl->map[(int)(*new_x + gl->player.dirX
				* HITBOX)][(int)gl->player.posY] == 0)
			gl->player.posX = *new_x;
		*new_y = gl->player.posY + gl->player.dirY * player->move_speed;
		if (gl->map[(int)gl->player.posX][(int)(*new_y + gl->player.dirY
			* HITBOX)] == 0)
			gl->player.posY = *new_y;
	}
	if (mlx_is_key_down(gl->mlx, MLX_KEY_S))
	{
		*new_x = gl->player.posX - gl->player.dirX * player->move_speed;
		if (gl->map[(int)(*new_x + gl->player.dirX * -HITBOX)]
			[(int)gl->player.posY] == 0)
			gl->player.posX = *new_x;
		*new_y = gl->player.posY - gl->player.dirY * player->move_speed;
		if (gl->map[(int)gl->player.posX]
			[(int)(*new_y + gl->player.dirY * -HITBOX)] == 0)
			gl->player.posY = *new_y;
	}
}

static void	a_d_movement(double *new_x, double *new_y, t_player *player,
		t_global *gl)
{
	if (mlx_is_key_down(gl->mlx, MLX_KEY_A))
	{
		*new_x = gl->player.posX - gl->player.dirY * player->move_speed;
		*new_y = gl->player.posY + gl->player.dirX * player->move_speed;
		if (gl->map[(int)(*new_x - gl->player.dirY * HITBOX)]
			[(int)gl->player.posY] == 0)
			gl->player.posX = *new_x;
		if (gl->map[(int)gl->player.posX]
			[(int)(*new_y + gl->player.dirX * HITBOX)] == 0)
			gl->player.posY = *new_y;
	}
	if (mlx_is_key_down(gl->mlx, MLX_KEY_D))
	{
		*new_x = gl->player.posX + gl->player.dirY * player->move_speed;
		*new_y = gl->player.posY - gl->player.dirX * player->move_speed;
		if (gl->map[(int)(*new_x + gl->player.dirY * HITBOX)]
			[(int)gl->player.posY] == 0)
			gl->player.posX = *new_x;
		if (gl->map[(int)gl->player.posX]
			[(int)(*new_y - gl->player.dirX * HITBOX)] == 0)
			gl->player.posY = *new_y;
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
