#include <stdio.h>
#include <string.h>

struct cat {
  int b;
  int e;
  int s;
  int t;
  int n;
  int v;
  FILE *p;
} p;

void init() {
  p.b = 0;
  p.e = 0;
  p.s = 0;
  p.t = 0;
  p.n = 0;
  p.v = 0;
  p.p = NULL;
}

void s21_options(char arg) {
  switch (arg) {
    case 'b':
      p.b = 1;
      break;
    case 'e':
      p.e = 1;
      break;
    case 's':
      p.s = 1;
      break;
    case 't':
      p.t = 1;
      break;
    case 'n':
      p.n = 1;
      break;
    default:
      break;
  }
}

void s21_toption(char outputChar) {
  if (outputChar == '\t') {
    printf("%c%c", '^', 'I');
  } else {
    printf("%c", outputChar);
  }
}

int main(int argc, char *argv[]) {
  size_t ok = 0;
  if (argc > 1) {
    size_t count = 1, i = 0;
    while (count < (size_t)argc) {
      // i = 0;
      if (argv[count][i] == '-') {
        for (i = 0; argv[count][i] && argv[count][i] != ' '; i++) {
          char arg = argv[count][i];
          s21_options(arg);
        }
        count++;
      } else {
        size_t n = 1;
        char outputChar = '\0';
        if ((p.p = fopen(argv[count], "r")) == NULL) {
          ok = 1;
        } else {
          if (p.n && p.b != 1) printf("%6lu\t", n++);
          if (p.b) {
            while ((outputChar = fgetc(p.p)) == '\n') {
              printf(p.e ? "$\n" : "\n");
            }
            if (outputChar != '\n') printf("%6lu\t", n++);
            printf("%c", outputChar);
          }
          if (p.s) {
            while ((outputChar = fgetc(p.p)) == '\n') {
              continue;
            }
            printf("\n%c", outputChar);
          }
          while ((outputChar = fgetc(p.p)) != EOF) {
            if (p.n || p.t || p.b || p.s || p.e) {
              if (outputChar == '\n') {
                if (p.e && !p.n && !p.b)
                  printf("$\n");
                else if (p.e)
                  printf("$");
                if (p.b || p.s) {
                  if (p.b) {
                    while ((outputChar = fgetc(p.p)) == '\n') {
                      printf("%c", outputChar);
                    }
                    // printf("%c", outputChar);
                  }
                  if (p.s) {
                    if ((outputChar = fgetc(p.p)) == '\n') {
                      printf("\n");
                      while ((outputChar = fgetc(p.p)) == '\n') {
                        continue;
                      }
                      printf("\n");
                    } else {
                      printf("\n");
                    }
                  }
                  if (p.s) printf("%c", outputChar);
                }
                if (p.n || p.b) printf("\n%6lu\t", n++);
                if (p.n || p.e) continue;
                if (p.t) printf("\n");
              } else if (p.t) {
                s21_toption(outputChar);
              } else if (!p.t) {
                printf("%c", outputChar);
              }
            } else {
              printf("%c", outputChar);
            }
          }
        }
        fclose(p.p);
        count++;
      }
    }
    return ok;
  }
}
