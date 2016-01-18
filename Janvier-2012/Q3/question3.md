#Question 3
##3.A Structure

Pour garantir l'unicité d'un compte en banque, on lui assigne un identifiant unique.
Le compte sera placé dans un tableau à l'indice correspondant à son identifiant unique.

```c
typedef struct compte {
	char* nom;
	double solde; // <- Banque pour milliardaires
} Compte;
```

##3.B Sous-problèmes
###SP1: Création d'un compte

```c
/*
 * @pre: tab est le tableau contenant l'ensemble des comptes
 *       id est l'indice d'une case du tableau existante et vide
 *       nom est une chaîne de caractères valide, initialisée
 * @post: la fonction retourne un pointeur vers le compte créé (avec le bon nom)
 *        le compte créé est placé dans le tableau tab à l'indice id
 */
Compte* new_compte(Compte** tab, unsigned id, char* nom);
```
###SP2: Suppression d'un compte
```c
/*
 * @pre: tab est le tableau contenant l'ensemble des comptes
 *       id est l'indice d'une case du tableau
 * @post: le compte à l'indice id est détruit
 */
void delete_compte(Compte** tab, unsigned id);
```
###SP3: Retrait d'argent
```c
/*
 * @pre: tab est le tableau contenant l'ensemble des comptes
 *        id est l'indice d'une case du tableau contenant un compte valide
 *        val est le montant à retirer >= 0
 * @post: la fonction retourne le montant réellement retiré
 */
unsigned get(Compte** tab, unsigned id, unsigned val);
```


###SP4: Versement d'argent
```c
/*
 * @pre: tab est le tableau contenant l'ensemble des comptes
 *        id est l'indice d'une case du tableau contenant un compte valide
 *        val est le montant à verser >= 0
 * @post: la fonction retourne le montant réellement versé
 */
unsigned put(Compte** tab, unsigned id, unsigned val);
```

###SP5: Virement
```c
/*
 * @pre: tab est le tableau contenant l'ensemble des comptes
 *        id1 et id2 sont les indices de deux cases du tableau contenant un compte valide
 *        val est le montant à virer >= 0
 * @post: la fonction retourne le montant réellement viré
 */
unsigned vire(Compte** tab, unsigned id1, unsigned id2, unsigned val);
```
