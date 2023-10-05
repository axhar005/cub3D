
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

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_exit("Wrong number of arguments");
	check_extension(av[1]);
	pars_map(av[1]);
	printf("NORD %s\n", g()->parsing.north);
	printf("SOUTH %s\n", g()->parsing.south);
	printf("WEST %s\n", g()->parsing.west);
	printf("EAST %s\n", g()->parsing.east);
	printf("COLOR F %lu\n", g()->parsing.color_f);
	printf("COLOR C %lu\n", g()->parsing.color_c);
	printf("DIR %c\n", g()->parsing.player_dir);
	free_all();
	return (0);
}