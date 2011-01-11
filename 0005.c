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


int *primes(int num) {
  int output[4];
  int curr = num;
  int prime = 1;

  int i = 0; while(curr != prime && curr != 1) {
    prime = largest_prime(curr);
    curr = curr / prime;
    printf("%d\n", prime);
    output[i] = prime;
    i++;
  }

  return output;
}


int main(int argc, char *argv[]) {
  int *output = primes(20);

  printf("%d  %d  %d  %d\n", output[0], output[1], output[2], output[3]);
  return 0;
}

