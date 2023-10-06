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
	t_global *gl;

	gl = g();
	g()->texture[0] = mlx_load_png(gl->parsing.north);
	g()->texture[1] = mlx_load_png(gl->parsing.south);
	g()->texture[2] = mlx_load_png(gl->parsing.west);
	g()->texture[3] = mlx_load_png(gl->parsing.east);
	valid_texture();
}
