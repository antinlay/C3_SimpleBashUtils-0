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

int init();
int s21_parser(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  char *greph = "GREPH";
  regex_t preg;
  char *pat = "PH";
  printf("GREPH %d PREG %d", regcomp(&preg, pat, REG_EXTENDED), preg);
  // printf("");
  return 0;
}

int init() {
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
    case 'e':
      p.e = 1;
      break;
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
    case 'f':
      p.f = 1;
      break;
    case 'o':
      p.o = 1;
      break;
    default:
      break;
  }
}

int s21_parser(int argc, char *argv[]) {}
