
#include "../../inc/cub3D.h"

void set_background(mlx_image_t *image, uint32_t floor_color, uint32_t roof_color)
{
     // Dessiner le ciel
    int x1 = 0;
    int y1 = 0;
    while (y1 < VIEW_HEIGHT / 2) {
        x1 = 0;
        while (x1 < VIEW_WIDTH) {
            mlx_put_pixel(image, x1, y1, floor_color); // couleur du ciel en RGB
            x1++;
        }
        y1++;
    }
    // Dessiner le sol
    y1 = VIEW_HEIGHT / 2;
    while (y1 < VIEW_HEIGHT) {
        x1 = 0;
        while (x1 < VIEW_WIDTH) {
            mlx_put_pixel(image, x1, y1, roof_color); // couleur du sol en RGB
            x1++;
        }
        y1++;
    }
}