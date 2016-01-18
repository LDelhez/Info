
#include <stdio.h>
#include <stdlib.h>


int longueur_prefixe_suffixe(int *t, int n){
  int i, k, contient;

  k = n-1;
  contient = 0;

  while(k>0 && !contient){
    k--;
    contient = 1;
    for(i=0; i<k; i++)
	if(t[i]!=t[n-k+i])
	  contient = 0;
  }//fin while()
  return k;
}//fin longueur_prefixe_suffixe()
