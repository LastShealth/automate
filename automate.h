#ifndef AUTOMATE
#define AUTOMATE

// en vrai cette structure est un peu inutile, on peut juste faire un tuple (malloc(konstante))
typedef struct tache {
    int duree;
    int dependances[100]; //dans aucun monde y a un truc avec plus de 100 de dependances
    int numero; // en vrai si je met dans un tableau ca sert a r, je peux juste prendre l'indice
}tache_h;

typedef struct sommet {
    tache_h apres[100]; //pour omega c'est NULL
    int poid_apres[100];//oui je majore ca par 100

    int shark;
    int snail; //f we ball
} sommet_h;

typedef struct graphe {
    sommet_h* S;
    int A[100][100]; //big matrix boy
}graphe_h;

#endif