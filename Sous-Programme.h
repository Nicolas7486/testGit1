//
// Created by Nathan Dabi on 28/03/2024.
//

#ifndef ING1_2023_2024_GROUPE13_EQUIPE2_SOUS_PROGRAMME_H
#define ING1_2023_2024_GROUPE13_EQUIPE2_SOUS_PROGRAMME_H
#include <allegro.h>

// Structure pour définir les propriétés d'un joueur
typedef struct {
    BITMAP *bitmap; // Image
    int x; // Position en x
    int y; // Position en y
    int dx; // Vitesse en x
    int dy; // Vitesse en y
} Joueur;

// Structure pour définir les propriétés des ALIMENTS
typedef struct {
    BITMAP *bitmap; // Image
    int x; // Position en x
    int y; // Position en y
    int associe; // Indicateur d'association avec un joueur (0: non, 1: joueur 1, 2: joueur 2)
} Tomate;
typedef struct {
    BITMAP *bitmap; // Image
    int x; // Position en x
    int y; // Position en y
    int associe; // Indicateur d'association avec un joueur (0: non, 1: joueur 1, 2: joueur 2)
} Pain;
typedef struct {
    BITMAP *bitmap; // Image
    int x; // Position en x
    int y; // Position en y
    int associe; // Indicateur d'association avec un joueur (0: non, 1: joueur 1, 2: joueur 2)
} Viande;


// STRUCTURE POUR DEFINIR LES ZONES
typedef struct {
    int x;       // Coordonnée x du coin supérieur gauche
    int y;       // Coordonnée y du coin supérieur gauche
    int w;       // Largeur de la zone interdite
    int h;       // Hauteur de la zone interdite
} ZoneInterdite;
typedef struct {
    int x;       // Coordonnée x du coin supérieur gauche
    int y;       // Coordonnée y du coin supérieur gauche
    int w;       // Largeur de la zone de gaz
    int h;       // Hauteur de la zone de gaz
} ZoneGaz;
typedef struct {
    int x;       // Coordonnée x du coin supérieur gauche
    int y;       // Coordonnée y du coin supérieur gauche
    int w;       // Largeur de la zone de gaz
    int h;       // Hauteur de la zone de gaz
} ZoneGaz2;
typedef struct {
    int x;       // Coordonnée x du coin supérieur gauche
    int y;       // Coordonnée y du coin supérieur gauche
    int w;       // Largeur de la zone de gaz
    int h;       // Hauteur de la zone de gaz
} ZoneEvier;
typedef struct {
    int x_min; // Limite minimale en x
    int x_max; // Limite maximale en x
    int y_min; // Limite minimale en y
    int y_max; // Limite maximale en y
} LimiteMap;
typedef struct {
    int x; // Limite minimale en x
    int y; // Limite maximale en x
    int w; // Limite minimale en y
    int h; // Limite maximale en y
} ZoneCoffre;


typedef struct {
    int x, y; // Position de l'objet
    BITMAP *bitmap; // Image de l'objet
    int pris; // Indique si l'objet est pris ou non (0 pour non pris, 1 pour pris)
    int joueur; // Indique quel joueur a pris l'objet (0 pour aucun, 1 pour joueur 1, 2 pour joueur 2)
} Objets;

typedef struct {
    int x, y; // Position du joueur
    int prise; // Indique si le joueur tient un objet ou non (0 pour non, 1 pour oui)
    Objets *objet;
} Joueurs;


int player();
void deplacer(Joueur *joueur, int speed, ZoneInterdite zone_interdite, ZoneGaz zone_gaz, ZoneGaz2 zone_gaz2, ZoneCoffre zone_coffre, ZoneEvier zone_evier, LimiteMap limite_map);
int collision(Joueur joueur, Viande viande);
void items();
#endif //ING1_2023_2024_GROUPE13_EQUIPE2_SOUS_PROGRAMME_H
