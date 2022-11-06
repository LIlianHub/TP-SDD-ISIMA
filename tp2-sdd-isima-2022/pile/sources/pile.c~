#include "../headers/pile.h"
#include <stdio.h>
#include <stdlib.h>

int initPile(pile_t ** newPile, int size){
  int sortie = 1;
  *newPile = (pile_t*)malloc(sizeof(pile_t));
  if(newPile){
    (*newPile)->tab = (char*)malloc(size*sizeof(char));
    if((*newPile)->tab){
      (*newPile)->nbelement = 0;
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


void libererPile(pile_t * pile){
  free(pile->tab);
  free(pile);
}

int estVidePile(pile_t * pile){
  int sortie = 1;
  if(pile->nbelement > 0){
    sortie = 0;
  }
  return sortie;
}

int estPleinePile(pile_t * pile){
  int sortie = 0;
  if(pile->nbelement >= pile->taille){
    sortie = 1;
  }
  return sortie;
}

int empiler(pile_t * pile, char ajout){
  int sortie = 0;
  if( !estPleinePile(pile) ){
    
    pile->tab[pile->nbelement]=ajout;
    pile->nbelement++;
    
    sortie = 1;
    
  }
  return sortie;
}

int depiler(pile_t * pile){
  int sortie = 0;
  if( !estVidePile(pile) ){
    pile->nbelement --;
    sortie = 1;
  }
  return sortie;
}

void affichPile(pile_t * pile){
  int i;
  if(estVidePile(pile)){
    printf("La pile est vide\n");
  }
  else{
    for(i=0; i<=pile->nbelement; i++){
      printf("%c ",pile->tab[i-1]);
    }
    printf("\n");
  }
}

int inversPile(pile_t pile){
  int sortie = 1;
  //principe du programme ?
  //tant que !estVidePile faire
  // enfiler la tete de la pile
  // depiler
  //ftq
  //empiler la tete de la file
  //defiler
  return sortie;
}

int main(){
  int size = 4;
  pile_t * maPile=NULL;
  initPile(&maPile,size);
  affichPile(maPile);
  empiler(maPile,'c');
  empiler(maPile,'a');
  empiler(maPile,'c');
  empiler(maPile,'a');
  affichPile(maPile);
  empiler(maPile,'a');
  affichPile(maPile);
  depiler(maPile);
  affichPile(maPile);
  depiler(maPile);
  depiler(maPile);
  depiler(maPile);
  affichPile(maPile);
  depiler(maPile);
  affichPile(maPile);
  libererPile(maPile);
  return 0;
}
