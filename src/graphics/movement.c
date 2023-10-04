#include "../../inc/cub3D.h"

void rotate_view(double *dirX, double *dirY, double *planeX, double *planeY, double theta)
{
    // Rotation du vecteur direction
    double oldDirX = *dirX;
    *dirX = *dirX * cos(theta) - *dirY * sin(theta);
    *dirY = oldDirX * sin(theta) + *dirY * cos(theta);

    // Rotation du vecteur plan
    double oldPlaneX = *planeX;
    *planeX = *planeX * cos(theta) - *planeY * sin(theta);
    *planeY = oldPlaneX * sin(theta) + *planeY * cos(theta);
}

void player_rotation(void)
{
    int rot_speed;

    if (mlx_is_key_down(g()->mlx, MLX_KEY_LEFT_SHIFT))
        rot_speed = MAX_ROT_SPEED;
    else
        rot_speed = MIN_ROT_SPEED;
    if (mlx_is_key_down(g()->mlx, MLX_KEY_LEFT))
    {
        rotate_view(&g()->player.dirX, &g()->player.dirY, &g()->player.planeX, &g()->player.planeY, rot_speed * M_PI / 180.0);
    }
    if (mlx_is_key_down(g()->mlx, MLX_KEY_RIGHT))
    {
        rotate_view(&g()->player.dirX, &g()->player.dirY, &g()->player.planeX, &g()->player.planeY, -rot_speed * M_PI / 180.0);
    }
}

void setPlayerDir(t_player *player, char c)
{
    static bool first = true;

    if (first == true)
    {
        if (c == 'S') {
            player->dirX = 0;
            player->dirY = 1;
            player->planeX = 0.66;
            player->planeY = 0;
        } else if (c == 'E') {
            player->dirX = -1;
            player->dirY = 0;
            player->planeX = 0;
            player->planeY = 0.66;
        } else if (c == 'W') {
            player->dirX = 1;
            player->dirY = 0;
            player->planeX = 0;
            player->planeY = -0.66;
        } else {
            player->dirX = 0;
            player->dirY = -1;
            player->planeX = -0.66;
            player->planeY = 0;
        }
        first = false;
    }
}

void player_movement(void)
{
    double newX, newY;
    //forward
    if (mlx_is_key_down(g()->mlx, MLX_KEY_LEFT_SHIFT))
        g()->player.move_speed = 0.06;
    else
        g()->player.move_speed = 0.03;

    if (mlx_is_key_down(g()->mlx, MLX_KEY_W))
    {
        // Vérifier la collision pour l'axe X
        newX = g()->player.posX + g()->player.dirX * g()->player.move_speed;
        if (g()->map[(int)newX][(int)g()->player.posY] == 0) // 0 indique un espace vide
        {
            g()->player.posX = newX;
        }

        // Vérifier la collision pour l'axe Y
        newY = g()->player.posY + g()->player.dirY * g()->player.move_speed;
        if (g()->map[(int)g()->player.posX][(int)newY] == 0)
        {
            g()->player.posY = newY;
        }
    }

    // back
    if (mlx_is_key_down(g()->mlx, MLX_KEY_S))
    {
        newX = g()->player.posX - g()->player.dirX * g()->player.move_speed;
        if (g()->map[(int)newX][(int)g()->player.posY] == 0)
        {
            g()->player.posX = newX;
        }

        newY = g()->player.posY - g()->player.dirY * g()->player.move_speed;
        if (g()->map[(int)g()->player.posX][(int)newY] == 0)
        {
            g()->player.posY = newY;
        }
    }

    // right
    if (mlx_is_key_down(g()->mlx, MLX_KEY_A))
    {
        newX = g()->player.posX - g()->player.dirY * g()->player.move_speed;
        if (g()->map[(int)newX][(int)g()->player.posY] == 0)
        {
            g()->player.posX = newX;
        }

        newY = g()->player.posY + g()->player.dirX * g()->player.move_speed;
        if (g()->map[(int)g()->player.posX][(int)newY] == 0)
        {
            g()->player.posY = newY;
        }
    }

    // left
    if (mlx_is_key_down(g()->mlx, MLX_KEY_D))
    {
        newX = g()->player.posX + g()->player.dirY * g()->player.move_speed;
        if (g()->map[(int)newX][(int)g()->player.posY] == 0)
        {
            g()->player.posX = newX;
        }

        newY = g()->player.posY - g()->player.dirX * g()->player.move_speed;
        if (g()->map[(int)g()->player.posX][(int)newY] == 0)
        {
            g()->player.posY = newY;
        }
    }
}