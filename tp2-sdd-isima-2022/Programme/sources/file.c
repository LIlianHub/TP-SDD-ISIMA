#include "../headers/file.h"
#include <stdlib.h>
#include <stdio.h>

int InitFile(file_t ** newFile, int taille){
    int sortie = 1;
    *newFile = (file_t*)malloc(sizeof(file_t));
    if(*newFile){
        enfilable_t * debut = (enfilable_t*)malloc(taille * sizeof(enfilable_t));
        if(debut){
            (*newFile)->base = debut;
            (*newFile)->deb = 0;
            (*newFile)->taille = taille;
            (*newFile)->nb_element = 0;
        }
        else{
            free(newFile);
            sortie = 0;
        }
    }
    else{
        sortie = 0;
    }
    return sortie;
}

void LibererFile(file_t * aLiberer){
    free(aLiberer->base);
    free(aLiberer);
}

int FilePleine(file_t * maFile){
    return(maFile->nb_element == maFile->taille);
}

int FileVide(file_t * maFile){
    return(maFile->nb_element == 0);
}

int Enfiler(file_t * maFile, enfilable_t ajout){
    int sortie = 0;
    if(!FilePleine(maFile)){
        int emplacement = (maFile->deb + maFile->nb_element) % maFile->taille;
        maFile->base[emplacement] = ajout;
        maFile->nb_element ++;
        sortie = 1;
    }
    return sortie;
}

void AfficheFile(file_t * aAfficher){
    if(!FileVide(aAfficher)){
        for(int i = 0; i < ((aAfficher->taille + 1) * 4); i++)
            printf("-");
        printf("\n--> ");

        int cur = (aAfficher->deb + aAfficher->nb_element - 1) % aAfficher->taille;
        while(cur != aAfficher->deb){
            printf("%c | ", aAfficher->base[cur]);
            if(cur == 0)
                cur = aAfficher->taille - 1;
            else
                cur--;
        }

        printf("%c",aAfficher->base[aAfficher->deb]);
        printf("\n");
        for(int i =0; i < ((aAfficher->taille + 1) * 4); i++)
            printf("-");
        printf("\n");
    }
    else{
        printf("La file est vide !\n");
    }
}

int Defiler(file_t * maFile, enfilable_t * element){
    int sortie = 0;
    if(!FileVide(maFile)){
        *element = maFile->base[maFile->deb];
        maFile->nb_element --;
        maFile->deb = (maFile->deb + 1) % maFile->taille;
        sortie = 1;
    }
    return sortie;
}
