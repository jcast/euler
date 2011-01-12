#include <stdio.h>
#include <stdlib.h>

#define MX 20
#define MY 20

void pop_matrix(int matrix[MY][MX]) {
  char *filename = "0011.txt";
  FILE *file     = fopen(filename, "r");

  int cx = 0;
  int cy = 0;
  char buff[3];
  buff[2] = 0;

  int i = 0;
  int c; while(c != EOF) {
    c = fgetc(file);

    if(c == ' ') {
      matrix[cy][cx] = atoi(buff);
      //printf("%d\n", matrix[cy][cx]);
      cx++;
      i = 0;

    } else if(c == '\n') {
      matrix[cy][cx] = atoi(buff);
      //printf("%d\n", matrix[cy][cx]);
      cy++;
      cx = 0;
      i  = 0;

    } else {
      buff[i] = c;
      i++;
    }
  }

  fclose(file);
}

int main(int argc, char *argv[]) {
  int matrix[MY][MX];

  pop_matrix(matrix);
  return 0;
}
