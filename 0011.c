#include <stdio.h>

static int mx, my = 20;

void populate_matrix(int matrix[my][mx]) {
  char *filename = "0011.txt";
  FILE *file     = fopen(filename, "r");

  int cx, cy = 0;
  char buff[2];

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
  int matrix[my][mx];

  populate_matrix(matrix);
  return 0;
}
