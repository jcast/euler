#include <stdio.h>

#define SIZE 20

/*
Cn-4 = Fn-1 - 4(Fn-2)
Cn-3 = Fn-1 - 3(Fn-2)
Cn-2 = Fn-1 - 2(Fn-2)
Cn-1 = Fn-1
Cn   = 2(Fn-1)
*/

int main(int argc, int *argv) {

  long a1[SIZE], a2[SIZE];
  long *pre = a1, *arr = a2, *tmp;

  long value;

  arr[0] = 2;
  arr[1] = 2;

  int n; for(n=2; n<=SIZE; n++) {

    tmp = pre;
    pre = arr;
    arr = tmp;

    arr[n] = 0;
    value  = 0;

    int i; for(i=0; i<n; i++) {
      value += pre[i];

      arr[i]  = value;
      arr[n] += value;
    }

    printf("n=%d: %ld\n", n, arr[n]);
  }

  printf("%ld\n", arr[SIZE]);

  return 0;
}
