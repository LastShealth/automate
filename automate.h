#ifndef AUTOMATE
#define AUTOMATE

// en vrai cette structure est un peu inutile, on peut juste faire un tuple (malloc(konstante))
typedef struct tache {
    int duree;
    int dependances[100]; //dans aucun monde y a un truc avec plus de 100 de dependances
    int numero; // en vrai si je met dans un tableau ca sert a r, je peux juste prendre l'indice
}tache_h;

#endif