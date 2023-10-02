/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:06:59 by oboucher          #+#    #+#             */
/*   Updated: 2023/04/27 17:33:48 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Check if it's a ascii char
/// @param c is a char
/// @return 1 = true 0 = false
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
