/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:28:03 by oboucher          #+#    #+#             */
/*   Updated: 2023/10/03 12:22:02 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

// size_t	line_count(char **str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// void	print_2d_char_array(char **array)
// {
// 	int	x;

// 	x = 0;
// 	while (array[x])
// 		ft_printf("%s\n", array[x++]);
// 	ft_printf("\n");
// }

// size_t	total_count(char **str)
// {
// 	size_t	i;
// 	size_t	count;

// 	i = 0;
// 	count = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 	{
// 		count += ft_strlen(str[i]);
// 		i++;
// 	}
// 	return (count);
// }

// char	*ft_del_char(char *str, char c)
// {
// 	char	*new;
// 	size_t	charnum;
// 	size_t	i;
// 	size_t	j;

// 	charnum = char_count(str, c);
// 	i = 0;
// 	j = 0;
// 	if (!str || charnum <= 0)
// 		return (str);
// 	new = ft_calloc(ft_strlen(str) - charnum + 1, sizeof(char));
// 	if (!new)
// 		return (str);
// 	while (str[i])
// 	{
// 		if (str[i] != c)
// 		{
// 			new[j] = str[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (ft_sfree(str), new);
// }

// size_t	char_count_2d(char **str, char c)
// {
// 	size_t	x;
// 	size_t	y;
// 	size_t	count;

// 	x = 0;
// 	count = 0;
// 	if (!str)
// 		return (0);
// 	while (str[x])
// 	{
// 		y = 0;
// 		while (str[x][y])
// 		{
// 			if (str[x][y] == c)
// 				count++;
// 			y++;
// 		}
// 		x++;
// 	}
// 	return (count);
// }

size_t	char_count(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
