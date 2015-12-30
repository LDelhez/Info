#include "question_4.h"

/*
 *  Question 4.A
 */
void affiche(Liste *l) {
  printf("{ "); // Affiche le début
  while(l != NULL) {  // Tant qu'il y a qqch à afficher
    printf("%d ", l->valeur); // Affiche la valeur
    l = l->suivant; // On passe à la cellule suivante
  }
  printf("}\n"); // et on termine
}

/*
 *  Question 4.B
 */
Liste* supprime_valeur(Liste *l, int x) {
  Liste *p_cur = l; // p_cur parcourt la liste
  Liste *p_prec = NULL; // p_rec pointe toujours vers l'élément avant p_cur
  while(p_cur != NULL){ // Tant qu'il y a un élément après
    if(p_cur->valeur == x){ // Si la cellule courrante contient x (il faut la détruire)
      if(p_prec == NULL){ // [!]: Si on est sur la première cellule, c'est un cas particulier
        l = p_cur->suivant; // Le pointeur de tête pointe directement sur le deuxième élément
        free(p_cur);  // On détruit l'élément x
        p_cur = l; // Et on repart à partir du premier élément
      }else{ // Sinon, on n'est pas sur la première case
        p_prec->suivant = p_cur->suivant; // on passe directement de p_prec à p_cur->suivant sans passer par p_cur
        free(p_cur); // on détruit l'élément x
        p_cur = p_prec->suivant; // Et on repart à partir de l'élément juste après l'élément détruit
      }
    }else{ // Si la valeur de la cellule pointée par p n'est pas x
      p_prec = p_cur; // On avance dans la liste
      p_cur = p_cur->suivant; // On avance dans la liste
    }
  }
  return l; // on retoure le pointeur de tête
}
