#include <regex.h>
#include <stdio.h>
#include <unistd.h>

struct greph {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int sumStr;
  FILE *file;
} p;

void init();
int parser(int argc, char *argv[], char *phrase);

int main(int argc, char *argv[]) {
  char greph[100] = "";
  // regex_t preg;
  // char *pat = "PH";
  int ok = 0;
  // printf("GREPH %d PREG %d", regcomp(&preg, pat, REG_EXTENDED), preg);
  // printf("");
  ok = parser(argc, argv, greph);
  printf("GREPH: %s\n", greph);
  return ok;
}

void init() {
  p.e = 0;
  p.i = 0;
  p.v = 0;
  p.c = 0;
  p.l = 0;
  p.n = 0;
  p.h = 0;
  p.s = 0;
  p.f = 0;
  p.o = 0;
  p.file = NULL;
}

void options(char arg) {
  switch (arg) {
    case 'i':
      p.i = 1;
      break;
    case 'v':
      p.v = 1;
      break;
    case 'c':
      p.c = 1;
      break;
    case 'l':
      p.l = 1;
      break;
    case 'n':
      p.n = 1;
      break;
    case 'h':
      p.h = 1;
      break;
    case 's':
      p.s = 1;
      break;
    default:
      break;
  }
}

int parser(int argc, char *argv[], char *phrase) {
  int flag = 0, ok = 0;
  while ((flag = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    if (flag == 'e') {
      p.e = 1;
      sprintf(phrase, optarg);
    } else if (flag) {
      options(flag);
    } else if (flag == 'f') {
      p.f = 1;
      sprintf(phrase, optarg);
    } else if (flag == 'o') {
      p.o = 1;
    } else {
      ok = -1;
    }
  }
  return ok;
}
