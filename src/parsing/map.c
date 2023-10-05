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
				g()->parsing.player_dir = c;
				g()->parsing.player_pos.x = x;
				g()->parsing.player_pos.y = y;
			}
			else if (c != '1' && c != '0' && c != '\n' && c != '\0'
				&& !ft_isspace(c))
			{
				printf("ERROR = %c\n", g()->flood_map[y][x]);
				ft_exit_free("Parsing map error = \n");
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
	int	new_size;

	size = ft_2darr_len(g()->map);
	new_size = calc_map_size(size);
	g()->final_map = (int **)calloc(new_size, sizeof(int *));
	if (!g()->final_map)
		ft_exit_free("Calloc failed");
}

void	make_final_map(void)
{
	int	line;
	int	x;
	int	y;
	int	newY;
	int	size;
	int	new_size;

	y = 0;
	newY = 0;
	size = ft_2darr_len(g()->map);
	new_size = calc_map_size(size);
	y = 0;
	newY = 0;
	line = find_longest_line(g()->map);
	alloc_final_map();
	while (g()->map[y])
	{
		if (strchr(g()->map[y], '1'))
		{
			g()->final_map[newY] = (int *)calloc(line, sizeof(int));
			if (!g()->final_map[newY])
				ft_exit_free("Calloc failed");
			x = -1;
			while (g()->map[y][++x])
				g()->final_map[newY][x] = (g()->map[y][x] == '1') ? 1 : 0;
			newY++;
		}
		y++;
	}
}

int	loc_start_map(char *trimmed, int y, int x)
{
	(void)y;
	int	is_map_line;

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
