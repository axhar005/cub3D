/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:32:21 by oboucher          #+#    #+#             */
/*   Updated: 2023/04/27 13:59:09 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	ft_numlen(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	len;

	len = ft_numlen(n);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, 1);
		ft_putchar_fd(n % 10 + '0', 1);
	}
	else
		ft_putchar_fd(n + '0', 1);
	return (len);
}
