
#include "inc/cub3D.h"

t_global	*g(void)
{
	static t_global	global;

	return (&global);
}

void	step(void *param)
{
	//
	(void)param;
}

int	main(int ac, char **av)
{
	//	1280 x 720
	int width = 1280;
	int height = 720;

	(void)av;
	(void)ac;

	g()->mlx = mlx_init(VIEW_HEIGHT, VIEW_WIDTH, "LE PLus Beau Cub3D", false);

	mlx_loop_hook(g()->mlx, step, NULL);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);
	return (EXIT_SUCCESS);
}