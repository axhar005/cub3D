#include "../../inc/cub3D.h"

void load_init_texture(void)
{
    g()->texture[0] = mlx_load_png("./asset/water_11.png");
    g()->texture[1] = mlx_load_png("./asset/sand_11.png");
    g()->texture[2] = mlx_load_png("./asset/stone_floor.png");
    g()->texture[3] = mlx_load_png("./asset/wood_floor.png");
}