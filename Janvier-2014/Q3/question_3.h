#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <assert.h>

typedef struct {
  unsigned short jour;
  unsigned short mois;
  unsigned short annee;
}date;

typedef struct {
  float latitude;
  float longitude;
}localisation;

/*
 *  Question 3.A
 *  Structure de données : mesures
 */
typedef struct {
  date m_date;
  float q_pluie;
  float vitesse_vent;
  float temperature;
}mesures;

typedef struct {
  char* nom;
  localisation loc_station;
  int nb_mesures;
  mesures* tab_mesures;
}station;



station *cree_station(char *nom, float latitude, float longitude, int nb_mesures);

void affiche_mesures(mesures *tab, int nb_mesures);

int charge_station(station* s, char *fichier);

void statistique_temperature(station* s, unsigned short mois, float *moy_temp, float *max_temp, float* min_temp);

int nb_jour_fort_vent(station *s, float vent);
