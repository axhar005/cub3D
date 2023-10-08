/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:55:48 by acouture          #+#    #+#             */
/*   Updated: 2023/10/08 19:28:24 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

size_t	count_next_line(int fd)
{
	char	*buffer;
	size_t	count;

	count = 0;
	if (BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	buffer = ft_gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (-1);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		count += char_count(buffer, '\n');
		ft_gnl_bzero(buffer, BUFFER_SIZE);
	}
	if (buffer)
		count++;
	buffer = ft_sfree(buffer);
	return (count);
}

int	open_file(char *file)
{
	int			fd;
	int			count;
	t_global	*gl;

	gl = g();
	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit("Error loading map");
	count = count_next_line(fd);
	gl->file = ft_calloc((count + 1), sizeof(char *));
	if (!gl->file)
		ft_exit("Malloc failed");
	close(fd);
	return (count);
}

void	store_file(char *file)
{
	int	i;
	int	fd;
	int	count;

	i = 0;
	count = open_file(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit_free("FD failed", 2);
	while (count)
	{
		g()->file[i] = get_next_line(fd);
		i++;
		count--;
	}
	if (i == 1)
		ft_exit_free("Empty map\n", 2);
	close(fd);
}

void	check_extension(char *map)
{
	int	i;

	i = ft_strlen(map) - 4;
	if (ft_strncmp(&map[i], ".cub", 4) != 0)
		ft_exit("Wrong type of file");
}

void	pars_file(char *file)
{
	store_file(file);
	find_nswe();
	find_colors();
	if (g()->parsing.valid_map != 6)
		ft_exit_free("Elements are not valid and/or missing\n", 2);
	map();
	return ;
}
