#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

struct s21_cat {
  int OPT_B;
  int OPT_E;
  int OPT_S;
  int OPT_T;
  int OPT_N;
  FILE *p;
} p;

int main(int argc, char **argv) {
  if (argc > 1) {
    size_t count = argc - 1, i = 0;
    while (count) {
      if (argv[count][i] == '-') {
        for (i = 0; i < s21_strlen(argv[count]); i++) {
          if (argv[count][i] == 'b')
            p.OPT_B = 1;
          else if (argv[count][i] == 'e')
            p.OPT_E = 1;
          else if (argv[count][i] == 's')
            p.OPT_S = 1;
          else if (argv[count][i] == 't')
            p.OPT_T = 1;
          else if (argv[count][i] == 'n')
            p.OPT_T = 1;
        }
        count--;
      } else {
        char strFile[1000] = "";
        p.p = fopen(argv[count], "r");
        while (fgets(strFile, sizeof(strFile), p.p)) {
          printf("%s", strFile);
        }
        count--;
      }
    }
    printf("\nBEST: %d%d%d%d%d", p.OPT_B, p.OPT_E, p.OPT_S, p.OPT_T, p.OPT_N);
  }
  return 0;
}