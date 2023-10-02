/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:40:59 by oboucher          #+#    #+#             */
/*   Updated: 2023/04/27 17:34:02 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Check if it's an alphabet
/// @param c is a char
/// @return 1 = true 0 = false
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
