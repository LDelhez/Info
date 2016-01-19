


typedef struct node Node;
struct node {
  unsigned deg;
  float coef;
  Node* next;
};

Node* new_node(float, unsigned);
Node* delete_node(Node*);


typedef Node Polynome;
void print_polynome(Polynome*);
void* delete_polynome(Polynome*);
Polynome* new_polynome_from_array(float*, unsigned);
Polynome* derivate_polynome(Polynome*);
Polynome* sum_polynome(Polynome*, Polynome*);
int save_polynome(Polynome*, char*);
