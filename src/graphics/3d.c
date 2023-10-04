#include "../../inc/cub3D.h"

void raycast(t_player player, mlx_image_t *image) {
    int x = 0;
    while (x < VIEW_WIDTH) {
        double cameraX = 2 * x / (double)VIEW_WIDTH - 1;
        double rayDirX = player.dirX + player.planeX * cameraX;
        double rayDirY = player.dirY + player.planeY * cameraX;

        int mapX = (int)player.posX;
        int mapY = (int)player.posY;

        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double sideDistX, sideDistY;

        int stepX, stepY;
        int hit = 0, side = 0;
       
        // initialisation des valeurs de sideDistX et sideDistY
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (player.posX - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player.posX) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (player.posY - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player.posY) * deltaDistY;
        }

        // Boucle DDA
        while (hit == 0) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (g()->map[mapX][mapY] > 0) hit = 1;
        }

        // Calcul de la distance du mur au joueur pour éviter la distorsion "fishbowl"
        double perpWallDist;
        if (side == 0) perpWallDist = (mapX - player.posX + (1 - stepX) / 2) / rayDirX;
        else perpWallDist = (mapY - player.posY + (1 - stepY) / 2) / rayDirY;

        // Hauteur de la ligne à dessiner
        int lineHeight = (int)(VIEW_HEIGHT / perpWallDist);

        // Calculer les positions de départ et de fin pour dessiner la colonne verticale
        int drawStart = -lineHeight / 2 + VIEW_HEIGHT / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + VIEW_HEIGHT / 2;
        if (drawEnd >= VIEW_HEIGHT) drawEnd = VIEW_HEIGHT - 1;

        int y = drawStart;
        uint32_t color;

        // Choisissez la couleur en fonction de l'orientation du mur
        if (side == 0) { // Mur est-ouest
            color = rayDirX < 0 ? 0x44FF33FF : 0xF8FF33FF;  // Bleu si Ouest, Jaune si Est
        } else {  // Mur nord-sud
            color = rayDirY < 0 ? 0xFF3333FF : 0x334EFFFF;  // Rouge si Nord, Vert si Sud
        }

        while (y < drawEnd) {
            mlx_put_pixel(image, x, y, color);  // Utilisation de la couleur avec alpha
            y++;
        }
        x++;
    }
}