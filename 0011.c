#include <stdio.h>
#include <stdlib.h>

#define MX 20
#define MY 20

void load_matrix(char *filename, int matrix[MY][MX]) {
  FILE *file = fopen(filename, "r");

  int cx = 0;
  int cy = 0;

  int c; while(c != EOF) {
    if( fscanf(file, "%2d", &(matrix[cy][cx])) > 0 ) {
      //printf("coord: x=%d", cx);
      //printf(" y=%d\n", cy);
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


// Calculate the product for a matrix in a given direction.

int matrix_product(int x, int y, int len, int dir, int matrix[MY][MX]) {
  int product = 1;
  int i;

  for(i = 0; i < len; i++) {

    switch(dir) {
    // vertical down
    case 0:
      if(y+len > MY) return 0;
      product = product * matrix[y+i][x];
      break;

    // horizontal forward
    case 1:
      if(x+len > MX) return 0;
      product = product * matrix[y][x+i];
      break;

    // diagonal up
    case 2:
      if(x < len-1 || y+len > MY) return 0;
      product = product * matrix[y+i][x-i];
      break;

    // diagonal down
    case 3:
      if(x+len > MX || y+len > MY) return 0;
      product = product * matrix[y+i][x+i];
      break;
    }
  }

  return product;
}


int highest_product(int len, int matrix[MY][MX]) {
  int highest = 0;
  int product;

  int y; for(y = 0; y < MY; y++) {
    int x; for(x = 0; x < MX; x++) {
      int dir; for(dir = 0; dir < 4; dir++) {

        product = matrix_product(x, y, len, dir, matrix);
        if(product > highest) highest = product;
      }
    }
  }

  return highest;
}


int main(int argc, char *argv[]) {
  int matrix[MY][MX];
  int prod_size = 4;

  load_matrix("0011.txt", matrix);
  printf("%d\n", highest_product(prod_size, matrix));

  return 0;
}
