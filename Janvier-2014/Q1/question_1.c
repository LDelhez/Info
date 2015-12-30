#include <stdio.h>
#include <stdlib.h>

/*
 *  Que fait la fonction F ?
 *  F prend en paramètre deux entiers (x et y) dont le premier est passé par adresse.
 *  La valeur de x dans le code appelant sera donc modifiée.
 *
 *  Après l'éxécution :
 *    La valeur pointée par x vaudra (*x + y)
 *    La valeur de y sera (3*y+2*(*x)) mais cela n'influence pas le code appelant
 *    Ces deux valeurs sont affichées à l'écran
 *
 *  F retourne comme valeur (3*(*x) + 4*y)
 */
int F(int *x, int y) { // [!]: x est passé par adresse et y par valeur
  *x = y + *x;  // même chose que *x += y   càd. la valeur pointée par x est incrémentée de y
  y = y + 2* (*x);  // même chose que y += 2*(*x)   càd. y est incrémenté du double de la valeur pointée par x
  printf("(2) *x == %d, y=%d \n",*x, y); // affiche *x et y
  return (*x + y); // retourne la somme de la valeur pointée par x et de y
}

/*
 *  Que fait la fonction G ?
 *  G prend en paramètre deux entiers (x et y) dont le premier est passé par adresse-adresse.
 *  La valeur de x dans le code appelant sera donc modifiée.
 *
 *  Après l'éxécution :
 *    La valeur de y sera (y+(**x))
 *    La case mémoire pointée-pointée par x sera celle de y
 *  La fonction affiche deux lignes à l'écran:
 *    1) **x et (**x+y)
 *    2) (**x+y) et (**x+y)
 *
 *  G retourne comme valeur (2*(**x) + 2*y + 3)
 */
int G(int **x, int y) { // 34,9
  y = **x + y; // même chose que y += **x   càd. y est incrémenté de la valeur pointée-pointée par x
  printf("(4) **x == %d, y=%d \n",**x, y); // affiche **x et y
  *x = &y;  // La valeur pointée par x (qui est un pointeur) pointe maintenant vers y. Donc, la variable pointée-pointée par x est y
  printf("(5) **x == %d, y=%d \n",**x, y); // affiche **x et y
  return (**x + y + 3); // retourne la somme de la valeur pointée-pointée par x (c'est y), de y  et de 3
}

int main() {
  int v=2, t=5, *u; // v et t sont des entiers et u est un pointeur vers un entier
  u=&t; // u pointe vers t (ils sont liés)
  t=5; // Aucun effet car t vaut déjà 5
  *u=*u +v; // même chose que *u += v     càd. la valeur pointée par u (c'est t) est incrémentée de v (2)
  // ici on a : v = 2 et t = 7 et *u = 7
  printf("(1)  v= %d, t=%d, *u=%d \n", v, t, *u); // Affiche les valeurs de v,t et *u
  t=F(&v,t); // t prend la valeur de retour de la fonction F
  // ici on a : v = 2 + 7 = 9 et t = 3*2+4*7=34 et *u = 34
  printf("(3) v= %d, t=%d, *u=%d \n",v, t, *u); // Affiche les valeurs de v,t et *u
  *u=G(&u,v); // la valeur pointée par u (c'est t) prend la valeur de retour de la fonction G
  /*
   *  Le comportement ici est DOUBLEMENT INDÉTERMINÉ !
   *    (1) Ne JAMAIS placer à droite d'un signe d'affectation une expression qui modifie le terme de gauche de l'affectation
   *        - La fonction G modifie la valeur pointée par u, à laquelle elle assigne sa valeur de retour.
   *    (2) Ne JAMAIS accéder aux cases mémoires des autres blocs d'instructions
   *        - La fonction G modifie la valeur pointée par u qui pointe alors vers la variable y de la fonction G.
   *        - Or, on accède parfois (en fonction du comportement en (1)) à la valeur pointée par u dans le bloc de la fonction main().
   *        - Au cours, on a dit que les variables locales étaient créées sur un contexte et disparaissaient avec celui-ci.
   *          La réponse la plus normale (selon le cours) serait de dire que le programme provoque une 'segmentation fault'.
   */

  printf("(6) v= %d, t=%d, *u=%d \n", v, t, *u); // Affiche les valeurs de v,t et *u
}
