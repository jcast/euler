#include <stdio.h>
#include <math.h>

int largest_prime(int num) {
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


int is_prime(long num) {
  if(num == largest_prime(num)) return 1;
  return 0;
}


int main(int argc, char *argv[]) {
  double sum=0;

  int i; for(i=2; i < 2000000; i++){
    if(is_prime(i)) sum += i;
  }

  printf("%0.f\n", sum);
  return 0;
}
