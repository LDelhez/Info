#include "wagon.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

unsigned length(char* str) {
  int i = 0;
  for(;str[i]!='\0';i++);
  return i;
}

marchandise* new_marchandise(double volume, char* nom, marchandise* next) {
  assert(volume >= 0);
  assert(nom);
  marchandise* new = malloc(sizeof(marchandise));
  if(!new) return NULL;
  new->volume = volume;

  unsigned l = length(nom);
  memcpy(new->nom, nom, l);

  new->next = next;
  return new;
}

wagon* new_wagon(marchandise* liste_marchandise, double volume_courant, wagon* next) {
  assert(volume_courant >= 0);
  wagon* new = malloc(sizeof(wagon));
  if(!new) return 0;
  new->liste_marchandise = liste_marchandise;
  new->next = next;
  return new;
}

int ajout_marchandise(wagon *w, marchandise *m) {
  assert(w && m && m->volume + w->volume_courant <= VOLUME_MAX_WAGON);
  w->volume_courant += m->volume;
  m->next = w->liste_marchandise;
  w->liste_marchandise = m;
  return 0;
}


// REPONSE QUESTION 5
/*
 *  Je considère ici qu'on ne peut pas déplacer des marchandises déjà placées.
 */
int ajout(int nb_wagon_max, int* nb_wagon, train *t, marchandise *m) {
  assert(nb_wagon_max > 0 && nb_wagon && *nb_wagon > 0);
  assert(t && m);

  if(m->volume > VOLUME_MAX_WAGON)
    return -1;

  wagon* p = (wagon*)t;
  wagon* prev = NULL;
  int count = 0;
  while(p) {
    count++;
    if(p->volume_courant + m->volume <= VOLUME_MAX_WAGON) {
      ajout_marchandise(p, m);
      return 1;
    }
    prev = p;
    p = p->next;
  }

  if(count >= nb_wagon_max)
    return -1;
  prev->next = new_wagon(NULL, 0, NULL); if(!prev->next) return -1;

  ajout_marchandise(prev->next, m);
  return 1;
}
