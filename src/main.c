
#include "../inc/cub3D.h"

t_global	*g(void)
{
    static t_global global;
    return (&global);
}

int	main(int ac, char **av)
{
    if (ac != 2)
        ft_exit("Wrong Number of Arguments");
    pars_map(av[1]);
	return (0);
}