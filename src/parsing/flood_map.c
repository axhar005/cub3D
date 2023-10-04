#include "../inc/cub3D.h"

void flood_fill(int y, int x, int map_width, int map_height)
{
	t_global *data;

	data = g();
	if (y < 0 || y >= map_height || x < 0 || x >= (int)ft_strlen(data->flood_map[y]))
		ft_exit_free("Out of bounds\n");
	if (data->flood_map[y][x] == 'X' || data->flood_map[y][x] == '1')
		return;
	data->flood_map[y][x] = 'X';
	flood_fill(y - 1, x, map_width, map_height);
	flood_fill(y + 1, x, map_width, map_height);
	flood_fill(y, x + 1, map_width, map_height);
	flood_fill(y, x - 1, map_width, map_height);
}

void copy_filemap_to_floodmap(int index)
{
	int i;
	int j;

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

void copy_floodmap_to_map(void)
{
	int i;
	int size;
	int j;

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
	for (int i = 0; g()->map[i]; i++)
	{
		for (int j = 0; g()->map[i][j]; j++)
		{
			printf("%c", g()->map[i][j]);
		}
	}
	printf("\n"); */
}

void flood_the_map()
{
	int map_width = find_longest_line(g()->flood_map);
	int map_height = ft_2darr_len(g()->flood_map);

	if (map_width > 60 || map_height > 60)
	{
		ft_exit_free("MAP OVERFLOW\n");
	}
	flood_fill(g()->parsing.player_pos.y, g()->parsing.player_pos.x, map_width, map_height);
}