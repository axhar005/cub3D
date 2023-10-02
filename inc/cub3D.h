/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:19:28 by oboucher          #+#    #+#             */
/*   Updated: 2023/10/02 14:21:16 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

// include
#include "../libft_/inc/libft.h"
#include <stdbool.h>
#include <unistd.h>

// struct
typedef struct s_position
{
    int x;
    int y;
}   t_pos;

typedef struct s_parsing
{
    char *north;
    char *south;
    char *east;
    char *west;
    t_pos *player_pos;
    
} t_parsing;


typedef struct s_global
{
    s_parsing *parsing;
} t_global;

// prototype

// string
size_t count_next_line(int fd);
size_t char_count(char *str, char c);

#endif