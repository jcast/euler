#include <stdio.h>

#define MX 50
#define MY 100

void load_matrix(char *filename, int matrix[MY][MX]) {
  FILE *file = fopen(filename, "r");

  int cx = 0;
  int cy = 0;

  int c; while(c != EOF) {
    if( fscanf(file, "%d", &(matrix[cy][cx])) > 0 ) {
      c = fgetc(file);
      cx++;
      if(c == '\n') {
        cy++;
        cx = 0;
      }
    } else {
      break;
    }
  }

  fclose(file);
}


char * matrix_addition(int matrix[MY][MX]) {
  char *num_str;

  return num_str;
}


int main(int argc, int *argv[]) {
  int matrix[MY][MX];

  return 0;
}
