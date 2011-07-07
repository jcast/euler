#include <stdio.h>
#include <math.h>

int count_divs(long number) {
  int divs = 0;

  long n; for(n = 1; n <= number; n++){
    if(fmod(number, n) == 0) {
      if((number / n) < n) {
        return (divs * 2);
      } else if((number / n) == n) {
        return (divs * 2) - 1;
      }
      divs++;
    }
  }

  return divs;
}


int main(int argc, int *argv[]) {
  int min_div_count = 500;
  int div_count     = 0;
  long triangle     = 0;
  long min_number   = 1;
  long counter      = 0;

  while(div_count <= min_div_count) {
    counter++;
    triangle  = triangle + counter;
    div_count = count_divs(triangle);
  }

  printf("%ld\n", triangle);

  return 0;
}
