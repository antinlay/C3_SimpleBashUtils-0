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
  s21_size_t ok = 0;
  if (argc > 1) {
    s21_size_t count = 1, i = 0;
    while (count != ((s21_size_t)argc + 1)) {
      if (argv[count][i] == '-') {
        for (i = 0; i < s21_strlen(argv[count]); i++) {
          switch (argv[count][i]) {
            case 'b':
              p.OPT_B = 1;
              argv[count++] = "";
              break;
            case 'e':
              p.OPT_E = 1;
              argv[count++] = "";
              break;
            case 's':
              p.OPT_S = 1;
              argv[count++] = "";
              break;
            case 't':
              p.OPT_T = 1;
              argv[count++] = "";
              break;
            case 'n':
              p.OPT_T = 1;
              argv[count++] = "";
              break;
            default:
              count++;
              break;
          }
        }
      } else {
        char strFile[1000000] = "";
        p.p = fopen(argv[count], "r");
        while (fgets(strFile, 1000000, p.p) != s21_NULL) {
          printf("%s", strFile);
        }
        fclose(p.p);
        count++;
      }
    }
  }
  return ok;
}
