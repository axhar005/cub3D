/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:47:28 by oboucher          #+#    #+#             */
/*   Updated: 2023/10/11 11:47:30 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	valid_texture(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!g()->texture[i])
			ft_exit_free("texture not found !", 2);
		i++;
	}
}

void	load_init_texture(void)
{
	t_global	*gl;

	gl = g();
	g()->texture[0] = mlx_load_png(gl->parsing.north);
	g()->texture[1] = mlx_load_png(gl->parsing.south);
	g()->texture[2] = mlx_load_png(gl->parsing.west);
	g()->texture[3] = mlx_load_png(gl->parsing.east);
	valid_texture();
}
