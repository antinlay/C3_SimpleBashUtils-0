#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

#define BMAX 1000000
struct s21_cat {
  int OPT_B;
  int OPT_E;
  int OPT_S;
  int OPT_T;
  int OPT_N;
  FILE *p;
} p;

void s21_init() {
  p.OPT_B = 0;
  p.OPT_E = 0;
  p.OPT_S = 0;
  p.OPT_T = 0;
  p.OPT_N = 0;
  p.p = s21_NULL;
}

// void s21_num_b(char **argv, s21_size_t count) {
//   char strFile[BMAX] = "";
//   p.p = fopen(argv[count], "r");
//   while (fgets(strFile, BMAX, p.p) != s21_NULL) {
//     s21_size_t n = 0;
//     printf("%d\t%s", n++, strFile);
//   }
//   fclose(p.p);
// }

int main(int argc, char **argv) {
  s21_size_t ok = 0;
  if (argc > 1) {
    s21_size_t count = 1, i = 0;
    while (count != (s21_size_t)argc) {
      if (argv[count][i] == '-') {
        for (i = 0; i < s21_strlen(argv[count]); i++) {
          switch (argv[count][i]) {
            case 'b':
              p.OPT_B = 1;
              argv[count] = "";
              break;
            case 'e':
              p.OPT_E = 1;
              argv[count] = "";
              break;
            case 's':
              p.OPT_S = 1;
              argv[count] = "";
              break;
            case 't':
              p.OPT_T = 1;
              argv[count] = "";
              break;
            case 'n':
              p.OPT_N = 1;
              argv[count] = "";
              break;
            default:
              break;
          }
        }
        count++;
      } else {
        s21_size_t n = 1;
        char strFile[BMAX] = "";
        p.p = fopen(argv[count], "r");
        while (fgets(strFile, BMAX, p.p) != s21_NULL) {
          if (p.OPT_B == 1 && p.p != s21_NULL) {
            printf((*strFile != '\n') ? "%6lu\t%s" : "\n", n++, strFile);
          } else if (p.OPT_N == 1 && p.p != s21_NULL) {
            printf("%6lu\t%s", n++, strFile);
          } else if (p.OPT_E == 1 && p.p != s21_NULL) {
            printf("%6lu\t%s", n++, strFile);
          } else if (p.OPT_B + p.OPT_E + p.OPT_S + p.OPT_T + p.OPT_N == 0 &&
                     p.p != s21_NULL) {
            printf("%s", strFile);
          }
        }
        fclose(p.p);
        count++;
      }
    }
  }
  return ok;
}
