#include <stdio.h>
#include <stdlib.h>

#define MX 20
#define MY 20

void load_matrix(char *filename, int matrix[][MY]) {
//  char *filename = "0011.txt";
  FILE *file     = fopen(filename, "r");

  int cx = 0;
  int cy = 0;

  int c; while(c != EOF) {
    if( fscanf(file, "%2d", &(matrix[cy][cx])) > 0 ) {
      printf("coord: x=%d", cx);
      printf(" y=%d\n", cy);
      c = fgetc(file);
      switch(c) {
      case ' ': cx++; break;
      case '\n': cy++; cx = 0; break;
      }
    } else {
      break;
    }
  }

  fclose(file);
}

int main(int argc, char *argv[]) {
  int matrix[MY][MX];

  load_matrix("0011.txt", matrix);
  return 0;
}
