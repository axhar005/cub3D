/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:46:50 by oboucher          #+#    #+#             */
/*   Updated: 2023/10/11 11:46:51 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	set_background(mlx_image_t *image, uint32_t floor_color,
		uint32_t roof_color)
{
	int	x1;
	int	y1;

	y1 = 0;
	while (y1 < VIEW_HEIGHT / 2)
	{
		x1 = 0;
		while (x1 < VIEW_WIDTH)
		{
			mlx_put_pixel(image, x1, y1, floor_color);
			x1++;
		}
		y1++;
	}
	y1 = VIEW_HEIGHT / 2;
	while (y1 < VIEW_HEIGHT)
	{
		x1 = 0;
		while (x1 < VIEW_WIDTH)
		{
			mlx_put_pixel(image, x1, y1, roof_color);
			x1++;
		}
		y1++;
	}
}
