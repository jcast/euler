#include <stdio.h>

int main(int argc, int *argv) {

  long start = 999999;

  long longest_num   = 0;
  int  longest_count = 0;


  long n; for(n = start; n > 0; n--) {
    long num  = n;
    int count = 0;

    while(num > 1) {
      if(num % 2 == 0) {
        num /= 2;
      } else {
        num = num * 3 + 1;
      }

      count++;
    }

    if(count > longest_count) {
      longest_num   = n;
      longest_count = count;
    }
  }


  printf("%ld\n", longest_num);

  return 0;
}
