#ifndef CUB3D_H
# define CUB3D_H

// include
# include "../lib/MLX42_/include/MLX42/MLX42.h"
# include "../lib/libft_/inc/libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

//720 x 1280
# define VIEW_HEIGHT 1080
# define VIEW_WIDTH 1920
# define MIN_SPEED 0.03
# define MAX_SPEED 0.08
# define MIN_ROT_SPEED 2
# define MAX_ROT_SPEED 3
# define SENSIBILITY 0.08
# define HITBOX 0.35
# define FPS 60

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
	double			perp_wall;
	double			wall_x;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_num;
	int				tex_x;
	int				tex_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	uint8_t			*color;
	uint32_t		new_color;
}					t_raycast;

typedef struct s_minimap
{
	int				pos_x;
	int				pos_y;
	int				width;
	int				height;
	int				slot_size;
	uint32_t		wall_color;
	uint32_t		floor_color;
	uint32_t		player_color;
	uint32_t		background_color;
}					t_minimap;

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
	unsigned long	color_f;
	unsigned long	color_c;
	char			player_dir;
	t_pos			player_pos;
	int				valid_map;
	int				final_map_size;
	int				final_map_longest_line;
	char			*error_flag;
}					t_parsing;

typedef struct s_global
{
	char			**file;
	char			**map;
	int				**final_map;
	char			**flood_map;
	bool			reached;
	bool			focus;
	t_parsing		parsing;
	mlx_t			*mlx;
	mlx_texture_t	*texture[4];
	mlx_image_t		*image;
	mlx_image_t		*background;
	t_player		player;
	double			delta_time;
	t_raycast		raycast;
	t_minimap		minimap;
}					t_global;

// prototype

//----------------------//
// --------UTILS--------//
//----------------------//
int					find_longest_line(char **array);
void				ft_exit_free(char *s, int fd);
void				free_all(void);
void				ft_2darr_print(char **tb, int fd);
void				ft_2darr_free(char **tb);
size_t				ft_2darr_len(char **arr);
t_global			*g(void);
// string
size_t				count_next_line(int fd);
size_t				char_count(char *str, char c);
//----------------------//
// -------PARSING-------//
//----------------------//
// find colors
void				find_colors(void);
uint32_t			rgba_to_store(char *color_string);
uint32_t			create_rgba(int r, int g, int b, int a);
int					check_number(char *s);
// find nswe
void				find_nswe(void);
int					check_path(char *path);
char				*extract_path(char *string);
// map
void				validate_map(void);
void				transform_map(void);
int					loc_start_map(char *trimmed, int y, int x);
void				map(void);
void				exec_map(int y);
// final_map
int					calc_map_size(int size);
void				make_final_map(void);
void				calloc_final_map_line(int new_y);
void				alloc_final_map(void);
// find width height
int					find_first_non_space(char *row);
int					find_last_non_space(char *row);
bool				row_contains_non_space(char *row);
int					find_effective_width(char **map);
int					find_effective_height(char **map);
// flood map
void				flood_fill(int y, int x, int map_width, int map_height);
void				copy_filemap_to_floodmap(int index);
void				copy_floodmap_to_map(void);
void				flood_the_map(void);
// open read
void				pars_file(char *map);
void				check_extension(char *map);
void				store_file(char *file);
int					open_file(char *file);
//----------------------//
// -------GRAPHICS------//
//----------------------//
void				player_movement(void);
void				player_rotation(void);
void				load_init_texture(void);
void				raycast(t_player player, mlx_image_t *image);
void				change_player_dir(char c);
void				set_background(mlx_image_t *image, uint32_t floor_color,
						uint32_t roof_color);
void				rotate_view(double theta);
void				cal_side_dist_x(t_player *player, t_raycast *raycast);
void				cal_side_dist_y(t_player *player, t_raycast *raycast);
void				dda(t_global *gl, t_raycast *raycast);
void				wall_height(t_player *player, t_raycast *raycast);
void				calum_dist(t_raycast *raycast);
void				mouse_view_rotation(double xpos, double ypos, void *param);
void				draw_minimap(t_minimap *minimap);
uint32_t			rgba_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void				draw_pixel_square(t_pos pos, t_pos size, uint32_t color);

#endif