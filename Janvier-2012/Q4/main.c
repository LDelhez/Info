#include "prog.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  const int N = 20;
  int* tab = malloc(N* sizeof(int)); // tableau de N entiers

   /* Intializes random number generator */
  time_t t;
  srand((unsigned) time(&t));

  int i;
  for(i=0;i<N;i++) {
    tab[i] = rand();
  }

  int ans = longueur_prefixe_suffixe(tab, N); // calcule la longueur max

  printf("%d\n", ans);

  free(tab);
  return 0;
}
