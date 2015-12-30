#include <stdio.h>
#include <stdlib.h>


typedef struct cellule {
  int valeur;
  struct cellule *suivant;
} cellule;

typedef cellule Liste;

void affiche(Liste *l);
Liste* supprime_valeur(Liste *l, int x);
