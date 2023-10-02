#include "../../inc/cub3D.h"

void load_intit_texture(void)
{
    g()->texture[0] = mlx_load_png(g()->parsing->north);
    g()->texture[0] = mlx_load_png(g()->parsing->south);
    g()->texture[0] = mlx_load_png(g()->parsing->east);
    g()->texture[0] = mlx_load_png(g()->parsing->west);
}