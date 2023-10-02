/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:06:03 by oboucher          #+#    #+#             */
/*   Updated: 2023/04/27 18:14:03 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "write_fd.h"

//prototype

int	ft_putnbr_base(unsigned int nbr, char c);
int	ft_printf(const char *str, ...);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putpointer(unsigned long long n);

#endif