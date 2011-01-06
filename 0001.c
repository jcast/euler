#include <stdio.h>

int main(int argc, char *argv[]) {

  int sum = 0;
  int i;

  for(i = 3; i < 1000; i++) {
    if(i % 3 == 0 || i % 5 == 0) sum += i;
  }

  printf("Sum: %d\n", sum);
  return 0;
}
