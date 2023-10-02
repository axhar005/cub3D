#include "../inc/cub3D.h"

void	flood_fill(int y, int x)
{
	t_global	*data;

	data = g();
	if (x < 0 && y < 0)
		return ;
	if (data->flood_map[y][x] == 'X' || data->flood_map[y][x] == '1')
		return ;
	data->flood_map[y][x] = 'X';
	flood_fill(y - 1, x);
	flood_fill(y + 1, x);
	flood_fill(y, x + 1);
	flood_fill(y, x - 1);
}

void	validate_map(void)
{
	int		y;
	int		x;
	char	c;
	int		is_map_line;

	y = 0;
	x = 0;
	while (g()->file[y])
	{
		x = 0;
		is_map_line = 1;
		if (g()->file[y][0] == '\0' || g()->file[y][0] == '\n')
		{
			y++;
			break ;
		}
		while (g()->file[y][x] != '\n')
		{
			c = g()->file[y][x];
			if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E'
				&& c != 'W')
			{
				is_map_line = 0;
				break ;
			}
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				g()->parsing.player_pos->x = x;
				g()->parsing.player_pos->y = y;
			}
			x++;
		}
		if (is_map_line)
		{
			printf("X %d Y %d\n", x, y);
			printf("FLLOD FILL\n");
			break ;
		}
		y++;
	}
}
