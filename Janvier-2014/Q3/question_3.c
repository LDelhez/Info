#include "question_3.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <assert.h>


/*
 *  Question 3.B
 */
station *cree_station(char *nom, float latitude, float longitude, int nb_mesures) {
  assert(nb_mesures >= 0); // Programmation défensive
  assert(nom); // Programmation défensive

  station *s = malloc(sizeof(station)); // Allocation de la mémoire pour la station
  if(!s) return NULL; // Programmation défensive

  // Nom
  int length;
  for (length = 0;nom[length] != '\0'; length++) // Taille du nom -> length
  s->nom = malloc(length * sizeof(char)); // Allocation de la mémoire pour le nom
  if(!s->nom) return NULL; // Programmation défensive
  for (;length >= 0; length--)
    s->nom[length] = nom[length]; // On copie nom  dans s->nom

  // latitude et longitude
  s->loc_station.latitude = latitude;
  s->loc_station.longitude = longitude;

  // mesures
  s->nb_mesures = nb_mesures;
  s->tab_mesures = malloc(nb_mesures * sizeof(mesures)); // Allocation de la mémoire pour les mesures
  if(!s->tab_mesures) return NULL; // Programmation défensive

  return s;
}

/*
 *  Question 3.C
 */
void affiche_mesures(mesures *tab, int nb_mesures) {
  assert(tab);  // Programmation défensive
  assert(nb_mesures >= 0);  // Programmation défensive
  int i;
  for(i=0;i<nb_mesures;i++) {  // Affiche chaque mesure
    printf("%02hu/%02hu/%04hu - %f; %f; %f\n", tab[i].m_date.jour,
      tab[i].m_date.mois, tab[i].m_date.annee, tab[i].q_pluie, tab[i].vitesse_vent, tab[i].temperature);
  }
}

/*
 *  Question 3.D
 */
int charge_station(station* s, char *fichier) {
  assert(s); // Programmation défensive
  assert(fichier); // Programmation défensive
  FILE* fp = fopen(fichier, "r");
  if(!fp) return -1; // Programmation défensive
  int i;
  mesures* t = s->tab_mesures;
  for(i=0;i < s->nb_mesures && fscanf(fp,"%hd %hd %hd %f %f %f", &t[i].m_date.jour, &t[i].m_date.mois, &t[i].m_date.annee,
    &t[i].q_pluie, &t[i].vitesse_vent, &t[i].temperature);i++); // Lit dans le fichier les mesures
  fclose(fp); // Fermeture du fichier
  return 1;
}

/*
 *  Question 3.E
 */
void statistique_temperature(station* s, unsigned short mois, float *moy_temp, float *max_temp, float* min_temp) {
  assert(s && s->tab_mesures); // Programmation défensive
  assert(moy_temp && max_temp && min_temp); // Programmation défensive
  assert(1 <= mois && mois <= 12);  // Programmation défensive

  int i;
  *moy_temp = 0;
  *max_temp = FLT_MIN;
  *min_temp = FLT_MAX;
  for(i=0;i<s->nb_mesures;i++) { // Pour toutes les mesures ...
    if(s->tab_mesures[i].m_date.mois == mois){ // si la mesure correspond au mois
      float tmp = s->tab_mesures[i].temperature;
      *moy_temp += tmp; // on somme toutes les temperatures
      if(tmp > *max_temp)
        *max_temp = tmp; // on cherche la temperature max
      if(tmp < *min_temp)
        *min_temp = tmp; // on cherche la temperature min
    }
  }
  *moy_temp /= s->nb_mesures; // On calcule la moyenne des températures
}


/*
 *  Question 3.F
 */
int nb_jour_fort_vent(station *s, float vent) {
  assert(s && s->tab_mesures); // Programmation défensive
  int i;
  int count = 0;
  for(i=0;i<s->nb_mesures;i++) { // Pour toutes les mesures ...
    if(s->tab_mesures[i].vitesse_vent > vent) // si le vent est fort
      count++;
  }
  return count;
}
