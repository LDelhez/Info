#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "question_4.h"

cellule *cree_cellule(int valeur){
    cellule *cell = malloc(sizeof(cellule));
    if(cell==NULL)
        return NULL;
    cell->valeur = valeur;
    return cell;
}

Liste *ajout_debut(Liste *l, int valeur){
    cellule *cell = cree_cellule(valeur);
    if(cell==NULL)
        return NULL;
    if(l!=NULL)
        cell->suivant = l;
    return cell;
}

Liste *cree_liste(){
    Liste *l = NULL;
    int i;

    for(i=0; i<20; i++){
        l = ajout_debut(l, rand()%10);
        if(l==NULL)
            return NULL;
    }
    return l;
}

int main() {
  Liste* l = cree_liste();
  affiche(l);
  l = supprime_valeur(l, 2);
  affiche(l);
  return 0;
}
