#include <stdio.h>

int main(int argc, char *argv[]) {

  int sum  = 0;
  int a    = 0;
  int b    = 1;
  int temp = b;

  while(b <= 4000000){
    if(b % 2 == 0) sum += b;
    temp = b;
    b += a;

    a = temp;
  } 

  printf("%d\n", sum);
  return 0;
}
