#include "../inc/cub3D.h"

void flood_fill(int y, int x)
{
    t_global *data;
    int map_width = find_longest_line(g()->flood_map);
    int map_height = ft_2darr_len(g()->flood_map);

    data = g();
    if (x < 0 || y < 0 || x >= map_width || y >= map_height)
        ft_exit_free("Out of bounds\n");
    if (data->flood_map[y][x] == 'X' || data->flood_map[y][x] == '1')
        return;
    data->flood_map[y][x] = 'X';
    flood_fill(y - 1, x);
    flood_fill(y + 1, x);
    flood_fill(y, x + 1);
    flood_fill(y, x - 1);
}


void	copy_filemap_to_floodmap(int index)
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
	/* for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < line; j++)
		{
			printf("%d", g()->final_map[i][j]);
		}
		printf("\n");
	} */
}

int	loc_start_map(int y, int x)
{
	int	is_map_line;

	is_map_line = 0;
	while (g()->file[y][x] != '\n')
	{
		if (g()->file[y][x] != '0' && g()->file[y][x] != '1')
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
		is_map_line = loc_start_map(y, x);
		if (is_map_line == 0)
			break ;
		y++;
	}
	copy_filemap_to_floodmap(y);
	validate_map();
	flood_fill(g()->parsing.player_pos.y, g()->parsing.player_pos.x);
	printf("--- FLOOD MAP ---\n");
	for (int i = 0; g()->flood_map[i]; i++)
	{
		for (int j = 0; g()->flood_map[i][j]; j++)
		{
			printf("%c", g()->flood_map[i][j]);
		}
		/* printf("\n"); */
	}
	copy_floodmap_to_map();
	transform_map();
	make_final_map();
	/* printf("--- AFTER MAP ---\n");
	ft_2darr_print(g()->map, 0); */
}
