/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:47:42 by oboucher          #+#    #+#             */
/*   Updated: 2023/10/11 11:47:44 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	ft_free_texture(t_global *gl)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (gl->texture[i])
			mlx_delete_texture(gl->texture[i]);
		i++;
	}
	if (gl->image)
		mlx_delete_image(gl->mlx, gl->image);
	if (gl->background)
		mlx_delete_image(gl->mlx, gl->background);
}

void	ft_2dint_free(int **tab)
{
	int	i;
	int	size;

	i = 0;
	if (!tab)
		return ;
	size = g()->parsing.final_map_size;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_2darr_free(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_all(void)
{
	if (g()->flood_map)
		ft_2darr_free(g()->flood_map);
	if (g()->file)
		ft_2darr_free(g()->file);
	if (g()->map)
		ft_2darr_free(g()->map);
	if (g()->final_map)
		ft_2dint_free(g()->final_map);
	if (g()->parsing.east)
		free(g()->parsing.east);
	if (g()->parsing.north)
		free(g()->parsing.north);
	if (g()->parsing.west)
		free(g()->parsing.west);
	if (g()->parsing.south)
		free(g()->parsing.south);
	ft_free_texture(g());
}

void	ft_exit_free(char *s, int fd)
{
	free_all();
	if (s)
		ft_putstr_fd(s, fd);
	exit(EXIT_FAILURE);
}
