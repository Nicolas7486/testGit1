//
// Created by Nathan Dabi on 03/04/2024.
//
#include <allegro.h>
#include "Sous-Programme.h"
void items( Joueur joueur1,  Joueur joueur2,   Tomate *tomate,  Viande *viande, Pain *pain,ViandeCuite *viandecuite ,Burger *burger, Salade *salade){


    int tolerance = (30);


    if(abs(tomate->x+10 - joueur1.x)<= tolerance && abs(tomate->y -joueur1.y)<= tolerance && key[KEY_P] ){
        tomate->x = joueur1.x;
        tomate->y = joueur1.y;

    }

    if(abs(viande->x+10 - joueur1.x)<= tolerance && abs(viande->y -joueur1.y)<= tolerance && key[KEY_P] ){
        viande->x = joueur1.x;
        viande->y = joueur1.y;
    }
    if(abs(pain->x+10 - joueur1.x)<= tolerance && abs(pain->y -joueur1.y)<= tolerance && key[KEY_P] ){
        pain->x = joueur1.x;
        pain->y = joueur1.y;

    }
    if(abs(burger->x+10 - joueur1.x)<= tolerance && abs(burger->y -joueur1.y)<= tolerance && key[KEY_P] ){
        burger->x = joueur1.x;
        burger->y = joueur1.y;

    }
    if(abs(viandecuite->x+10 - joueur1.x)<= tolerance && abs(viandecuite->y -joueur1.y)<= tolerance && key[KEY_P] ){
        viandecuite->x = joueur1.x;
        viandecuite->y = joueur1.y;

    }
    if(abs(salade->x+10 - joueur1.x)<= tolerance && abs(salade->y -joueur1.y)<= tolerance && key[KEY_P] ){
        salade->x = joueur1.x;
        salade->y = joueur1.y;

    }




    if(abs(tomate->x+10 - joueur2.x)<= tolerance && abs(tomate->y -joueur2.y)<= tolerance && key[KEY_E] ){
        tomate->x = joueur2.x;
        tomate->y = joueur2.y;

    }

    if(abs(pain->x+10 - joueur2.x)<= tolerance && abs(pain->y -joueur2.y)<= tolerance && key[KEY_E] ){
        pain->x = joueur2.x;
        pain->y = joueur2.y;

    }
    if(abs(viande->x+10 - joueur2.x)<= tolerance && abs(viande->y -joueur2.y)<= tolerance && key[KEY_E]){
        viande->x = joueur2.x;
        viande->y = joueur2.y;

    }
    if(abs(burger->x+10 - joueur2.x)<= tolerance && abs(burger->y -joueur2.y)<= tolerance && key[KEY_E]){
        burger->x = joueur2.x;
        burger->y = joueur2.y;

    }
    if(abs(viandecuite->x+10 - joueur2.x)<= tolerance && abs(viandecuite->y -joueur2.y)<= tolerance && key[KEY_E]){
        viandecuite->x = joueur2.x;
        viandecuite->y = joueur2.y;

    }
    if(abs(salade->x+10 - joueur2.x)<= tolerance && abs(salade->y -joueur2.y)<= tolerance && key[KEY_E]){
        salade->x = joueur2.x;
        salade->y = joueur2.y;

    }

}



