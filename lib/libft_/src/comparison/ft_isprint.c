/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:13:07 by oboucher          #+#    #+#             */
/*   Updated: 2023/04/27 17:35:47 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Check if it's a printable char
/// @param c is a char
/// @return 1 = true 0 = false
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
