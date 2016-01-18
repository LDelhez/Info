#include "prog.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  const int N = 2;
  int* tab = malloc(N* sizeof(int));

   /* Intializes random number generator */
  time_t t;
  srand((unsigned) time(&t));

  int i;
  for(i=0;i<N;i++) {
    tab[i] = rand();
  }


  int ans = longueur_prefixe_suffixe(tab, N); 

  printf("%d\n", ans);

  free(tab);
  return 0;
}
