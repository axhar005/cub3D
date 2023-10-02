

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
    t_parsing parsing;
} t_global;

// prototype

//----------------------//
// --------UTILS--------//
//----------------------//
// string
size_t count_next_line(int fd);
size_t char_count(char *str, char c);
//----------------------//
// ------PARSING--------//
//----------------------//
void    pars_map(char *map);

//----------------------//
// -------GRAPHICS------//
//----------------------//

#endif