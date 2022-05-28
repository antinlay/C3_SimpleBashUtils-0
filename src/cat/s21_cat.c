#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cat {
  int b;
  int e;
  int s;
  int t;
  int n;
  int v;
  int sumStr;
  FILE *file;
} p;

void init();
void s21_options(char arg);
int s21_file_read(char *argv[], size_t count);

int main(int argc, char *argv[]) {
  size_t ok = 0;
  init();
  if (argc > 1) {
    size_t count = 1, i = 0;
    while (count < (size_t)argc) {
      if (argv[count][i] == '-') {
        for (i = 0; argv[count][i] && argv[count][i] != ' '; i++) {
          char arg = argv[count][i];
          s21_options(arg);
        }
      } else {
        if (p.b) p.n = 0;
        ok = s21_file_read(argv, count);
      }
      count++;
    }
  } else {
  }
  return ok;
}

void init() {
  p.b = 0;
  p.e = 0;
  p.s = 0;
  p.t = 0;
  p.n = 0;
  p.v = 0;
  p.file = NULL;
}

void s21_options(char arg) {
  switch (arg) {
    case 'b':
      p.b = 1;
      break;
    case 'e':
      p.e = 1;
      p.v = 1;
      break;
    case 'E':
      p.e = 1;
      break;
    case 's':
      p.s = 1;
      break;
    case 't':
      p.t = 1;
      p.v = 1;
      break;
    case 'T':
      p.t = 1;
      break;
    case 'n':
      p.n = 1;
      break;
    case 'v':
      p.v = 1;
      break;
    default:
      break;
  }
}

int s21_file_read(char *argv[], size_t count) {
  p.file = fopen(argv[count], "r");
  int ok = 0, countStr = 1;
#ifdef __linux__
  if (count > 2) countStr = p.sumStr;
#endif
  char outputChar = '\0';
  char lastChar = '\n';
  if (p.file != NULL) {
    while ((outputChar = fgetc(p.file)) != EOF) {
      if (p.s && outputChar == '\n' && lastChar == '\n') {
        countStr++;
        char last = lastChar;
        if (countStr > 1) {
          while ((outputChar = fgetc(p.file)) == '\n' && last == '\n') {
            last = outputChar;
            continue;
          }
          if (p.b) --countStr;
          if (p.n) printf("%6d\t", countStr - 1);
          if (p.e) printf("$");
          printf("\n");
        } else {
          countStr = 0;
#ifdef __linux__
          if (count > 2) countStr = p.sumStr;
#endif
        }
      }
      if (lastChar == '\n' && ((p.b && outputChar != '\n') || p.n)) {
        printf("%6d\t", countStr++);
      }
      if (p.t && outputChar == '\t') {
        printf("^");
        outputChar = 'I';
      }
      if (p.e && outputChar == '\n') {
        printf("$");
      }
      if (p.v) {
        if ((outputChar >= 0 && outputChar < 9) ||
            (outputChar > 10 && outputChar < 32)) {
          printf("^");
          outputChar += 64;
        }
        if (outputChar == 127) {
          printf("^?");
          lastChar = outputChar;
          continue;
        }
      }
      printf("%c", outputChar);
      lastChar = outputChar;
    }
    p.sumStr = countStr;
    fclose(p.file);
  } else {
    fprintf(stderr, "cat: %s: No such file or directory\n", argv[count]);
    ok = -1;
  }
  return ok;
}
