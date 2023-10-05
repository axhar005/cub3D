#include "../inc/cub3D.h"

void	validate_map(void)
{
	int	x;
	int	y;
	int	c;

	y = -1;
	/* ft_2darr_print(g()->flood_map, 1); */
	while (g()->flood_map[++y])
	{
		x = -1;
		while (g()->flood_map[y][++x])
		{
			c = g()->flood_map[y][x];
			if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
			{
				if (!g()->parsing.player_dir)
					g()->parsing.player_dir = c;
				else
					ft_exit_free("Only one player permitted\n");
				g()->parsing.player_pos.x = x;
				g()->parsing.player_pos.y = y;
			}
			else if (c != '1' && c != '0' && c != '\n' && c != '\0'
				&& !ft_isspace(c))
			{
				ft_exit_free("Parsing map error\n");
			}
		}
	}
}

void	transform_map(void)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (g()->map[y])
	{
		x = 0;
		while (g()->map[y][x])
		{
			if (g()->map[y][x] == '\n')
				g()->map[y][x] = '\0';
			if (g()->map[y][x] != '0' && g()->map[y][x] != '1'
				&& g()->map[y][x] != '\0')
				g()->map[y][x] = '0';
			x++;
		}
		y++;
	}
}

int	calc_map_size(int size)
{
	int	y;
	int	res;

	(void)size;
	y = 0;
	res = 0;
	while (g()->map[y])
	{
		if (strchr(g()->map[y], '1'))
			res++;
		y++;
	}
	return (res);
}

void	alloc_final_map(void)
{
	int	size;

	size = ft_2darr_len(g()->map);
	g()->parsing.final_map_size = calc_map_size(size);
	g()->final_map = (int **)calloc(g()->parsing.final_map_size, sizeof(int *));
	if (!g()->final_map)
		ft_exit_free("Calloc failed");
}

void	make_final_map(void)
{
	int	x;
	int	y;
	int	newY;

	y = -1;
	newY = 0;
	g()->parsing.final_map_longest_line = find_longest_line(g()->map);
	alloc_final_map();
	while (g()->map[++y])
	{
		if (strchr(g()->map[y], '1'))
		{
			g()->final_map[newY] = (int *)calloc(g()->parsing.final_map_longest_line,
				sizeof(int));
			if (!g()->final_map[newY])
				ft_exit_free("Calloc failed");
			x = -1;
			while (g()->map[y][++x])
			{
				if (g()->map[y][x] == '1')
					g()->final_map[newY][x] = 1;
				else
					g()->final_map[newY][x] = 0;
			}
			newY++;
		}
	}
	/* printf("--- FINAL MAP ---\n");
	for (int i = 0; i < g()->parsing.final_map_size; i++)
	{
		for (int j = 0; j < g()->parsing.final_map_longest_line; j++)
		{
			printf("%d", g()->final_map[i][j]);
		}
		printf("\n");
	} */
}

int	loc_start_map(char *trimmed, int y, int x)
{
	int	is_map_line;

	(void)y;
	is_map_line = 0;
	while (trimmed[x] != '\0' && trimmed[x] != '\n')
	{
		if (trimmed[x] != '0' && trimmed[x] != '1')
		{
			is_map_line = 1;
			break ;
		}
		x++;
	}
	return (is_map_line);
}

void	map(void)
{
	int		y;
	int		x;
	int		is_map_line;
	char	*trimmed;

	y = 0;
	x = 0;
	while (g()->file[y])
	{
		x = 0;
		is_map_line = 0;
		trimmed = ft_strtrim(g()->file[y], " ");
		if (*trimmed == '\0' || *trimmed == '\n')
		{
			y++;
			free(trimmed);
			continue ;
		}
		is_map_line = loc_start_map(trimmed, y, x);
		free(trimmed);
		if (is_map_line == 0)
			break ;
		y++;
	}
	copy_filemap_to_floodmap(y);
	validate_map();
	flood_the_map();
	copy_floodmap_to_map();
	transform_map();
	make_final_map();
}
