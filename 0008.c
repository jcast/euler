#include <stdio.h>

int get_digits(FILE *file, int *digits, int len) {
  int i; for(i=0; i < len; i++) {
    if(digits[i] == -1 || i == len - 1) {
      int c = -2;
      while(c == -2 || c == '\n') c = fgetc(file);
      if(c == EOF) return 0;
      digits[i] = atoi(&c);

    } else {
      digits[i] = digits[i + 1];
    }
  }

  return 1;
}


int main(int argc, char *argv[]) {
  char *filename   = "0008.txt";
  FILE *file       = fopen(filename, "r");
  int largest_prod = 0;
  int len          = 5;
  int digits[len];
  int j; for(j=0; j < len; j++) digits[j] = -1;

  while(get_digits(file, digits, len)) {
    int prod = 1;
    int i; for(i=0; i < len; i++) {
      prod = prod * digits[i];
      if(prod > largest_prod) largest_prod = prod;
    }
  }

  if(fclose(file)) printf("File %s did not close properly\n", filename);

  printf("%d\n", largest_prod);

  return 0;
}
