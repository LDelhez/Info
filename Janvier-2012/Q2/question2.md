#Question 2
```c
/*
 * @pre: n > 0, n pair, tab initialisé avec des entiers positifs
 * @post: profondeur du contour dont la somme des éléments est maximale
 */
 int profondeurSommeMax(int **tab, int n) {
	 int p_max, som_max = -1;
	 int p, som, k;
	 for(p=0; p < n/2;p++) { // (1)
		 som = 0;
		 for(k=0; k<n-1-2*p; k++) // (2)
			 som += tab[p+k][p] + tab[n-1-p][p+k] + tab[n-1-p-k][n-1-p] + tab[p][n-1-p-k];

		 if(som > som_max) {
			 som_max = som;
			 p_max = p;
		 }
	  } // fin for - p
	return p_max;
 } // fin profondeurSommeMax()
```

##2.A

Sp 1 : Calculer la profondeur avec la plus grande somme (calculer toutes les sommes)
Sp 2 : Calculer la somme `som` de la profondeur `p`
Sp 3 : Ajouter a `som` la valeur de chaque case du cadre de profondeur `p`

Boucles :

1. Énumère tous les cadres et calcule leur somme pour trouver la somme maximale
2. Énumère les case d'un cadre à la profondeur `p` et additionne les valeurs des cases

##2.B
Invariant de la boucle (2).

/|0 |... | p | p+1 | ... |p+k-1 |p+k|p+k+1|...|n-2-p-k|n-1-p-k|n-p-k|...|n-1-p| ... | n-1
- | -
0|/ |...| /|/|...|/|/|/|...|/|/|/|...|/|...|/
...|/ |...| ...|...|...|...|...|...|...|...|...|...|...|...|...|/
p|/ |...| x|o|...|o|o|o|...|o|o|x|...|x|...|/
p+1|/ |...| x|/|...|...|...|...|...|...|...|...|...|o|...|/
...|/ |...| ...|...|...|...|...|...|...|...|...|...|...|...|...|/
p+k-1|/ |...| x|/|...|...|...|...|...|...|...|...|...|o|...|/
p+k|/ |...| o|/|...|...|...|...|...|...|...|...|...|o|...|/
p+k+1|/ |...| o|/|...|...|...|...|...|...|...|...|...|o|...|/
...|/ |...| ...|...|...|...|...|...|...|...|...|...|...|...|...|/
n-2-p-k|/ |...| o|/|...|...|...|...|...|...|...|...|...|o|...|/
n-1-p-k|/ |...| o|/|...|...|...|...|...|...|...|...|...|o|...|/
n-p-k|/ |...| o|/|...|...|...|...|...|...|...|...|...|x|...|/
...|/ |...| ...|...|...|...|...|...|...|...|...|...|...|...|...|/
n-1-p|/ |...| x|x|...|x|o|o|...|o|o|o|...|x|...|/
...|/ |...| ...|...|...|...|...|...|...|...|...|...|...|...|...|/
n-1|/ |...| /|/|...|/|/|/|...|/|/|/|...|/|...|/

`som` contient la somme des valeurs des cases marquées d'un `x`.
Il faut encore calculer la somme des valeurs des cases marquées d'un `o`.

##2.C

L'existence d'un invariant pour une boucle ne suffit pas à garantir qu'elle soit correcte.

* Le code peut ne pas compiler.
* L'invariant n'est pas celui qui résout le problème posé.
* ...

Tout dépend de ce qu'on entend par **_boucle correcte_**.
