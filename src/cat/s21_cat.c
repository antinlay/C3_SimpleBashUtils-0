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

// void num_b(char **argv, size_t count) {
//   char strFile[BMAX] = "";
//   p.p = fopen(argv[count], "r");
//   while (fgets(strFile, BMAX, p.p) != NULL) {
//     size_t n = 0;
//     printf("%d\t%s", n++, strFile);
//   }
//   fclose(p.p);
// }

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
        p.p = fopen(argv[count], "r");
        size_t n = 1;
        char nextChar = '\0';
        char outputChar = '\0';
        // char strFile[BMAX] = "";
        if (nextChar == EOF) {
          ok = 1;
        } else {
          if (p.OPTION_N == 1 && p.p != NULL) {
            printf("%6lu\t", n++);
            while ((outputChar = getc(p.p)) != EOF) {
              if (outputChar == '\n') {
                printf("\n%6lu\t", n++);
                continue;
              }
              printf("%c", outputChar);
            }
          }
          if (p.OPTION_T == 1 && p.p != NULL) {
            while ((outputChar = getc(p.p)) != EOF) {
              if (outputChar == '\t') {
                printf("%c%c", '^', 'I');
                continue;
              }
              printf("%c", outputChar);
            }
          }
          if (p.OPTION_S == 1 && p.p != NULL) {
            // nextChar = getc(p.p);
            while ((outputChar = getc(p.p)) != EOF) {
              if (outputChar == '\n' && nextChar == '\n') {
                while (nextChar == '\n') {
                  nextChar = getc(p.p);
                  continue;
                }
                outputChar = nextChar;
              }
              printf("%c", outputChar);
            }
          }
          if (p.OPTION_E == 1 && p.p != NULL) {
            while ((outputChar = getc(p.p)) != EOF) {
              if (outputChar == '\n') printf("%c", '$');
              printf("%c", outputChar);
            }
          }
          if (p.OPTION_B + p.OPTION_E + p.OPTION_S + p.OPTION_T + p.OPTION_N ==
                  0 &&
              p.p != NULL) {
            while ((outputChar = getc(p.p)) != EOF) {
              printf("%c", outputChar);
            }
          }
          // while (fgets(strFile, BMAX, p.p) != NULL) {
          //   if (p.OPTION_B == 1 && p.p != NULL) {
          //     printf((*strFile != '\n') ? "%6lu\t%s" : "\n", n++, strFile);
          //   } else if (p.OPTION_N == 1 && p.p != NULL) {
          //     printf("%6lu\t%s", n++, strFile);
          //   } else if (p.OPTION_E == 1 && p.p != NULL) {
          //     printf("%6lu\t%s", n++, strFile);
          //   } else if (p.OPTION_B + p.OPTION_E + p.OPTION_S + p.OPTION_T +
          //   p.OPTION_N == 0
          //   &&
          //              p.p != NULL) {
          //     // printf("%s", strFile);
          //   }
          // }
          fclose(p.p);
          count++;
        }
      }
    }
    return ok;
  }
}
