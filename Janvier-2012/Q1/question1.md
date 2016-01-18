#Question 1

## 1.
```
#include <stdio.h>

typedef struct de_t{
	int faces;
	char** etiquettes;
} De;

int main() {
	int a, b = 8, c = b;
	a = c && b = c; // 1.
	De d[10];
  if(a || b || c){
    a = 0;
    b++;
    for(; a =< b;){ // 2.
      d.faces[a] = 3; // 3.
      a++;
    }
  }
  return -1;
}
```

Il y a trois erreurs de syntaxe.

1.  L'opérateur `&&` a une plus grande priorité que l'opérateur `=`. La ligne correspond donc à `a = (c && b) = c`. Cela ne compile pas car `(c && b)` n'est pas une valeur à gauche (_lvalue_).

2. L'opérateur `=<` n'existe pas. Il devrait être remplacé par `<=`.
3. Le type de `d` est `De*` (ou `struct de_t*`). L'operateur `.` (_point_) ne s'applique pas aux pointeurs et tableaux, il s'applique uniquement aux structures.  

##2.

**Pas vu cette année.**

_Pour votre culture, _
En complément à 2 sur 8 bits, `10000000` correspond au nombre `0`.

##3.
```c
int *a, *n;
init(&a, *n);
```
* `a` est de type `int*`, donc `&a` est de type `int**`
* `n` est de type `int*`, donc `*n` est de type `int`

Le prototype de la fonction `init` est donc :

```c
	T init(int** a, int n); // T est n'importe quel type
```

##4.
```c
int a=0, b=0, *c=&a, *d=&b, **e=&c, *f=*e;
++**e;
*e = d;
d = f;
printf("%d; ", (*d)--+*c);
printf("%d\n", (*f)||**e);
```


| - | a | b | c | d | e | f |
|--|----|---|---|---|----|---|
|   | 0 | 0 | &a| &b | &c | &a |
|   | 1 | 0 | &a| &b | &c | &a |
|   | 1 | 0 | &b| &b | &c | &a |
|   | 1 | 0 | &b| &a | &c | &a |
| Printf |  |   |    |    |    |
|   | 0 | 0 | &b| &a | &c | &a |
| Printf |  |   |    |    |    |

Le code affiche :

	1; 0

##5.
```c
int nombre = 8;
int *p1 = &nombre;
int **p2 = &p1;
```

Le résultat de `printf("%d", p2)` est l'adresse de `p1`.
