#include "../headers/file.h"
#include <stdlib.h>
#include <stdio.h>

int InitFile(file_t ** newFile, int taille){
    int sortie = 1;
    *newFile = (file_t*)malloc(sizeof(file_t));
    if(*newFile){
        char * debut = (char*)malloc(taille * sizeof(char));
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

int Enfiler(file_t * maFile, char ajout){
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
        for(int i =0; i < ((aAfficher->taille + 1) * 4); i++)
            printf("-");
        printf("\n--> ");
        
        for(int i = (aAfficher->deb + aAfficher->nb_element) % aAfficher->taille; i != aAfficher->deb; i = (i - 1) % aAfficher->taille){
            printf("%c | ", aAfficher->base[i]);
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

int Defiler(file_t * maFile, char * element){
    int sortie = 0;
    if(!FileVide(maFile)){
        *element = maFile->base[maFile->deb];
        maFile->nb_element --;
        maFile->deb = (maFile->deb + 1) % maFile->taille;
        sortie = 1;
    }
    return sortie;
}

int main(){
    file_t * test = NULL;
    InitFile(&test, 8);
    Enfiler(test,'a');

    AfficheFile(test);


    Enfiler(test,'b');
    Enfiler(test,'c');
    Enfiler(test,'d');
    Enfiler(test,'e');
    Enfiler(test,'f');
    Enfiler(test,'g');
    //Enfiler(test,'h');
    //Enfiler(test,'i');
    //Enfiler(test,'j');

    AfficheFile(test);

    char defile_el;
    while(!FileVide(test)){
        Defiler(test, &defile_el);
    }

    AfficheFile(test);

    LibererFile(test);
    return 0;
}