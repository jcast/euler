#include <stdio.h>
#include <stdlib.h>
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


int* new_prime_list(int num){
  int *prime_list = malloc(sizeof(int) * (num+1));

  int i;for(i = 0; i <= num; i++){
    prime_list[i] = 0;
  }

  return prime_list;
}


void print_primes(int *list, int len) {
  int i; for(i = 0; i <= len; i++) {
    printf("%d ^ %d\n", i, list[i]);
  }
}


int* primes(int num) {
  int *output = new_prime_list(num);
  int curr = num;
  int prime;

  while(curr > 1) {
    prime = largest_prime(curr);
    output[prime]++;
    curr = curr / prime;
  }

  return output;
}


void merge_lists(int *list, int *new_list, int len) {
  int i; for(i=0; i<len; i++){
    if(list[i] < new_list[i]) {
      list[i] = new_list[i];
    }
  }
}


int main(int argc, char *argv[]) {
  int max_num = 20;
  int* prime_list = new_prime_list(max_num);
  int i;

  for(i = 2; i <= max_num; i++){
    int* new_list = primes(i);
    merge_lists(prime_list, new_list, i+1);
    free(new_list);
  }

  printf("Primes:\n");
  print_primes(prime_list, max_num);

  double product = 1;
  for(i = 2; i <= max_num; i++){
    product = product * pow(i, prime_list[i]);
  }

  free(prime_list);

  printf("\nResult: %0.f\n", product);
  return 0;
}
