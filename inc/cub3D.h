

#ifndef CUB3D_H
#define CUB3D_H

// include
#include "../lib/libft_/inc/libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// struct
typedef struct s_position
{
	int x;
	int y;
} t_pos;

typedef struct s_parsing
{
	char *north;
	char *south;
	char *east;
	char *west;
	unsigned long color_f;
	unsigned long color_c;
	char player_dir;
	t_pos player_pos;
	int valid_map;
} t_parsing;

typedef struct s_global
{
	char **file;
	char **map;
	int **final_map;
	char **flood_map;
	bool reached;
	t_parsing parsing;
} t_global;

// prototype

//----------------------//
// --------UTILS--------//
//----------------------//
int find_longest_line(char **array);
void ft_exit_free(char *s);
void free_all(void);
void ft_2darr_print(char **tb, int fd);
void ft_2darr_free(char **tb);
size_t ft_2darr_len(char **arr);
t_global *g(void);
// map
void validate_map(void);
void transform_map(void);
int calc_map_size(int size);
void make_final_map(void);
int loc_start_map(int y, int x);
void map(void);
// flood map
void flood_fill(int y, int x, int map_width, int map_height);
void copy_filemap_to_floodmap(int index);
void copy_floodmap_to_map(void);
void flood_the_map();
// string
size_t count_next_line(int fd);
size_t char_count(char *str, char c);
//----------------------//
// -------PARSING-------//
//----------------------//
void pars_map(char *map);
void check_extension(char *map);
void find_nswe(void);
void find_colors(void);
char *extract_path(char *string);
void map(void);
//----------------------//
// -------GRAPHICS------//
//----------------------//

#endif