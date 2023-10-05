#include "../../inc/cub3D.h"

int	calc_map_size(int size)
{
	int	y;
	int	res;

	(void)size;
	y = 0;
	res = 0;
	while (g()->map[y])
	{
		if (ft_strchr(g()->map[y], '1'))
			res++;
		y++;
	}
	return (res);
}

void	alloc_final_map(void)
{
	t_global	*gl;
	int			size;
	size_t		final_map_size;

	gl = g();
	size = ft_2darr_len(g()->map);
	final_map_size = calc_map_size(size);
	gl->final_map = ft_calloc(final_map_size, sizeof(int *));
	if (!gl->final_map)
		ft_exit_free("Calloc failed");
	gl->parsing.final_map_size = final_map_size;
	gl->parsing.final_map_longest_line = find_longest_line(g()->map);
}

void	calloc_final_map_line(int new_y)
{
	t_global	*gl;

	gl = g();
	gl->final_map[new_y] = (int *)calloc(gl->parsing.final_map_longest_line,
			sizeof(int));
	if (!gl->final_map[new_y])
		ft_exit_free("Calloc failed");
}

void	make_final_map(void)
{
	t_global	*gl;
	int			x;
	int			y;
	int			new_y;

	gl = g();
	y = -1;
	new_y = 0;
	alloc_final_map();
	while (gl->map[++y])
	{
		if (ft_strchr(gl->map[y], '1'))
		{
			calloc_final_map_line(new_y);
			x = -1;
			while (gl->map[y][++x])
			{
				if (gl->map[y][x] == '1')
					gl->final_map[new_y][x] = 1;
				else
					gl->final_map[new_y][x] = 0;
			}
			new_y++;
		}
	}
}
