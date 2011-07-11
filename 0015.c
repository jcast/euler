#include <stdio.h>

#define SIZE 20

/*
Observation for n=1 to n=5

col  1    2    3    4    5    6

n=1: 2    2
n=2: 2    4    6
n=3: 2    6   12   20
n=4: 2    8   20   40   70
n=5: 2   10   30   70  140  252

From the above table we can infer the following formulas
for any value of n:

* let Fn be the number of paths for a given square
* let FnCx be the value of a column of the square n

FnCx = SUM(F(n-1)C1..F(n-1)Cx)
Fn   = SUM(FnC1..FnCn)
*/

int main(int argc, int *argv) {

  long a1[SIZE+1], a2[SIZE+1];
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
