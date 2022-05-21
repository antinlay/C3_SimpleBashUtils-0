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

int main(int argc, char *argv[]) {
  size_t ok = 0;
  if (argc > 1) {
    size_t count = 1, i = 0;
    while (count < (size_t)argc) {
      // i = 0;
      if (argv[count][i] == '-') {
        for (i = 0; argv[count][i] && argv[count][i] != ' '; i++) {
          switch (argv[count][i]) {
            case 'b':
              p.OPTION_B = 1;
              // argv[count] = "";
              break;
            case 'e':
              p.OPTION_E = 1;
              // argv[count] = "";
              break;
            case 's':
              p.OPTION_S = 1;
              // argv[count] = "";
              break;
            case 't':
              p.OPTION_T = 1;
              // argv[count] = "";
              break;
            case 'n':
              p.OPTION_N = 1;
              // argv[count] = "";
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
          if (p.OPTION_N == 1 && p.OPTION_B != 1) printf("%6lu\t", n++);
          if (p.OPTION_B == 1) {
            if ((outputChar = fgetc(p.p)) == '\n') printf("\n");
            printf("%6lu\t", n++);
          }
          if (p.OPTION_S == 1) printf("%c", outputChar);
          while ((outputChar = fgetc(p.p)) != EOF) {
            if (p.OPTION_N == 1 || p.OPTION_T == 1 || p.OPTION_B == 1 ||
                p.OPTION_S == 1 || p.OPTION_E == 1) {
              if (outputChar == '\n') {
                if (p.OPTION_E == 1 && p.OPTION_N != 1 && p.OPTION_B != 1)
                  printf("%c\n", '$');
                else if (p.OPTION_E == 1)
                  printf("%c", '$');
                if (p.OPTION_B == 1 || p.OPTION_S == 1) {
                  if (p.OPTION_S == 1) {
                    if ((outputChar = fgetc(p.p)) == '\n') {
                      printf("%c", outputChar);
                    }
                  }
                  while ((outputChar = fgetc(p.p)) == '\n') {
                    if (p.OPTION_B == 1) printf("%c", outputChar);
                  }
                  if (p.OPTION_S == 1) printf("\n%c", outputChar);
                }
                if (p.OPTION_N == 1 || p.OPTION_B == 1) printf("\n%6lu\t", n++);
                if (p.OPTION_T == 1) {
                  if (outputChar == '\t') {
                    printf("%c%c", '^', 'I');
                  }
                }
                // if (p.OPTION_S == 1) {
                //   if ((outputChar = fgetc(p.p)) == '\n') {
                // printf("%c", outputChar);
                // while (outputChar == '\n') {
                //   outputChar = fgetc(p.p);
                // }
                // printf("\n%c", outputChar);
                // } else {
                //   printf("\n%c", outputChar);
                //   }
                // }
                if (p.OPTION_N == 1 || p.OPTION_E == 1) continue;
              }
              printf("%c", outputChar);
            } else {
              printf("%c", outputChar);
            }

            // if (p.OPTION_T == 1) {
            //   if (outputChar == '\t') {
            //     printf("%c%c", '^', 'I');
            //     continue;
            //   }
            //   printf("%c", outputChar);
            // }

            // if (p.OPTION_S == 1) {
            //   printf("%c", outputChar);
            //   if (outputChar == '\n') {
            //     if ((outputChar = fgetc(p.p)) == '\n') {
            //       printf("%c", outputChar);
            //       while (outputChar == '\n') {
            //         outputChar = fgetc(p.p);
            //       }
            //       printf("%c", outputChar);
            //     } else {
            //       printf("%c", outputChar);
            //     }
            //   }
            // }
            // if (p.OPTION_E == 1) {
            //   if (outputChar == '\n') printf("%c", '$');
            //   printf("%c", outputChar);
            // }
            // else {
            //   printf("%c", outputChar);
            // }
          }
        }
        fclose(p.p);
        count++;
      }
    }
    return ok;
  }
}
