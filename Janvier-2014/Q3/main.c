#include <stdio.h>
#include "question_3.h"

/*
 * Question 3.G
 */
int main(){
    station *station_uccle;
    float moyenne, min_temp, max_temp;
    int x;

    //1. Création de la station Uccle située à (50.48, 4.20) pour 30 mesures
    station_uccle = cree_station("Uccle", 50.48, 4.20, 30);
    if(station_uccle==NULL)
        return -1;

    //2. charger les mesures pour station_uccle depuis le fichier appelé "uccle_mesures.txt"
    x = charge_station(station_uccle, "uccle_mesures.txt");
    if(x==-1){
        return -1;
    }

    //3. affiche les mesures chargées
    affiche_mesures(station_uccle->tab_mesures, 30);

    //4. afficher, à l'écran, le nombre de jours où le vent était supérieur à 35.2
    printf("Le nombre de jours de fort vent (>35.2): %d\n", nb_jour_fort_vent(station_uccle, 35.2));

    //5. afficher les statistiques de température (moyenne, min, max) pour le mois de septembre.
    statistique_temperature(station_uccle, 9, &min_temp, &max_temp, &moyenne);
    printf("Statistique de température: \n");
    printf("\tTempérature moyenne: %f\n", moyenne);
    printf("\tTempérature min.: %f\n", min_temp);
    printf("\tTempérature max.: %f\n", max_temp);

    return 1;
}//fin programme()
