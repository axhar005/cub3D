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

        // Choix de la texture en fonction de l'orientation du mur
        int texNum;
        if (side == 0) {
            texNum = stepX > 0 ? 0 : 1; // Nord ou Sud
        } else {
            texNum = stepY > 0 ? 2 : 3; // Est ou Ouest
        }

        // Calcul de la valeur de texX
        double wallX;
        if (side == 0) wallX = player.posY + perpWallDist * rayDirY;
        else wallX = player.posX + perpWallDist * rayDirX;
        wallX -= floor(wallX);

        int texX = (int)(wallX * (double)g()->texture[texNum]->width);

        // Dessiner la colonne
        int y = drawStart;
        while (y < drawEnd) {
            // Calcul de texY
            int d = y * 256 - VIEW_HEIGHT * 128 + lineHeight * 128;
            int texY = ((d * g()->texture[texNum]->height) / lineHeight) / 256;

            // Obtenez la couleur de la texture
            uint32_t color = *((uint32_t*)g()->texture[texNum]->pixels + (texY * g()->texture[texNum]->width + texX));;
            uint32_t rearranged_color = ((color & 0xFF000000) >> 24) |  // R
                            ((color & 0x00FF0000) >> 8)  |  // G
                            ((color & 0x0000FF00) << 8)  |  // B
                            ((color & 0x000000FF) << 24);  // A

            // Dessinez le pixel
            mlx_put_pixel(image, x, y, rearranged_color);

            y++;
        }
        x++;
    }
}