
#include <stdio.h>
#include <stdlib.h>

int longueur_prefixe_suffixe(int *t, int n) {
  int i;
  int prev = -1;
  /*
   * Invariant:
   * prev contient la longueur de la plus grande sous-chaine préfixe/suffixe de t[0..i-1]
   */
  for (i=1;i<n;i++){ 
    if (prev <= 0 && t[0] == t[i])
      prev = 1;
    else if (prev >= 1 && t[prev] == t[i])
      prev++;
    else
      prev = 0;
  }
  return prev;
}
