#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
  int square_of_sums = 0;
  int sum_of_squares = 0;

  int i; for(i=1; i<=100; i++){
    square_of_sums += i;
    sum_of_squares += pow(i, 2);
  }

  square_of_sums = pow(square_of_sums, 2);

  printf("%d\n", square_of_sums - sum_of_squares);
  return 0;
}
