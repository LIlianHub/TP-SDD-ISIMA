#include "../headers/pile.h"
#include "../headers/file.h"
#include <stdio.h>
#include <stdlib.h>

int InitPile(pile_t ** newPile, int size){
  int sortie = 1;
  *newPile = (pile_t*)malloc(sizeof(pile_t));
  if(newPile){
    (*newPile)->base = (empilable_t*)malloc(size*sizeof(empilable_t));
    if((*newPile)->base){
      (*newPile)->nb_element = 0;
      (*newPile)->taille = size;
    }
    else{
      free(newPile);
      sortie = 0;
    }
  }
  else{
    sortie = 0;
  }
  return sortie;
 }


void LibererPile(pile_t * pile){
  free(pile->base);
  free(pile);
}

int PileVide(pile_t * pile){
  return (pile->nb_element == 0);
}

int PilePleine(pile_t * pile){
  return (pile->nb_element == pile->taille);
}

int Empiler(pile_t * pile, empilable_t ajout){
  int sortie = 0;
  if(!PilePleine(pile)){
    
    pile->base[pile->nb_element] = ajout;
    pile->nb_element++;
    
    sortie = 1;
  }
  return sortie;
}

int Depiler(pile_t * pile, empilable_t * element){
  int sortie = 0;
  if(!PileVide(pile)){
    pile->nb_element --;
    *element = pile->base[pile->nb_element];
    sortie = 1;
  }
  return sortie;
}

void AffichePile(pile_t * pile){
  int i;
  if(PileVide(pile)){
    printf("La pile est vide\n");
  }
  else{
    for(i = (pile->nb_element) - 1; i >=0 ; i--){
      printf("| %c |\n",pile->base[i]);
    }
    printf("-----\n");
  }
}

void InversePile(pile_t * pile){
  empilable_t outil;

  file_t * file = NULL;
  InitFile(&file, pile->taille);

  while(!PileVide(pile)){
    Depiler(pile, &outil);
    Enfiler(file,outil);
  }

  while(!FileVide(file)){
    Defiler(file, &outil);
    Empiler(pile, outil);
  }

  LibererFile(file);
}

