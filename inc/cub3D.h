

#ifndef CUB3D_H
# define CUB3D_H

// include
# include "../lib/libft_/inc/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

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
	unsigned long	color_f;
	unsigned long	color_c;
	char			player_dir;
	t_pos			player_pos;
	int				valid_map;
	int				final_map_size;
	int				final_map_longest_line;
}					t_parsing;

typedef struct s_global
{
	char			**file;
	char			**map;
	int				**final_map;
	char			**flood_map;
	bool			reached;
	t_parsing		parsing;
}					t_global;

// prototype

//----------------------//
// --------UTILS--------//
//----------------------//
int					find_longest_line(char **array);
void				ft_exit_free(char *s);
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

// flood map
void				flood_fill(int y, int x, int map_width, int map_height);
void				copy_filemap_to_floodmap(int index);
void				copy_floodmap_to_map(void);
void				flood_the_map(void);
// open read
void				pars_map(char *map);
void				check_extension(char *map);
void				store_file(char *file);
int					open_file(char *file);
//----------------------//
// -------GRAPHICS------//
//----------------------//

#endif