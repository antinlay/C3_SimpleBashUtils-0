#!/bin/bash
#1
./s21_grep -e 127 s21_grep.c >> s21_grep.txt
grep -e 127 s21_grep.c >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
#2 -i
./s21_grep -i e s21_grep.c >> s21_grep.txt
grep -i e s21_grep.c >> grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #3 -v
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
# #6 -n
./s21_grep -n e s21_grep.c > s21_grep.txt
grep -n e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #7 -h
./s21_grep -h e s21_grep.c > s21_grep.txt
grep -h e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #8 -s
./s21_grep -s e s21_grep.c > s21_grep.txt
grep -s e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #9 -f
./s21_grep -f phrase.txt s21_grep.c > s21_grep.txt
grep -f phrase.txt s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #10 -o
./s21_grep -o '[[:alnum:]+\.\_\-]*@[[:alnum:]+\.\_\-]*' emails.txt > s21_grep.txt
grep -o '[[:alnum:]+\.\_\-]*@[[:alnum:]+\.\_\-]*' emails.txt > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
# #11 -sn
# ./s21_cat -sn bytes.txt >> s21_cat.txt
# cat -sn bytes.txt >> cat.txt
# diff -s s21_cat.txt cat.txt
# rm s21_cat.txt cat.txt
# #12 -sb
# ./s21_cat -sb bytes.txt >> s21_cat.txt
# cat -sb bytes.txt >> cat.txt
# diff -s s21_cat.txt cat.txt
# rm s21_cat.txt cat.txt
# #13 -nb
# ./s21_cat -nb bytes.txt >> s21_cat.txt
# cat -nb bytes.txt >> cat.txt
# diff -s s21_cat.txt cat.txt
# rm s21_cat.txt cat.txt
# #14 -v
# ./s21_cat -v bytes.txt >> s21_cat.txt
# cat -v bytes.txt >> cat.txt
# diff -s s21_cat.txt cat.txt
# rm s21_cat.txt cat.txt
# #15 -ne
# ./s21_cat -n bytes.txt bytes.txt >> s21_cat.txt
# cat -n bytes.txt bytes.txt >> cat.txt
# diff -s s21_cat.txt cat.txt
# rm s21_cat.txt cat.txt
# #15 -err
# ./s21_cat -n bytes.txt byte1s.txt >> s21_cat.txt
# cat -n bytes.txt byte1s.txt >> cat.txt
# diff -s s21_cat.txt cat.txt
# rm s21_cat.txt cat.txt
