//
// Created by Nathan Dabi on 28/03/2024.
//

#include "Sous-Programme.h"

int player() {

    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
    clear_to_color(buffer, makecol(0, 0, 0));
    BITMAP *background = load_bitmap("newfond.bmp", NULL);
    Joueur joueur1 = {load_bitmap("joueur1.bmp", NULL), 1100, 155, 0, 0};
    Joueur joueur2 = {load_bitmap("joueur2.bmp", NULL), 220, 550, 0, 0};
    Tomate tomate = {load_bitmap("tomate.bmp", NULL), 150, 210, 0};
    Pain pain = {load_bitmap("pain.bmp", NULL), 120, 268, 0};
    Viande viande = {load_bitmap("viande.bmp", NULL), 150, 327, 0};
// Création des structures pour les propriétés des joueurs
// Définition des coordonnées de la zone interdite

    ZoneInterdite zone_interdite = {470, 325, 558, 113};
    ZoneGaz zone_gaz = {707, 157, 240, 55};
    LimiteMap limite_map = {64, 1428, 100, 713};
    ZoneCoffre zone_coffre = {67, 155, 82, 345};
    ZoneGaz2 zone_gaz2 ={946,553, 243, 57};
    ZoneEvier zone_Evier ={1345,215,85,225};

    int speed = 10;
    int tomatePrise = 0;

// Boucle interactive
    while (!key[KEY_ESC]) {
        draw_sprite(buffer, background, 0, 0);
        draw_sprite(buffer, pain.bitmap, pain.x, pain.y);
        draw_sprite(buffer, viande.bitmap, viande.x, viande.y);


// Déplacement du joueur 1 avec les touches fléchées
        if (key[KEY_UP]) joueur1.dy = -speed; else if (key[KEY_DOWN]) joueur1.dy = speed; else joueur1.dy = 0;
        if (key[KEY_LEFT]) joueur1.dx = -speed; else if (key[KEY_RIGHT]) joueur1.dx = speed; else joueur1.dx = 0;
        if (key[KEY_Z]) joueur2.dy = -speed; else if (key[KEY_S]) joueur2.dy = speed; else joueur2.dy = 0;
        if (key[KEY_Q]) joueur2.dx = -speed; else if (key[KEY_D]) joueur2.dx = speed; else joueur2.dx = 0;

// Déplacement des joueurs avec gest
// ion des bords
        deplacer(&joueur1, speed, zone_interdite, zone_gaz, zone_gaz2, zone_coffre, zone_Evier, limite_map);
        deplacer(&joueur2, speed, zone_interdite, zone_gaz, zone_gaz2, zone_coffre, zone_Evier, limite_map);

// Affichage des joueurs à leur nouvelle position
        draw_sprite(buffer, joueur1.bitmap, joueur1.x, joueur1.y);
        draw_sprite(buffer, joueur2.bitmap, joueur2.x, joueur2.y);

// Affichage de la tomate si elle n'est pas associée à un joueur
        if (!tomate.associe) {
            draw_sprite(buffer, tomate.bitmap, tomate.x, tomate.y);}
        if (!viande.associe) {
            draw_sprite(buffer, viande.bitmap, viande.x, viande.y);}


// Si la touche P est appuyée, vérifier si la tomate peut s'associer à un joueur
     /*   // Gestion de la prise de la tomate
        if (key[KEY_P] && !tomatePrise) {
            // Prendre la tomate si elle n'est pas déjà prise
            if (collision(joueur1, viande) && !tomate.associe) {
                tomate.associe = 1; // Associer à joueur 1
                tomatePrise = 1;
            } else if (collision(joueur2, viande) && !tomate.associe) {
                tomate.associe = 2; // Associer à joueur 2
                tomatePrise = 1;
            }
        }

        // Gestion de la prise de la viande
        if (key[KEY_V] && !tomatePrise) {
            // Prendre la viande si elle n'est pas déjà prise et qu'aucun joueur n'a la tomate
            if (collision(joueur1, viande) && !viande.associe) {
                viande.associe = 1; // Associer à joueur 1
            } else if (collision(joueur2, viande) && !viande.associe) {
                viande.associe = 2; // Associer à joueur 2
            }
        }
        // Lâcher la pomme ou la viande si elle est prise
        if (key[KEY_L] && (tomatePrise || viande.associe)) {
            if (tomatePrise) {
                // Lâcher la pomme si elle est prise
                if (tomate.associe == 1) {
                    tomate.associe = 0;
                    tomate.x = joueur1.x;
                    tomate.y = joueur1.y;
                    tomatePrise = 0;
                } else if (tomate.associe == 2) {
                    tomate.associe = 0;
                    tomate.x = joueur2.x;
                    tomate.y = joueur2.y;
                    tomatePrise = 0;
                }
            } else {
                // Lâcher la viande si elle est prise
                viande.associe = 0;
                if (viande.associe == 1) {
                    viande.x = joueur1.x;
                    viande.y = joueur1.y;
                } else if (viande.associe == 2) {
                    viande.x = joueur2.x;
                    viande.y = joueur2.y;
                }
            }
        }*/
      items();
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    destroy_bitmap(buffer);
}


int collision(Joueur joueur, Viande viande) {
    return (joueur.x < viande.x + viande.bitmap->w &&
            joueur.x + joueur.bitmap->w > viande.x &&
            joueur.y < viande.y + viande.bitmap->h &&
            joueur.y + joueur.bitmap->h > viande.y);

}

// Fonction pour déplacer un joueur avec gestion des zones
// Fonction pour déplacer un joueur avec gestion des zones
void deplacer(Joueur *joueur, int speed, ZoneInterdite zone_interdite, ZoneGaz zone_gaz, ZoneGaz2 zone_gaz2, ZoneCoffre zone_coffre, ZoneEvier zone_evier, LimiteMap limite_map) {
    // Déplacement en x
    joueur->x += joueur->dx;
    // Vérification des limites de la carte en x
    if (joueur->x < limite_map.x_min) {
        joueur->x = limite_map.x_min;
    } else if (joueur->x + joueur->bitmap->w > limite_map.x_max) {
        joueur->x = limite_map.x_max - joueur->bitmap->w;
    }
    // Vérification de la zone interdite en x
    if (joueur->x + joueur->bitmap->w > zone_interdite.x && joueur->x < zone_interdite.x + zone_interdite.w &&
        joueur->y + joueur->bitmap->h > zone_interdite.y && joueur->y < zone_interdite.y + zone_interdite.h) {
        if (joueur->dx > 0) {
            joueur->x = zone_interdite.x - joueur->bitmap->w;
        } else {
            joueur->x = zone_interdite.x + zone_interdite.w;
        }
    }
    // Vérification de la zone "gaz" en x
    if (joueur->x + joueur->bitmap->w > zone_gaz.x && joueur->x < zone_gaz.x + zone_gaz.w &&
        joueur->y + joueur->bitmap->h > zone_gaz.y && joueur->y < zone_gaz.y + zone_gaz.h) {
        if (joueur->dx > 0) {
            joueur->x -= speed;  // Ajuster le déplacement vers la gauche
        } else if (joueur->dx < 0) {
            joueur->x += speed;  // Ajuster le déplacement vers la droite
        }
    }
    // Vérification de la zone "gaz2" en x
    if (joueur->x + joueur->bitmap->w > zone_gaz2.x && joueur->x < zone_gaz2.x + zone_gaz2.w &&
        joueur->y + joueur->bitmap->h > zone_gaz2.y && joueur->y < zone_gaz2.y + zone_gaz2.h) {
        if (joueur->dx > 0) {
            joueur->x -= speed;  // Ajuster le déplacement vers la gauche
        } else if (joueur->dx < 0) {
            joueur->x += speed;  // Ajuster le déplacement vers la droite
        }
    }
    // Vérification de la zone de coffre en x
    if (joueur->x + joueur->bitmap->w > zone_coffre.x && joueur->x < zone_coffre.x + zone_coffre.w &&
        joueur->y + joueur->bitmap->h > zone_coffre.y && joueur->y < zone_coffre.y + zone_coffre.h) {
        if (joueur->dx > 0) {
            joueur->x -= speed;  // Ajuster le déplacement vers la gauche
        } else if (joueur->dx < 0) {
            joueur->x += speed;  // Ajuster le déplacement vers la droite
        }
    }
    if (joueur->x + joueur->bitmap->w > zone_evier.x && joueur->x < zone_evier.x + zone_evier.w &&
        joueur->y + joueur->bitmap->h > zone_evier.y && joueur->y < zone_evier.y + zone_evier.h) {
        if (joueur->dx > 0) {
            joueur->x -= speed;  // Ajuster le déplacement vers la gauche
        } else if (joueur->dx < 0) {
            joueur->x += speed;  // Ajuster le déplacement vers la droite
        }
    }


    // Déplacement en y
    joueur->y += joueur->dy;
    // Vérification des limites de la carte en y
    if (joueur->y < limite_map.y_min) {
        joueur->y = limite_map.y_min;
    } else if (joueur->y + joueur->bitmap->h > limite_map.y_max) {
        joueur->y = limite_map.y_max - joueur->bitmap->h;
    }
    // Vérification de la zone interdite en y
    if (joueur->y + joueur->bitmap->h > zone_interdite.y && joueur->y < zone_interdite.y + zone_interdite.h &&
        joueur->x + joueur->bitmap->w > zone_interdite.x && joueur->x < zone_interdite.x + zone_interdite.w) {
        if (joueur->dy > 0) {
            joueur->y = zone_interdite.y - joueur->bitmap->h;
        } else {
            joueur->y = zone_interdite.y + zone_interdite.h;
        }
    }
    // Vérification de la zone "gaz" en y
    if (joueur->y + joueur->bitmap->h > zone_gaz.y && joueur->y < zone_gaz.y + zone_gaz.h &&
        joueur->x + joueur->bitmap->w > zone_gaz.x && joueur->x < zone_gaz.x + zone_gaz.w) {
        if (joueur->dy > 0) {
            joueur->y -= speed;  // Ajuster le déplacement vers le haut
        } else if (joueur->dy < 0) {
            joueur->y += speed;  // Ajuster le déplacement vers le bas
        }
    }
    // Vérification de la zone "gaz2" en y
    if (joueur->y + joueur->bitmap->h > zone_gaz2.y && joueur->y < zone_gaz2.y + zone_gaz2.h &&
        joueur->x + joueur->bitmap->w > zone_gaz2.x && joueur->x < zone_gaz2.x + zone_gaz2.w) {
        if (joueur->dy > 0) {
            joueur->y -= speed;  // Ajuster le déplacement vers le haut
        } else if (joueur->dy < 0) {
            joueur->y += speed;  // Ajuster le déplacement vers le bas
        }
    }
    // Vérification de la zone de coffre en y
    if (joueur->y + joueur->bitmap->h > zone_coffre.y && joueur->y < zone_coffre.y + zone_coffre.h &&
        joueur->x + joueur->bitmap->w > zone_coffre.x && joueur->x < zone_coffre.x + zone_coffre.w) {
        if (joueur->dy > 0) {
            joueur->y -= speed;  // Ajuster le déplacement vers le haut
        } else if (joueur->dy < 0) {
            joueur->y += speed;  // Ajuster le déplacement vers le bas
        }
    }
    if (joueur->y + joueur->bitmap->h > zone_evier.y && joueur->y < zone_evier.y + zone_evier.h &&
        joueur->x + joueur->bitmap->w > zone_evier.x && joueur->x < zone_evier.x + zone_evier.w) {
        if (joueur->dy > 0) {
            joueur->y -= speed;  // Ajuster le déplacement vers le haut
        } else if (joueur->dy < 0) {
            joueur->y += speed;  // Ajuster le déplacement vers le bas
        }
    }

}
