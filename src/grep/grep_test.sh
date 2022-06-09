#!/bin/bash
#1 -e
./s21_grep -e 127 s21_grep.c >> s21_grep.txt
grep -e 127 s21_grep.c >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
#2 -i
./s21_grep -i e s21_grep.c >> s21_grep.txt
grep -i e s21_grep.c >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
#3 -v
./s21_grep -v e s21_grep.c > s21_grep.txt
grep -v e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #4 -c
./s21_grep -c e s21_grep.c > s21_grep.txt
grep -c e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #5 -l
./s21_grep -l e s21_grep.c s21_grep.c s21_grep.c > s21_grep.txt
grep -l e s21_grep.c s21_grep.c s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #6 -h
./s21_grep -h e s21_grep.c > s21_grep.txt
grep -h e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #7 -s
./s21_grep -s e s21_grep.c > s21_grep.txt
grep -s e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #8 -f
./s21_grep -f phrase.txt s21_grep.c > s21_grep.txt
grep -f phrase.txt s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #9 int
./s21_grep int s21_grep.c s21_grep.h > s21_grep.txt
grep int s21_grep.c s21_grep.h > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #10 -i int
./s21_grep -i int s21_grep.h > s21_grep.txt
grep -i int s21_grep.h > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #11 -v s
./s21_grep -v s s21_grep.h > s21_grep.txt
grep -v s s21_grep.h > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #12 -c s
./s21_grep -c s s21_grep.h > s21_grep.txt
grep -c s s21_grep.h > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #13 -l s
./s21_grep -l s s21_grep.h > s21_grep.txt
grep -l s s21_grep.h > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #14 -n s
./s21_grep -n s s21_grep.h > s21_grep.txt
grep -n s s21_grep.h > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #15 -o 123
./s21_grep -o 123 s21_grep.c > s21_grep.txt
grep -o 123 s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #16 -h optinons
./s21_grep -h options s21_grep.c s21_grep.h > s21_grep.txt
grep -h options s21_grep.c s21_grep.h > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #17 grep -s
./s21_grep grep -s 123123 > s21_grep.txt
grep grep -s 123123 > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #18 -f
./s21_grep -f phrase.txt s21_grep.h > s21_grep.txt
grep -f phrase.txt s21_grep.h > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #19 -in
./s21_grep -in options s21_grep.c > s21_grep.txt
grep -in options s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #20 -cv
./s21_grep -cv s s21_grep.c > s21_grep.txt
grep -cv s s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #21 -iv
./s21_grep -iv s s21_grep.c > s21_grep.txt
grep -iv s s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #22 -lv
./s21_grep -lv s s21_grep.c > s21_grep.txt
grep -lv s s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #23 -ho
./s21_grep -ho int phrase.txt pattern.txt > s21_grep.txt
grep -ho int phrase.txt pattern.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #24 -nf
./s21_grep -nf phrase.txt pattern.txt > s21_grep.txt
grep -nf phrase.txt pattern.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt