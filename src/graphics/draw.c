/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:46:03 by oboucher          #+#    #+#             */
/*   Updated: 2023/10/11 11:46:05 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	draw_thick_line(t_pos start, t_pos end, uint32_t color)
{
	int	offset;
	int	x;
	int	y;

	offset = CROSSHAIR_THICK / 2;
	if (start.x == end.x)
	{
		y = start.y;
		while (y <= end.y)
		{
			x = start.x - offset;
			while (x <= start.x + offset)
				mlx_put_pixel(g()->image, x++, y++, color);
		}
	}
	else if (start.y == end.y)
	{
		x = start.x;
		while (x <= end.x)
		{
			y = start.y - offset;
			while (y <= start.y + offset)
				mlx_put_pixel(g()->image, x++, y++, color);
		}
	}
}

void	draw_cross(int x_center, int y_center, uint32_t color)
{
	int	half;

	half = CROSSHAIR_LEN / 2;
	draw_thick_line((t_pos){x_center, y_center - half}, (t_pos){x_center,
		y_center + half}, color);
	draw_thick_line((t_pos){x_center - half, y_center}, (t_pos){x_center + half,
		y_center}, color);
}

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
