/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:34:18 by oboucher          #+#    #+#             */
/*   Updated: 2023/05/03 15:26:09 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Check if c it's a space
/// @param c is a char
/// @return 1 = true 0 = false
int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\f' || c == '\r'
		|| c == '\v' || c == ' ')
		return (1);
	return (0);
}
