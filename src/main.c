
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

void step(void)
{
    //
}

int	main(int ac, char **av)
{
   /*  int width = 100;
    int height = 100; */

	if (ac != 2)
		ft_exit("Wrong number of arguments");
	check_extension(av[1]);
	init_struct();
	pars_map(av[1]);
	/* g()->mlx = mlx_init(width, height, "NAME", false);
	mlx_loop_hook(g()->mlx, step, NULL);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx); */
	for (int i = 0; i < g()->parsing.final_map_size; i++)
	{
		for (int j = 0; j < g()->parsing.final_map_longest_line; j++)
		{
			printf("%d", g()->final_map[i][j]);
		}
		printf("\n");
	}
	free_all();
	return (0);
}