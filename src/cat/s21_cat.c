#include <stdio.h>
#include <string.h>

struct cat {
  int OPTION_B;
  int OPTION_E;
  int OPTION_S;
  int OPTION_T;
  int OPTION_N;
  FILE *p;
} p;

void init() {
  p.OPTION_B = 0;
  p.OPTION_E = 0;
  p.OPTION_S = 0;
  p.OPTION_T = 0;
  p.OPTION_N = 0;
  p.p = NULL;
}

int main(int argc, char **argv) {
  size_t ok = 0;
  if (argc > 1) {
    size_t count = 1, i = 0;
    while (count < (size_t)argc) {
      if (argv[count][i] == '-') {
        for (i = 0; i < strlen(argv[count]); i++) {
          switch (argv[count][i]) {
            case 'b':
              p.OPTION_B = 1;
              argv[count] = "";
              break;
            case 'e':
              p.OPTION_E = 1;
              argv[count] = "";
              break;
            case 's':
              p.OPTION_S = 1;
              argv[count] = "";
              break;
            case 't':
              p.OPTION_T = 1;
              argv[count] = "";
              break;
            case 'n':
              p.OPTION_N = 1;
              argv[count] = "";
              break;
            default:
              break;
          }
        }
        count++;
      } else {
        size_t n = 1;
        char outputChar = '\0';
        if ((p.p = fopen(argv[count], "r")) == NULL) {
          ok = 1;
        } else {
          if (p.OPTION_N == 1) {
            printf("%6lu\t", n++);
            while ((outputChar = fgetc(p.p)) != EOF) {
              if (outputChar == '\n') {
                printf("\n%6lu\t", n++);
                continue;
              }
              printf("%c", outputChar);
            }
          } else if (p.OPTION_T == 1) {
            while ((outputChar = fgetc(p.p)) != EOF) {
              if (outputChar == '\t') {
                printf("%c%c", '^', 'I');
                continue;
              }
              printf("%c", outputChar);
            }
          } else if (p.OPTION_B == 1) {
            if ((outputChar = fgetc(p.p)) == '\n') printf("\n");
            printf("%6lu\t", n++);
            while ((outputChar = fgetc(p.p)) != EOF) {
              if (outputChar == '\n') {
                printf("\n");
                while ((outputChar = fgetc(p.p)) == '\n') {
                  printf("\n");
                }
                printf("%6lu\t", n++);
              }
              printf("%c", outputChar);
            }
          } else if (p.OPTION_S == 1) {
            while ((outputChar = fgetc(p.p)) != EOF) {
              printf("%c", outputChar);
              if (outputChar == '\n') {
                if ((outputChar = fgetc(p.p)) == '\n') {
                  printf("%c", outputChar);
                  while (outputChar == '\n') {
                    outputChar = fgetc(p.p);
                  }
                  printf("%c", outputChar);
                } else {
                  printf("%c", outputChar);
                }
              }
            }
          } else if (p.OPTION_E == 1) {
            while ((outputChar = fgetc(p.p)) != EOF) {
              if (outputChar == '\n') printf("%c", '$');
              printf("%c", outputChar);
            }
          } else {
            while ((outputChar = fgetc(p.p)) != EOF) {
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
