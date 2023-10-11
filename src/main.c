/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:45:50 by oboucher          #+#    #+#             */
/*   Updated: 2023/10/11 11:45:52 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_global	*g(void)
{
	static t_global	global;

	return (&global);
}

void	entry(void)
{
	static bool	tab = false;

	if (mlx_is_key_down(g()->mlx, MLX_KEY_ESCAPE))
		ft_exit_free("", 1);
	if (tab == false && mlx_is_key_down(g()->mlx, MLX_KEY_TAB))
	{
		mlx_set_cursor_mode(g()->mlx, MLX_MOUSE_NORMAL);
		tab = true;
	}
	else if (tab == true && mlx_is_key_down(g()->mlx, MLX_KEY_TAB))
	{
		mlx_set_cursor_mode(g()->mlx, MLX_MOUSE_DISABLED);
		tab = false;
	}
}

void	step(void *param)
{
	static double	frame;
	t_global		*gl;

	(void)param;
	gl = g();
	gl->delta_time = gl->mlx->delta_time * FPS;
	if (frame >= 1)
	{
		ft_bzero(gl->image->pixels, (VIEW_HEIGHT * VIEW_WIDTH) * sizeof(int));
		raycast(gl->player, gl->image);
		draw_minimap(&gl->minimap);
		draw_cross(VIEW_WIDTH / 2, VIEW_HEIGHT / 2,
			rgba_color(255, 255, 255, 255));
	}
	frame += gl->delta_time;
	entry();
	player_rotation();
	player_movement();
}

void	init(t_global *gl)
{
	gl->player.pos_x = gl->parsing.player_pos.y + 0.5;
	gl->player.pos_y = gl->parsing.player_pos.x + 0.5;
	gl->player.move_speed = 0.03;
	gl->minimap.pos_x = 10;
	gl->minimap.pos_y = 10;
	gl->minimap.width = 9;
	gl->minimap.height = 5;
	gl->minimap.slot_size = 32;
	gl->minimap.wall_color = rgba_color(72, 61, 139, 255);
	gl->minimap.floor_color = rgba_color(60, 179, 113, 255);
	gl->minimap.player_color = rgba_color(255, 99, 71, 255);
	gl->minimap.background_color = rgba_color(34, 34, 34, 255);
	mlx_set_cursor_mode(gl->mlx, MLX_MOUSE_DISABLED);
}

int	main(int ac, char **av)
{
	t_global	*gl;

	gl = g();
	if (ac != 2)
		ft_exit("Wrong number of arguments");
	check_extension(av[1]);
	pars_file(av[1]);
	change_player_dir(gl->parsing.player_dir);
	gl->mlx = mlx_init(VIEW_WIDTH, VIEW_HEIGHT, "Cub3D", false);
	gl->background = mlx_new_image(gl->mlx, VIEW_WIDTH, VIEW_HEIGHT);
	gl->image = mlx_new_image(gl->mlx, VIEW_WIDTH, VIEW_HEIGHT);
	mlx_image_to_window(gl->mlx, gl->background, 0, 0);
	set_background(gl->background, gl->parsing.color_c, gl->parsing.color_f);
	mlx_image_to_window(gl->mlx, gl->image, 0, 0);
	load_init_texture();
	init(g());
	mlx_loop_hook(gl->mlx, step, NULL);
	mlx_cursor_hook(gl->mlx, mouse_view_rotation, NULL);
	mlx_loop(gl->mlx);
	free_all();
	mlx_terminate(gl->mlx);
	return (EXIT_SUCCESS);
}
