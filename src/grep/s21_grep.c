#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct grep {
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

int main(int argc, char *argv[]) { return 0; }