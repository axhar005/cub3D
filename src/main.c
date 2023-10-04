
#include "inc/cub3D.h"

t_global	*g(void)
{
	static t_global	global;

	return (&global);
}

void	step(void *param)
{
	(void)param;
	set_background(g()->image, 0x699FF5FF, 0x662D01FF);

    raycast(g()->player, g()->image);

    setPlayerDir(&g()->player, 'W');

	if (mlx_is_key_down(g()->mlx, MLX_KEY_LEFT))
	{
		rotate_view(&g()->player.dirX, &g()->player.dirY, &g()->player.planeX, &g()->player.planeY, 1 * M_PI / 180.0);
	}
	if (mlx_is_key_down(g()->mlx, MLX_KEY_RIGHT))
	{
		rotate_view(&g()->player.dirX, &g()->player.dirY, &g()->player.planeX, &g()->player.planeY, -1 * M_PI / 180.0);
	}


	double moveSpeed = 0.03;
    double newX, newY;

	//forward
    if (mlx_is_key_down(g()->mlx, MLX_KEY_W))
    {
        // Vérifier la collision pour l'axe X
        newX = g()->player.posX + g()->player.dirX * moveSpeed;
        if (g()->map[(int)newX][(int)g()->player.posY] == 0) // 0 indique un espace vide
        {
            g()->player.posX = newX;
        }

        // Vérifier la collision pour l'axe Y
        newY = g()->player.posY + g()->player.dirY * moveSpeed;
        if (g()->map[(int)g()->player.posX][(int)newY] == 0)
        {
            g()->player.posY = newY;
        }
    }

    // back
    if (mlx_is_key_down(g()->mlx, MLX_KEY_S))
    {
        newX = g()->player.posX - g()->player.dirX * moveSpeed;
        if (g()->map[(int)newX][(int)g()->player.posY] == 0)
        {
            g()->player.posX = newX;
        }

        newY = g()->player.posY - g()->player.dirY * moveSpeed;
        if (g()->map[(int)g()->player.posX][(int)newY] == 0)
        {
            g()->player.posY = newY;
        }
    }

    // right
    if (mlx_is_key_down(g()->mlx, MLX_KEY_A))
    {
        newX = g()->player.posX - g()->player.dirY * moveSpeed;
        if (g()->map[(int)newX][(int)g()->player.posY] == 0)
        {
            g()->player.posX = newX;
        }

        newY = g()->player.posY + g()->player.dirX * moveSpeed;
        if (g()->map[(int)g()->player.posX][(int)newY] == 0)
        {
            g()->player.posY = newY;
        }
    }

    // left
    if (mlx_is_key_down(g()->mlx, MLX_KEY_D))
    {
        newX = g()->player.posX + g()->player.dirY * moveSpeed;
        if (g()->map[(int)newX][(int)g()->player.posY] == 0)
        {
            g()->player.posX = newX;
        }

        newY = g()->player.posY - g()->player.dirX * moveSpeed;
        if (g()->map[(int)g()->player.posX][(int)newY] == 0)
        {
            g()->player.posY = newY;
        }
    }
}

int	main(int ac, char **av)
{
	int tempMap[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	int i, j;
    for(i = 0; i < 10; ++i) {
        for(j = 0; j < 10; ++j) {
            g()->map[i][j] = tempMap[i][j];
        }
    }

	g()->player.posX = 2.5;
	g()->player.posY = 2.5;
	g()->player.planeX = 0;
	g()->player.planeY = 0.66;
    g()->player.dirX = -1;
	g()->player.dirY = 0;


	(void)av;
	(void)ac;

	g()->mlx = mlx_init(VIEW_WIDTH, VIEW_HEIGHT, "LE PLus Beau Cub3D", false);
	g()->image = mlx_new_image(g()->mlx, VIEW_WIDTH, VIEW_HEIGHT);
    mlx_image_to_window(g()->mlx, g()->image, 0, 0);
    load_init_texture();

	mlx_loop_hook(g()->mlx, step, NULL);
	mlx_loop(g()->mlx);
	mlx_terminate(g()->mlx);
	return (EXIT_SUCCESS);
}