#include "question_2.h"


/*
 *  Swap échange les éléments a et b du tableau t
 */
void swap(int *t, int a, int b) {
  int tmp = t[a];
  t[a] = t[b];
  t[b] = tmp;
}

/*
 *  Question 2.A
 *    @pre:
 *        t est un tableau initialisé de n entiers
 *    @post:
 *        t est trié avec la valeur pivot x
 *
 */

/*  Invariant
 *    t: | | ... | | | ... | | | ... | |
 *       0      i-1 i       j j+1      n-1 n
 *       Les cases [0,i-1] sont < x.
 *       Les cases [j+1,n-1] sont >= x.
 */


 void trie_tableau(int *t, int n, int x) {
   int i = 0; // indice à 'gauche'
   int j = n-1; // indice à 'droite'
   while(i<j) { // on boucle jusqu'à ce que le tableau soit OK (voir Invariant)
     if(t[i] >= x) { // si la valeur en i est mauvaise
       if(t[j] < x) { // si la valeur en j est aussi mauvaise
         swap(t,i,j); // on échange les valeurs en i et j
         i++; // on reduit l'espace de travail (voir Invariant)
         j--; // on reduit l'espace de travail (voir Invariant)
       }
       else // sinon, si la valeur en j est bonne
         j--; // on reduit l'espace de travail (voir Invariant)
     }
     else // sinon, si la valeur en i est bonne
       i++; // on réduit l'espace de travail
   }
 }
