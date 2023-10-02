
#include "inc/cub3D.h"

t_global	*g(void)
{
    static t_global global;
    return (&global);
}

void step(void)
{
    //
}

int	main(int ac, char **av)
{
    int width = 100;
    int height = 100;

	if (ac == 2)
	{
        //parsing
	}
	else
		ft_exit("Error> one argument needed (map.ber)");

	g()->mlx = mlx_init(width, height, "NAME", false);
	mlx_loop_hook(g()->mlx, step, NULL);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);
	return (EXIT_SUCCESS);
}