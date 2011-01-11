#include <stdio.h>
#include <math.h>

static int SUM = 1000;

int resolve_values(int a, int b, int *buff){
  int c = sqrt(pow(a,2) + pow(b,2));

  if(a + b + c != SUM || pow(c,2) != pow(a,2) + pow(b,2)) return 0;

  buff[0] = a;
  buff[1] = b;
  buff[2] = c;

  return 1;
}


int main(int argc, char *argv[]){
  int resp[3];

  int a; for(a=1; a < SUM/3; a++){
    int b; for(b = a+1; b < SUM - (a*2); b++){

      if(resolve_values(a, b, resp)){
        printf("%d, %d, %d\n", resp[0], resp[1], resp[2]);
        printf("%d\n", resp[0] * resp[1] * resp[2]);
        return 0;
      }
    }
  }

  return 1;
}
