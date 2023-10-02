/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:23:16 by olivierbouc       #+#    #+#             */
/*   Updated: 2023/07/22 16:13:54 by olivierbouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGF_H
# define FT_STRINGF_H

# include "conversion.h"
# include "error.h"
# include "get_next_line.h"
# include "memory.h"
# include "string.h"
# include <stdarg.h>
# include <unistd.h>

// prototype

char	*ft_stringf(const char *str, ...);

#endif