#include <stdio.h>
#include <string.h>
#define BSIZE 100000

int main(void) {
  //   FILE *p;
  char cmdName[] = "s21_cat ";
  char scnName[BSIZE] = "";
  //   char fileName[BSIZE] = "";
  scanf("%s", scnName);
  printf("%ld", strspn(scnName, cmdName));
  return 0;
}