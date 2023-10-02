/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:54:32 by oboucher          #+#    #+#             */
/*   Updated: 2023/04/27 18:10:02 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/write_fd.h"

/// @brief write a char on a fd
/// @param c is the char
/// @param fd is the file descriptor
/// @return the write length
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
