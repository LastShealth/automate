#include "automate.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void read (char* nomDuTXT){
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
    tache_h* tableau[100]; // j'ai mis 100 sur les deux, mais je pense que majore bien
    char* temp; //wallah c'est un temp qui est temp
    while (fgets(buffer, 2, pointeurFichier)) {
        printf("%s", buffer);
        temp = strtok(buffer, " "); 
        //en gros je split buffer et je prend un morceau a chaque fois 

        tableau[compteur] = malloc(sizeof(tache_h));
        tableau[compteur]->numero = atoi(temp); //eh je le met car il me le donne sinon c'est le compteur
        //atoi c'est pour "Interprets an integer value in a byte string [...]" (source Zeal)
        temp = strtok(NULL, " ");//la je prend le prochain mais jsp pk le NULL, idk g trouve ca sur Stack Overflow

        tableau[compteur]->duree = atoi(temp);

        temp = strtok(NULL, " ");

        for(int i = 0; temp != NULL;i++){
            tableau[compteur]->dependances[i] = atoi(temp);
            temp = strtok(NULL, " ");
        }
        compteur++;
    }


    fclose(pointeurFichier);
}





int main (){
    printf("debut\n");
    read("table/table 1.txt");
    printf("\nfin\n");
}
