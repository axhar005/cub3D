/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nswe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:52:55 by acouture          #+#    #+#             */
/*   Updated: 2023/10/08 17:34:00 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (0);
}

char	*extract_path(char *string)
{
	int		i;
	int		len;
	char	*path;

	i = 2;
	len = 0;
	while (ft_isspace(string[i]))
		i++;
	while (string[i + len] && !ft_isspace(string[i + len]))
		len++;
	path = (char *)malloc(len + 1);
	if (!path)
		return (NULL);
	ft_strlcpy(path, &string[i], len + 1);
	path[len] = '\0';
	g()->parsing.valid_map++;
	return (path);
}

void	find_nswe(void)
{
	int		i;
	char	*trimmed_str;

	i = 0;
	while (g()->file[i])
	{
		trimmed_str = ft_strtrim(g()->file[i], " ");
		if (ft_strncmp(trimmed_str, "NO", 2) == 0 && (trimmed_str[2] == ' '))
			g()->parsing.north = extract_path(trimmed_str);
		else if (ft_strncmp(trimmed_str, "SO", 2) == 0
			&& (trimmed_str[2] == ' '))
			g()->parsing.south = extract_path(trimmed_str);
		else if (ft_strncmp(trimmed_str, "WE", 2) == 0
			&& (trimmed_str[2] == ' '))
			g()->parsing.west = extract_path(trimmed_str);
		else if (ft_strncmp(trimmed_str, "EA", 2) == 0
			&& (trimmed_str[2] == ' '))
			g()->parsing.east = extract_path(trimmed_str);
		free(trimmed_str);
		i++;
	}
}
