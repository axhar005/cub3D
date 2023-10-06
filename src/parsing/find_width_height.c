/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_width_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:52:59 by acouture          #+#    #+#             */
/*   Updated: 2023/10/06 14:55:40 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	find_first_non_space(char *row)
{
	int	i;

	i = 0;
	while (row[i] == ' ')
		i++;
	return (i);
}

int	find_last_non_space(char *row)
{
	int	i;

	i = (int)ft_strlen(row) - 1;
	while (i >= 0 && row[i] == ' ')
		i--;
	return (i);
}

bool	row_contains_non_space(char *row)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(row))
	{
		if (row[i] != ' ')
			return (true);
		i++;
	}
	return (false);
}

int	find_effective_width(char **map)
{
	int	i;
	int	max_effective_width;
	int	first_non_space;
	int	last_non_space;
	int	effective_width;

	i = 0;
	max_effective_width = 0;
	while (map[i])
	{
		first_non_space = find_first_non_space(map[i]);
		last_non_space = find_last_non_space(map[i]);
		effective_width = last_non_space - first_non_space + 1;
		if (effective_width > max_effective_width)
			max_effective_width = effective_width;
		i++;
	}
	return (max_effective_width);
}

int	find_effective_height(char **map)
{
	int	i;
	int	effective_height;

	i = 0;
	effective_height = 0;
	while (map[i])
	{
		if (row_contains_non_space(map[i]))
			effective_height++;
		i++;
	}
	return (effective_height);
}
