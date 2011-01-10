#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_palendrome(int num) {
  char num_str[7];
  int len = sprintf( num_str, "%d", num );

  int i; for(i = 0; i <= (len / 2); i++) {
    if(num_str[i] != num_str[len - i - 1]) return 0;
  }

  return 1;
}


int main(int argc, char *argv[]) {
  int largest = 0;

  int x; for(x = 999; x > 99; x--) {
    int y; for(y = x; y > 99; y--) {
      int prod = x * y;
      if(prod > largest && is_palendrome(prod)) {
        largest = prod;
      }
    }
  }

  printf("%d\n", largest);
  return 0;
}

