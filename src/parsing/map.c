#include "../../inc/cub3D.h"

void	validate_map(void)
{
	int	x;
	int	y;
	int	c;

	y = -1;
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
				ft_exit_free("Parsing map error\n");
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

void	exec_map(int y)
{
	copy_filemap_to_floodmap(y);
	validate_map();
	if (!g()->parsing.player_dir)
		ft_exit_free("No player detected\n");
	flood_the_map();
	copy_floodmap_to_map();
	transform_map();
	make_final_map();
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
	exec_map(y);
}
