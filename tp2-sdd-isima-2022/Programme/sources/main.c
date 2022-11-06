#include "../headers/pile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int size = 8;
  pile_t * maPile = NULL;
  InitPile(&maPile,size);

  AffichePile(maPile);

  Empiler(maPile,'a');
  Empiler(maPile,'b');
  Empiler(maPile,'c');
  Empiler(maPile,'d');
  Empiler(maPile,'e');
  Empiler(maPile,'f');
  Empiler(maPile,'g');
  Empiler(maPile,'h');
  Empiler(maPile,'i');

  AffichePile(maPile);

  InversePile(maPile);

  AffichePile(maPile);
  
  LibererPile(maPile);
  return 0;
}
