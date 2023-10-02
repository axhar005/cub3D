/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:22:48 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/22 16:26:01 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_stringf.h"

char	*sort_c(int val, char *str, size_t i)
{
	char	*new;

	if (!str)
		return (NULL);
	new = ft_gnl_calloc(ft_strlen(str), sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, str, i);
	new[i] = val;
	if (ft_strlen(&str[i + 2]) > 0)
		ft_memcpy(&new[i + 1], &str[i + 2], ft_strlen(&str[i + 2]));
	return (new);
}

char	*sort_s(char *val, char *str, size_t i)
{
	char	*new;

	if (!str)
		return (NULL);
	new = ft_gnl_calloc(i + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, str, i);
	new = ft_gnl_strjoin(new, val);
	if (ft_strlen(&str[i + 2]) > 0)
	{
		new = ft_gnl_strjoin(new, &str[i + 2]);
	}
	return (new);
}

char	*sort_d(int val, char *str, size_t i)
{
	char	*new;
	char	*num;

	num = ft_itoa(val);
	if (!str || !num)
		return (NULL);
	new = ft_gnl_calloc(i + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, str, i);
	new = ft_gnl_strjoin(new, num);
	if (ft_strlen(&str[i + 2]) > 0)
	{
		new = ft_gnl_strjoin(new, &str[i + 2]);
	}
	ft_sfree(num);
	return (new);
}

char	*sort(va_list arg, char *str, char c, size_t i)
{
	if (c == 'c')
		return (sort_c(va_arg(arg, int), str, i));
	else if (c == 's')
		return (sort_s(va_arg(arg, char *), str, i));
	else if (c == 'd')
		return (sort_d(va_arg(arg, int), str, i));
	return (str);
}

char	*ft_stringf(const char *str, ...)
{
	size_t	i;
	va_list	arg;
	char	*new;
	char	*temp;

	i = 0;
	if (!str)
		return (NULL);
	new = ft_strdup(str);
	if (!new)
		return (NULL);
	va_start(arg, str);
	while (new[i])
	{
		if (new[i] == '%')
		{
			temp = new;
			new = sort(arg, new, new[i + 1], i);
			ft_sfree(temp);
		}
		i++;
	}
	va_end(arg);
	return (new);
}
