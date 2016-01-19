#include <stdio.h>
#include "polynome.h"

int main() {

  const unsigned N = 6;
  float tab[] = {0,1,2,3,0,5};

  Polynome* p = new_polynome_from_array(tab, N);
  print_polynome(p);

  Polynome* derivate = derivate_polynome(p);
  print_polynome(derivate);

  Polynome* sum = sum_polynome(p, derivate);
  print_polynome(sum);

  return 0;
}
