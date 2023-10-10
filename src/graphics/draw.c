#include "../../inc/cub3D.h"

void	draw_pixel_square(t_pos pos, t_pos size, uint32_t color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			mlx_put_pixel(g()->image, pos.x + x, pos.y + y, color);
			x++;
		}
		y++;
	}
}

void	logical_minimap(t_minimap *map, int x, int y)
{
	int	cam_x;
	int	cam_y;

	cam_x = (int)g()->player.pos_y - map->width / 2;
	cam_y = (int)g()->player.pos_x - map->height / 2;
	if (((y + cam_y >= 0) && (y + cam_y < g()->parsing.final_map_size)) && ((x
				+ cam_x >= 0) && (x
				+ cam_x < g()->parsing.final_map_longest_line)))
	{
		if (x + cam_x == (int)g()->player.pos_y && y
			+ cam_y == (int)g()->player.pos_x)
			draw_pixel_square((t_pos){(x * map->slot_size) + map->pos_x, (y
					* map->slot_size) + map->pos_y}, (t_pos){map->slot_size,
				map->slot_size}, map->player_color);
		else if (g()->final_map[y + cam_y][x + cam_x] == 1)
			draw_pixel_square((t_pos){(x * map->slot_size) + map->pos_x, (y
					* map->slot_size) + map->pos_y}, (t_pos){map->slot_size,
				map->slot_size}, map->wall_color);
		else if (g()->final_map[y + cam_y][x + cam_x] == 0)
			draw_pixel_square((t_pos){(x * map->slot_size) + map->pos_x, (y
					* map->slot_size) + map->pos_y}, (t_pos){map->slot_size,
				map->slot_size}, map->floor_color);
	}
}

/// @brief draw a minimap
/// @param square_size nb pixel by square
/// @param map_width nb square
/// @param map_height
void	draw_minimap(t_minimap *map)
{
	int	x;
	int	y;
	int	cam_x;
	int	cam_y;

	draw_pixel_square((t_pos){map->pos_x - 5, map->pos_y - 5},
		(t_pos){map->slot_size * map->width + 10, map->slot_size
		* map->height + 10},
		map->background_color);
	cam_x = (int)g()->player.pos_y - map->width / 2;
	cam_y = (int)g()->player.pos_x - map->height / 2;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			logical_minimap(map, x, y);
			x++;
		}
		y++;
	}
}
