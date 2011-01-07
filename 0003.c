#include <stdio.h>
#include <math.h>

int largest_prime(long num) {
  int i = floor(sqrt(num));
  int prime;
  int largest = 1;

  while(i > 1) {
    if(num % i == 0) {
      prime = largest_prime(i);
      if(prime > largest) largest = prime;
    }

    i--;
  }

  if(largest == 1) largest = num;

  return largest;
}

int main(int argc, char *argv[]) {
  printf("%d\n", largest_prime(600851475143));
  return 0;
}
