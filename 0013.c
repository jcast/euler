#include <stdio.h>
#include <string.h>

#define MX 50
#define MY 100

void load_matrix(char *filename, int matrix[MY][MX]) {
  FILE *file = fopen(filename, "r");

  int cx = 0;
  int cy = 0;

  int c; while(c != EOF) {
    if( fscanf(file, "%1d", &(matrix[cy][cx])) > 0 ) {
      c = fgetc(file);
      cx++;
      if(c == '\n') {
        cy++;
        cx = 0;
      } else {
        ungetc(c, file);
      }
    } else {
      break;
    }
  }

  fclose(file);
}


char *matrix_addition(int matrix[MY][MX]) {
  char *nums;
  int sum;

  int x; for(x = MX-1; x >= 0; x--) {
    int y; for(y = 0; y < MY; y++) {
      sum += matrix[y][x];
    }

    sum = prepend_int(nums, sum, 1);
  }

  prepend_int(nums, sum, 0);

  return nums;
}


int prepend_int(char *str, int num, int last_digit) {
  char buf[sizeof(int) * 70];

  if(last_digit) {
    sprintf(buf, "%d%s", num % 10, str);
    num /= 10;

  } else {
    sprintf(buf, "%d%s", num, str);
    num = 0;
  }

  strcpy(str, buf);
  return num;
}


int main(int argc, int *argv[]) {
  int matrix[MY][MX];

  load_matrix("0013.txt", matrix);
  printf("%0.10s\n", matrix_addition(matrix));
  
  return 0;
}
