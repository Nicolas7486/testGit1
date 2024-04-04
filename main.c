#include <allegro.h>
#include "Sous-Programme.h"
#define TRUE 1
#define FALSE 0
int main() {
    srand(time(NULL));
    allegro_init();
    install_keyboard();
    install_mouse();

    BITMAP *imageTitle;
    BITMAP *imageRect1;
    BITMAP *imageRect2;
    BITMAP *buffer; // Déclaration du double buffer


    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1500, 800, 0, 0) != 0) {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }



    imageTitle = load_bitmap("fond1.bmp", NULL); // ECRAN ACCUEIL
    if (!imageTitle)
    {
        allegro_message("Impossible de charger l'image de l'écran titre");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

   /* imageRect1 = load_bitmap("Cowboyo.bmp", NULL);
    if (!imageRect1)
    {
        allegro_message("Impossible de charger l'image pour le premier rectangle");
        allegro_exit();
        exit(EXIT_FAILURE);
    }*/

    imageRect2 = load_bitmap("Chapeau.bmp", NULL); // ici c les regles
    if (!imageRect2)
    {
        allegro_message("Impossible de charger l'image pour le deuxième rectangle");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP *currentImage = imageTitle;
    int imageLoaded = FALSE;
    int inRectangle1 = FALSE;
    int inRectangle2 = FALSE;
    int rect1Visible = TRUE;
    int rect2Visible = TRUE;

    // Création du double buffer avec les mêmes dimensions que l'écran
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    while (!key[KEY_ESC])
    {
        clear_to_color(buffer, makecol(0, 0, 0)); // Efface le contenu du double buffer

        // Dessine l'image sur le double buffer au centre de l'écran
        blit(currentImage, buffer, 0, 0, (SCREEN_W - currentImage->w) / 2, (SCREEN_H - currentImage->h) / 2, currentImage->w, currentImage->h);


        //////////////////////////////////////////////////////////

        // Rectangle 1
        if (rect1Visible && mouse_x >= 560 && mouse_x <= 745 && mouse_y >= 658 && mouse_y <= 780) {
            rect(buffer, 560, 658, 745, 780, makecol(255, 0, 255));

            if (mouse_b & 1) {
                currentImage = imageRect1;
               player();

                rect1Visible = FALSE;
            }
        }

        // Rectangle 2
        if (rect2Visible && mouse_x >= 750 && mouse_x <= 958 && mouse_y >= 658 && mouse_y <= 780) {
            rect(buffer, 750, 658, 958, 780, makecol(255, 0, 255));

            if (mouse_b & 1) {
                currentImage = imageRect2;
                imageLoaded = TRUE;
                rect2Visible = FALSE;
            }
        }

        ///////////////////////////////////////////////////////////

        // Si la touche Entrée est enfoncée, revenez à l'image initiale, peu importe l'image actuelle
        if (key[KEY_ENTER]) {
            currentImage = imageTitle;
            imageLoaded = FALSE;
            rect1Visible = TRUE;
            rect2Visible = TRUE;
        }

        // Transfère le contenu du double buffer à l'écran
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        // Efface le double buffer pour la prochaine itération
        clear_bitmap(buffer);

        rest(20); // Attend un peu pour éviter le défilement rapide
    }

    destroy_bitmap(buffer); // Libère la mémoire du double buffer
    destroy_bitmap(imageTitle);
    destroy_bitmap(imageRect1);
    destroy_bitmap(imageRect2);
    allegro_exit();



    return 0;
}
END_OF_MAIN();
