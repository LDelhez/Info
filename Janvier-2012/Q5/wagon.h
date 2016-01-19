


#define VOLUME_MAX_WAGON 100

typedef struct marchandise_t{
  double volume;
  char nom[26];
  struct marchandise_t *next; // [!]: Erreur dans le code du prof !
} marchandise;

marchandise* new_marchandise(double, char*, marchandise*);
unsigned length(char*);

typedef struct wagon wagon;
typedef struct wagon {
  wagon *next;
  marchandise *liste_marchandise;
  double volume_courant;
} train;

wagon* new_wagon(marchandise*, double, wagon*);

/*
 * @pre: {m} est une marchandise valdide, {w} est un wagon valide, {w} dispose
 *       de suffisamment de volume libre pour stocker {m}.
 * @post: la marchandise {m} est ajoutée au wagon {w} et le volume utilisé
 *        dans le wagon est augmenté en fonction du volume de {m}.
 *        Retourne -1 en cas d'erreur.
 */
 int ajout_marchandise(wagon *w, marchandise *m);

/*
 * @pre: {t} est un train valide, {m} est une marchandise valide, {nb_wagon_max} > 0,
 *       {nb_wagon} pointe sur un entier strictement positif.
 * @post: Ajoute {m} dans un wagon du train {t} ayant un volume suffisant,
 *        s'il y en a un, sinon dans un nouveau wagon ajouté en fin du train {t}.
 *        Retourne 1 si l'ajout a réussi.
 *        Si {m} dépasse la capacité d'un wagon vide ou si un nouveau wagon ne peut
 *        être ajouté, retourne -1 et le train {t} n'est pas modifié.
 */
 int ajout(int nb_wagon_max, int* nb_wagon, train *t, marchandise *m);
