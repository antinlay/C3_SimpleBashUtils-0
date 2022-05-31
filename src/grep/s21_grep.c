#include <regex.h>
#include <stdio.h>
#include <unistd.h>
#define BSIZE 1000000

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
int phrase_file(char *phrase, char *buff);
void greph(char *phrase, char *fileName);
void edit_file(regex_t rgx, char *fileName);
void greph_logic(int argc, char *argv[], char *buff);

int main(int argc, char *argv[]) {
  char greph[BSIZE] = "";
  int ok = 0;
  init();
  ok = parser(argc, argv, greph);
  if (argc >= 3 && ok != 1) greph_logic(argc, argv, greph);
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

int phrase_file(char *phrase, char *buff) {
  p.file = fopen(buff, "r");
  int i = 0;

  if (p.file == NULL) {
    i = -1;
  } else {
    int symb;
    while ((symb = fgetc(p.file)) != EOF) {
      if (symb == 13 || symb == 10) phrase[i++] = '|';
      if (symb != 13 && symb != 10) phrase[i++] = symb;
    }
    if (phrase[--i] == '|') phrase[--i] = '\0';
    fclose(p.file);
  }
  return i == -1 ? i : ++i;
}

void greph(char *phrase, char *fileName) {
  int flags = (p.i) ? REG_ICASE : REG_EXTENDED;
  regex_t rgx;
  p.file = fopen(fileName, "r");

  if (p.file != NULL) {
    regcomp(&rgx, phrase, flags);
    edit_file(rgx, fileName);
    regfree(&rgx);
    fclose(p.file);
  }
}

void edit_file(regex_t rgx, char *fileName) {
  char text[BSIZE] = "";
  regmatch_t match[1];
  int strMatch = 0, numStr = 1;

  while (fgets(text, BSIZE - 1, p.file) != NULL) {
    int regStatus = regexec(&rgx, text, 1, match, 0);
    int numMatch = 0;

    if ((regStatus == 0 && !p.v) || (regStatus == REG_NOMATCH && p.v))
      numMatch = 1;
    if (numMatch && !p.l && !p.c && p.n) printf("%d:", numStr);
    if (numMatch && !p.l && !p.c && !p.o) printf("%s", text);

    if (p.o && numMatch) {
      for (int i = match[0].rm_so; i < match[0].rm_eo; i++) {
        printf("%c", text[i]);
      }
      printf("\n");
    }
    strMatch += numMatch;
    numStr++;
  }
  if (p.l && strMatch > 0) printf("%s\n", fileName);
  if (p.c && !p.l) printf("%d\n", strMatch);
}

void greph_logic(int argc, char *argv[], char *buff) {
  char phrase[BSIZE] = "";
  int ok = 0;

  if (!p.f && !p.e) snprintf(phrase, BSIZE, argv[optind++]);
  if (p.f) ok = phrase_file(phrase, buff);
  if (!p.f && p.e) snprintf(phrase, BSIZE, buff);

  if (ok != -1) {
    int fileFlag = (argc - optind > 1) ? 1 : 0;

    for (int i = optind; i < argc; i++) {
      if (fileFlag && !p.h && !p.l) printf("%s:", argv[i]);
      greph(phrase, argv[i]);
    }
  }
}
