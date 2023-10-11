/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:09:58 by oboucher          #+#    #+#             */
/*   Updated: 2023/10/11 12:10:00 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static bool	new_pressed(keys_t key, keys_t *array, int32_t i)
{
	while (i < 10)
	{
		if (array[i] == key)
			return (false);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (array[i] == 0)
		{
			array[i] = key;
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	alrady_pressed(keys_t key, keys_t *array, int32_t i)
{
	while (i < 10)
	{
		if (array[i] == key)
		{
			array[i] = 0;
			return (false);
		}
		i++;
	}
	return (false);
}

bool	is_key_pressed(keys_t key)
{
	static keys_t	array[10];
	int32_t			i;

	i = 0;
	if (mlx_is_key_down(g()->mlx, key))
	{
		return (new_pressed(key, array, i));
	}
	else
	{
		return (alrady_pressed(key, array, i));
	}
	return (false);
}
