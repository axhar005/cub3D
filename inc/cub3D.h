/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:19:28 by oboucher          #+#    #+#             */
/*   Updated: 2023/10/02 13:55:18 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

// include
#include "../libft_/inc/libft.h"
#include <stdbool.h>
#include <unistd.h>

// struct
typedef struct t_parsing
{

} s_parsing;

typedef struct t_global
{
    s_parsing *parsing;
} s_global;

// prototype

// string
size_t count_next_line(int fd);
size_t char_count(char *str, char c);

#endif