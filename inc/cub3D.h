

#ifndef CUB3D_H
# define CUB3D_H

// include
# include "../lib/MLX42_/include/MLX42/MLX42.h"
# include "../lib/libft_/inc/libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# define VIEW_HEIGHT 1080
# define VIEW_WIDTH 1920
# define MIN_SPEED 0.03
# define MAX_SPEED 0.08
# define MIN_ROT_SPEED 2
# define MAX_ROT_SPEED 3
# define HITBOX 0.4

// struct

typedef struct s_raycast
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;

	double			perpWallDist;
	double			wallX;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	int				texNum;
	int				tex_x;
	int				tex_y;

	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	uint32_t		color;
	uint32_t		new_color;
}					t_raycast;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
}					t_player;

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
	int				map[10][10];
	t_player		player;
	double			delta_time;
	t_parsing		*parsing;
	t_raycast		raycast;
}					t_global;

// prototype

//----------------------//
// --------UTILS--------//
//----------------------//
t_global			*g(void);
size_t				count_next_line(int fd);
// size_t				char_count(char *str, char c);
//----------------------//
// -------PARSING-------//
//----------------------//

//----------------------//
// -------GRAPHICS------//
//----------------------//
void				player_movement(void);
void				player_rotation(void);
void				load_init_texture(void);
void				raycast(t_player player, mlx_image_t *image);
void				change_player_dir(t_player *player, char c);
void				set_background(mlx_image_t *image, uint32_t roof_color,
						uint32_t floor_color);
void				rotate_view(double theta);
void				cal_side_dist_x(t_player *player);
void				cal_side_dist_y(t_player *player);
void				dda(void);
void				wall_height(t_player *player);
void				calum_dist(void);

#endif