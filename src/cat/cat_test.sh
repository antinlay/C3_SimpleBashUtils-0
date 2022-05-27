#!/bin/bash

./s21_cat bytes.txt >> s21_cat.txt
cat bytes.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -b bytes.txt >> s21_cat.txt
cat -b bytes.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -e bytes.txt >> s21_cat.txt
cat -e bytes.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -n bytes.txt >> s21_cat.txt
cat -n bytes.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -s bytes.txt >> s21_cat.txt
cat -s bytes.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -t bytes.txt >> s21_cat.txt
cat -t bytes.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt
