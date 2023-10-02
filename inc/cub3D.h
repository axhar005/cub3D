

#ifndef CUB3D_H
# define CUB3D_H

// include
# include "../lib/MLX42_/include/MLX42/MLX42.h"
# include "../lib/libft_/inc/libft.h"
# include <stdbool.h>
# include <unistd.h>

#define VIEW_HEIGHT 720
#define VIEW_WIDTH 1280

// struct
typedef struct s_position
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_parsing
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	t_pos			*player_pos;

}					t_parsing;

typedef struct s_global
{
	mlx_t			*mlx;
	mlx_texture_t	*texture[4];
	mlx_image_t		*image;
	t_parsing		*parsing;
}					t_global;

// prototype

//----------------------//
// --------UTILS--------//
//----------------------//
t_global			*g(void);
size_t				count_next_line(int fd);
size_t				char_count(char *str, char c);
//----------------------//
// -------PARSING-------//
//----------------------//

//----------------------//
// -------GRAPHICS------//
//----------------------//

#endif