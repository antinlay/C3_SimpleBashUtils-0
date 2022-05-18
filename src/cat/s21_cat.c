#include <stdio.h>
#include <string.h>

struct s21_cat {
  int OPT_B;
  int OPT_E;
  int OPT_S;
  int OPT_T;
  int OPT_N;
} p;

int main(int argc, char *argv[]) {
  // char flagList[] = "best";
  if (argc > 1) {
    size_t i = 0;
    while (argc) {
      if (argv[argc][i] == '-') {
        for (i = 1; i < strlen(argv[argc]); i++) {
          if (argv[argc][i++] == 'b')
            p.OPT_B = 1;
          else if (argv[argc][i] == 'e')
            p.OPT_E = 1;
          else if (argv[argc][i] == 's')
            p.OPT_S = 1;
          else if (argv[argc][i] == 't')
            p.OPT_T = 1;
          else if (argv[argc][i] == 'n')
            p.OPT_T = 1;
        }
        argc--;

        // if (argv[argc][1] == 'b' || argv[argc][1] == 'e' ||
        //     argv[argc][1] == 's' || argv[argc][1] == 't') {
        // }
      } else {
        argc--;
      }
    }
    printf("BEST: %d%d%d%d%d", p.OPT_B, p.OPT_E, p.OPT_S, p.OPT_T, p.OPT_N);
  }
  return 0;
}