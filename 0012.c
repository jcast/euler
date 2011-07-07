#include <stdio.h>
#include <math.h>

int count_divs(long double number) {
  int divs = 0;

  long double n; for(n = 1; n < number; n++){
    if(fmod(number, n) == 0) {
      divs++;
      if(number / n < n) {
        return divs * 2;
      } else if(number / n == n) {
        return divs * 2 - 1;
      }
    }
  }

  return divs;
}


int main(int argc, int *argv[]) {
  int min_div_count = 500;
  int div_count     = 0;
  long double triangle      = 0;
  long double min_number    = 1;

  int n;

  for(n = 1; n <= min_div_count; n++) {
//printf("%Le\n", min_number);
    min_number = min_number * n;
  }


  for(n = 1; n <= min_number; n++); triangle += n;

  long double counter = min_number;

  while(div_count <= min_div_count) {
    counter++;
    triangle  = triangle + counter;
    div_count = count_divs(triangle);
    //printf("%d\n", div_count);
  }

  printf("%Le\n", triangle);

  return 0;
}
