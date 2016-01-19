#include "polynome.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

Node* new_node(float coef, unsigned deg) {
  assert(coef != 0 || deg == 0);
  Node* new = malloc(sizeof(Node));
  if(!new) return NULL;
  new->coef = coef;
  new->deg = deg;
  new->next = NULL;
  return new;
}

Node* delete_node(Node* node) {
  assert(node);
  Node* next = node->next;
  free(node);
  return next;
}

void print_polynome(Polynome* polynome) {
  assert(polynome);
  Node* n;
  for(n = (Node*) polynome; n; n = n->next) {
    if(n != polynome)
      printf("+ ");
    printf("%gx^%u ", n->coef, n->deg);
  }
  printf("\n");
}

void* delete_polynome(Polynome* polynome) {
  if(!polynome) return NULL;
  Node* n;
  for(n = (Node*)polynome; n; n = delete_node(n));
  return NULL;
}

Polynome* new_polynome_from_array(float* tab, unsigned n) {
  Polynome* polynome;
  Node* prev= NULL;
  int i;
  for(i=0; i<n; i++) {
    if(tab[i] || !i) {
      Node* new = new_node(tab[i], i);
      if(!new) return (Polynome*)delete_polynome(polynome);
      if(prev == NULL)
        polynome = new;
      else
        prev->next = new;
      prev = new;
    }
  }
  return polynome;
}

Polynome* derivate_polynome(Polynome* polynome) {
  assert(polynome);
  Node *n, *prev = NULL;
  Polynome* ans;
  int has_zero = FALSE;
  for(n = (Polynome*)polynome; n; n = n->next) {
    float coef;
    unsigned deg;
    if(n->deg == 0) {
      deg = 0;
      coef = 0;
    }
    else {
      deg = n->deg-1;
      coef = n->coef * n->deg;
    }
    if((coef != 0 && deg != 0) || !has_zero) {
      if(coef == 0 && deg == 0)
        has_zero = TRUE;
      Node* new = new_node(coef, deg);
      if(!new) return (Polynome*)delete_polynome(ans);
      if(!prev)
        ans = new;
      else
        prev->next = new;
      prev = new;
    }
  }
  return ans;
}


Polynome* sum_polynome(Polynome* p1, Polynome* p2) {
  assert(p1 && p2);
  Node *n1, *n2, *prev = NULL;
  Polynome* ans;
  n1 = (Node*)p1;
  n2 = (Node*)p2;
  int has_zero = FALSE;
  while(n1 || n2) {
    float coef = 0;
    unsigned deg = 0;
    if((n1 && n2 && n1->deg < n2->deg) || !n2) {
      coef = n1->coef;
      deg = n1->deg;
      n1 = n1->next;
    }
    else if((n1 && n2 && n1->deg > n2->deg) || !n1) {
      coef = n2->coef;
      deg = n2->deg;
      n2 = n2->next;
    }
    else if(n1 && n2 && n1->deg == n2->deg) {
      coef = n2->coef + n1->coef;
      deg = n1->deg;
      n1 = n1->next;
      n2 = n2->next;
    }
    if((coef != 0 && deg != 0) || !has_zero) {
      if(coef == 0 && deg == 0)
        has_zero = TRUE;
      Node* new = new_node(coef, deg);
      if(!new) return (Polynome*)delete_polynome(ans);
      if(!prev)
        ans = new;
      else
        prev->next = new;
      prev = new;
    }
  }
  return ans;
}

int save_polynome(Polynome* polynome, char* filename) {
  assert(polynome);
  FILE* fp = fopen(filename, "w");
  if(!fp) return -1;
  Node* n;
  for(n = (Node*) polynome; n; n = n->next) {
    if(n != polynome)
      fprintf(fp, "+ ");
    fprintf(fp, "%fx^%u ", n->coef, n->deg);
  }
  fprintf(fp, "\n");
  fclose(fp);
  return 1;
}
