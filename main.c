#include <allegro.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int main()
{
    BITMAP *image1;
    BITMAP *image2;
    BITMAP *buffer; // Déclaration du double buffer

    srand(time(NULL));
    allegro_init();
    install_keyboard();
    install_mouse(); // Initialisation de la souris

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1500, 800, 0, 0) != 0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    image1 = load_bitmap("Stylo.bmp", NULL);
    if (!image1)
    {
        allegro_message("pas pu trouver/charger mon_image1.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    image2 = load_bitmap("Cowboyo.bmp", NULL);
    if (!image2)
    {
        allegro_message("pas pu trouver/charger mon_image2.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP *currentImage = image1;
    int imageLoaded = FALSE;
    int inRectangle = FALSE;

    // Création du double buffer avec les mêmes dimensions que l'écran
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    while (!key[KEY_ESC])
    {
        clear_to_color(buffer, makecol(0, 0, 0)); // Efface le contenu du double buffer

        // Dessine l'image sur le double buffer au centre de l'écran
        blit(currentImage, buffer, 0, 0, (SCREEN_W - currentImage->w) / 2, (SCREEN_H - currentImage->h) / 2, currentImage->w, currentImage->h);


        //////////////////////////////////////////////////////////

        // Dessine le rectangle non rempli sur le double buffer uniquement si la souris est à l'intérieur
        if (mouse_x >= 560 && mouse_x <= 745 && mouse_y >= 658 && mouse_y <= 780) {
            rect(buffer, 560, 658, 745, 780, makecol(255, 0, 255));
        }


        ///////////////////////////////////////////////////////////

        // Dessine le rectangle non rempli sur le double buffer uniquement si la souris est à l'intérieur
        if (currentImage == image1 && mouse_x >= 750 && mouse_x <= 958 && mouse_y >= 658 && mouse_y <= 780) {
            rect(buffer, 750, 658, 958, 780, makecol(255, 0, 255));
            inRectangle = TRUE;

            // Si le clic gauche est enfoncé à l'intérieur du rectangle
            if (mouse_b & 1) {
                // Chargez et affichez l'image choisie
                currentImage = image2;
                imageLoaded = TRUE;
            }
        }
        else {
            inRectangle = FALSE;
            imageLoaded = FALSE; // Réinitialisez l'état de l'image chargée si la souris n'est pas à l'intérieur du rectangle
        }

        // Si la touche Entrée est enfoncée, revenez à l'image initiale, peu importe l'image actuelle
        if (key[KEY_ENTER]) {
            currentImage = image1;
            imageLoaded = FALSE;
        }

        // Transfère le contenu du double buffer à l'écran
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        // Efface le double buffer pour la prochaine itération
        clear_bitmap(buffer);

        rest(20); // Attend un peu pour éviter le défilement rapide
    }

    destroy_bitmap(buffer); // Libère la mémoire du double buffer
    destroy_bitmap(image1);
    destroy_bitmap(image2);
    allegro_exit();
    return 0;
}
END_OF_MAIN();
