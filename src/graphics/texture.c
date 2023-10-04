#include "../../inc/cub3D.h"

void load_init_texture(void)
{
    g()->texture[0] = mlx_load_png("./asset/stone.png");
    g()->texture[1] = mlx_load_png("./asset/wall.png");
    g()->texture[2] = mlx_load_png("./asset/stone.png");
    g()->texture[3] = mlx_load_png("./asset/wall.png");
}