#include "../inc/cub3D.h"

void	flood_fill(int y, int x)
{
	t_global	*data;

	data = g();
	if (x < 0 && y < 0)
		return ;
	if (data->flood_map[y][x] == '\n' || data->flood_map[y][x] == ' ')
		ft_exit_free("Out of bounds\n");
	else if (data->flood_map[y][x] == 'X' || data->flood_map[y][x] == '1')
		return ;
	data->flood_map[y][x] = 'X';
	flood_fill(y - 1, x);
	flood_fill(y + 1, x);
	flood_fill(y, x + 1);
	flood_fill(y, x - 1);
}

void	copy_filemap_to_map(int index)
{
	int	i;
	int	j;

	i = index;
	j = 0;
	while (g()->file[index])
		index++;
	g()->flood_map = malloc(sizeof(char *) * (index + 1));
	if (!g()->flood_map)
		ft_exit_free("Malloc failed\n");
	while (g()->file[i])
	{
		g()->flood_map[j++] = ft_strdup(g()->file[i++]);
	}
	g()->flood_map[j] = NULL;
	/* printf("--- FLOOD MAP ---\n");
	ft_2darr_print(g()->flood_map, 0); */
}

void	copy_floodmap_to_map(void)
{
	int	i;
	int	size;
	int	j;

	i = 0;
	j = 0;
	size = 0;
	while (g()->flood_map[size])
		size++;
	g()->map = malloc(sizeof(char *) * (size + 1));
	if (!g()->map)
		ft_exit_free("Malloc failed\n");
	while (g()->flood_map[i])
	{
		g()->map[j++] = ft_strdup(g()->flood_map[i++]);
	}
	g()->map[j] = NULL;
	/* printf("--- MAP ---\n");
	ft_2darr_print(g()->map, 0); */
}

void	validate_map(void)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	while (g()->flood_map[y])
	{
		x = 0;
		while (g()->flood_map[y][x])
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
			x++;
		}
		y++;
	}
}

int	loc_start_map(char c, int x)
{
	int	is_map_line;

	is_map_line = 0;
	while (c != '\n')
	{
		if (c != '0' && c != '1')
		{
			is_map_line = 1;
			break ;
		}
		x++;
	}
	return (is_map_line);
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

void	make_final_map(void)
{
	int	line;
	int	size;
	int	x;
	int	y;

	y = 0;
	line = find_longest_line(g()->map);
	size = ft_2darr_len(g()->map);
	g()->final_map = ft_calloc(size, sizeof(int));
	if (!g()->final_map)
		ft_exit_free("Calloc failed");
	while (g()->map[y])
	{
		x = 0;
		g()->final_map[y] = (int *)ft_calloc(line, sizeof(int));
		if (!g()->final_map[y])
			ft_exit_free("Calloc failed");
		while (g()->map[y][x])
		{
			if (g()->map[y][x] != '1')
				g()->final_map[y][x] = 0;
			else
				g()->final_map[y][x] = 1;
			x++;
		}
		y++;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < line; j++) {
			printf("%d", g()->final_map[i][j]);
		}
		printf("\n");
	}
}

void	map(void)
{
	int	y;
	int	x;
	int	is_map_line;

	y = 0;
	x = 0;
	while (g()->file[y])
	{
		x = 0;
		is_map_line = 0;
		if (g()->file[y][0] == '\0' || g()->file[y][0] == '\n')
			y++;
		is_map_line = loc_start_map(g()->file[y][x], x);
		if (is_map_line == 0)
			break ;
		y++;
	}
	copy_filemap_to_map(y);
	validate_map();
	flood_fill(g()->parsing.player_pos.y, g()->parsing.player_pos.x);
	copy_floodmap_to_map();
	transform_map();
	make_final_map();
	printf("--- AFTER MAP ---\n");
	ft_2darr_print(g()->map, 0);
}
