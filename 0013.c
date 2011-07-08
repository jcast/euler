#include <stdio.h>
#include <string.h>

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
  char *nums;

  int x; for(x = MX-1; x >= 0; x--) {
    int y; for(y = 0; y < MY; y++) {

      
    }
  }

  return nums;
}


int main(int argc, int *argv[]) {
  int matrix[MY][MX];
  char *out

  load_matrix("0013.txt", matrix);
  out = matrix_addition(matrix);

  //TODO: get first 10 chars
  printf(out);
  
  return 0;
}
