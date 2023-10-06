
#include "../inc/cub3D.h"

t_global	*g(void)
{
	static t_global	global;

	return (&global);
}

void	check_extension(char *map)
{
	int	i;

	i = ft_strlen(map) - 4;
	if (ft_strncmp(&map[i], ".cub", 4) != 0)
		ft_exit("Wrong type of file");
}

void	init_struct()
{
	g()->file = NULL;
}

void	ft_2darr_print(char **tb, int fd)
{
	int	i;

	i = 0;
	while (tb[i])
	{
		ft_putstr_fd(tb[i], fd);
		printf("\n");
		i++;
	}
	printf("\n");
}

void	step(void *param)
{
	static double	frame;
	t_global *gl;


	(void)param;
	gl = g();
	gl->delta_time = gl->mlx->delta_time * FPS;
	if (frame >= 1)
	{
		set_background(gl->image, g()->parsing.color_c, g()->parsing.color_f);
		raycast(gl->player, gl->image);
		change_player_dir(&gl->player, 'W');
		player_rotation();
		player_movement();
	}
	frame += gl->delta_time;
}

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_exit("Wrong number of arguments");
	check_extension(av[1]);
	init_struct();
	pars_file(av[1]);
	for (int i = 0; i < g()->parsing.final_map_size; i++)
	{
		for (int j = 0; j < g()->parsing.final_map_longest_line; j++)
		{
			printf("%d", g()->final_map[i][j]);
		}
		printf("\n");
	}

	g()->player.pos_x = 1.5;
	g()->player.pos_y = 1.5;
	g()->player.plane_x = 0;
	g()->player.plane_y = 0.66;
	g()->player.dir_x = -1;
	g()->player.dir_y = 0;
	g()->player.move_speed = 0.03;

	g()->mlx = mlx_init(VIEW_WIDTH, VIEW_HEIGHT, "Merci Chat", false);
	g()->image = mlx_new_image(g()->mlx, VIEW_WIDTH, VIEW_HEIGHT);
	mlx_image_to_window(g()->mlx, g()->image, 0, 0);
	load_init_texture();
	mlx_loop_hook(g()->mlx, step, NULL);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);

	free_all();
	return (EXIT_SUCCESS);
}