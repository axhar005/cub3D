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
