#ifndef PILE_H
#define PILE_H

/*type de la pile*/
typedef char empilable_t;

/*Structure*/
typedef struct pile{
  int taille;
  int nb_element;
  empilable_t * base;  
} pile_t;



/*Fonction*/
int InitPile(pile_t ** newPile, int taille) ;
void LibererPile(pile_t * pile);
int PileVide(pile_t * pile);
int PilePleine(pile_t *pile);
int Empiler(pile_t * pile, empilable_t ajout);
int Depiler(pile_t * pile, empilable_t * element);
void AffichePile(pile_t * pile);
void InversePile(pile_t * pile);

#endif



