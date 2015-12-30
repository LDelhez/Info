#include <stdio.h>
#include <stdlib.h>
#include "question_2.h"

void afficher_tab(int* t, int n){
  int i = 0;
  for (;i<n;i++)
    printf("%d ", t[i]);
  printf("\n");
}

int main() {
  int t[10] = {5,6,5,4,0,-89,-56,100,3,2};
  afficher_tab(t, 10);
  trie_tableau(t, 10 ,2);
  afficher_tab(t, 10);
}
