//
// Created by Nathan Dabi on 03/04/2024.
//
#include "Sous-Programme.h"
#include <allegro.h>




void items() {


    BITMAP *objets_images[5];
    objets_images[0] = load_bitmap("objet1.bmp", NULL);
    objets_images[1] = load_bitmap("objet2.bmp", NULL);
    objets_images[2] = load_bitmap("objet3.bmp", NULL);
    objets_images[3] = load_bitmap("objet4.bmp", NULL);
    objets_images[4] = load_bitmap("objet5.bmp", NULL);


    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
    clear_to_color(buffer, makecol(0, 0, 0));

    // Initialisation des objets
    Objets objets[5];
    for (int i = 0; i < 5; i++) {
        objets[i].x = rand() % SCREEN_W;
        objets[i].y = rand() % SCREEN_H;
        objets[i].bitmap = load_bitmap("objet.bmp", NULL);
        objets[i].pris = 0;
        objets[i].joueur = 0;
    }

    // Initialisation des joueurs
    Joueur joueur1 = {100, 100, 0, NULL};
    Joueur joueur2 = {200, 200, 0, NULL};

    int prise = 15; // Rayon de prise de l'objet

    while (!key[KEY_ESC]) {
        // Affichage des objets
        for (int i = 0; i < 5; i++) {
            draw_sprite(buffer, objets[i].bitmap, objets[i].x, objets[i].y);
        }

        // Affichage des joueurs
        if (!joueur1.prise) {
            draw_sprite(buffer, joueur1.objet->bitmap, joueur1.x, joueur1.y);
        }
        if (!joueur2.prise) {
            draw_sprite(buffer, joueur2.objet->bitmap, joueur2.x, joueur2.y);
        }

        // Vérification si un joueur est à portée d'un objet pour le prendre
        if (key[KEY_P]) {
            for (int i = 0; i < 5; i++) {
                if (!objets[i].pris && !joueur1.prise &&
                    sqrt(pow(objets[i].x - joueur1.x, 2) + pow(objets[i].y - joueur1.y, 2)) <= prise) {
                    objets[i].pris = 1;
                    objets[i].joueur = 1;
                    joueur1.objet = &objets[i];
                    joueur1.prise = 1;
                }
                if (!objets[i].pris && !joueur2.prise &&
                    sqrt(pow(objets[i].x - joueur2.x, 2) + pow(objets[i].y - joueur2.y, 2)) <= prise) {
                    objets[i].pris = 1;
                    objets[i].joueur = 2;
                    joueur2.objet = &objets[i];
                    joueur2.prise = 1;
                }
            }
        }

        // Vérification si un joueur lâche l'objet qu'il tient
        if (key[KEY_L]) {
            if (joueur1.prise) {
                joueur1.prise = 0;
                joueur1.objet->pris = 0;
                joueur1.objet->joueur = 0;
                joueur1.objet = NULL;
            }
            if (joueur2.prise) {
                joueur2.prise = 0;
                joueur2.objet->pris = 0;
                joueur2.objet->joueur = 0;
                joueur2.objet = NULL;
            }
        }
    }
}