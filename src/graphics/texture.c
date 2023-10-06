#include "../../inc/cub3D.h"

void	valid_texture(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!g()->texture[i])
			ft_exit("texture not found ! (ft_exit_free needed)");
		i++;
	}
}

void	load_init_texture(void)
{
	g()->texture[0] = mlx_load_png("./asset/stone.png");
	g()->texture[1] = mlx_load_png("./asset/wall.png");
	g()->texture[2] = mlx_load_png("./asset/stone.png");
	g()->texture[3] = mlx_load_png("./asset/wall.png");
	valid_texture();
}
