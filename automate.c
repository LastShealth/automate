#include "automate.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

tache_h** read (char* nomDuTXT){
    //verif 2s si le nom est good or nah
    int compteur = 0;    
    while (nomDuTXT[compteur] != '\0' && nomDuTXT[compteur] != '.')
        compteur++;
    
    if (strcmp((char*)&nomDuTXT[compteur], ".txt\0")) { //strcmp renvoie 0 si y a 0 difference entre eux
        printf("t sur c'est un txt\n"); //en vrai je pense vraiment que le txt check n'est pas obligatoire, mais eh
        assert(0);// :)
    }

    FILE* pointeurFichier = fopen(nomDuTXT, "r");

    if(!pointeurFichier){//NULL check
        printf("ta mal ecrit, c juste table 1.txt\n");
        assert(0);// :)
    }
    compteur = 0; //recyclage de variable, 100% bio 
    char buffer[100]; 
    tache_h** tableau = malloc(sizeof(tache_h*) * 100); // j'ai mis 100 sur les deux, mais je pense que majore bien
                                                            //anyways je ne le remplie dyamiquement
    char* temp; //wallah c'est un temp qui est temp
    while (fgets(buffer, 100, pointeurFichier)) {
        // printf("%s\n", buffer);
        temp = strtok(buffer, " "); //en gros je split buffer et je prend un morceau a chaque fois 
                                            //et temp devient null des qu'il y a plus rien
        tableau[compteur] = malloc(sizeof(tache_h));
        tableau[compteur]->numero = atoi(temp); //eh je le met car il me le donne sinon c'est le compteur
                                                    //atoi c'est pour "Interprets an integer value in a byte string [...]" (source Zeal)
        temp = strtok(NULL, " ");//la je prend le prochain mais jsp pk le NULL, idk g trouve ca sur Stack Overflow

        tableau[compteur]->duree = atoi(temp);
        temp = strtok(NULL, " ");
        if(temp[1]=='\n')temp = NULL; //idk why but il n'est pas null 

        for(int i = 0;i<100;i++){
            tableau[compteur]->dependances[i] = -1;
            if (temp != NULL){
                tableau[compteur]->dependances[i] = atoi(temp);
                temp = strtok(NULL, " ");
            }
        }
        compteur++;
    }


    fclose(pointeurFichier);
    return tableau;
}


void affiche_tab (tache_h** t) {
    printf("debut affiche\n");
    for(int i = 0; i < 100 ; i++){
        if (t[i] == NULL) break;
        printf("tache n°%d avec une duree : %d et a pour dependeces : ",i,t[i]->duree);//oui je triche pour le num mais la meme
        for(int j = 0; j < 3; j++){  
            printf("%d ",t[i]->dependances[j]);
        }
        printf("\n");
    }
    printf("fin affichage\n");
}


void graphifitication (tache_h** t) { //ca c'est un nom qui nom
    int compteur = 0; //a deux doight de le mettre en varaible globale et de le recylcer encore une fois
    graphe_h* res = malloc(sizeof(graphe_h));
    while (t[compteur] != NULL) {
        
    }
}




int main (){
    tache_h** tab;
    printf("debut\n");
    tab = read("table/table 1.txt");
    affiche_tab(tab);
    printf("\nfin\n");
}
