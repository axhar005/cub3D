/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:24:14 by oboucher          #+#    #+#             */
/*   Updated: 2023/05/03 14:01:35 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

//prototype

int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
long int	ft_atoli(const char *str);

#endif