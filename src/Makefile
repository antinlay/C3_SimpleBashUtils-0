

CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -g






s21_cat:
	$(CC) $(CFLAGS) cat/s21_cat.c -o cat/s21_cat
	cat/s21_cat -s ../README.md

s21_grep:
	$(CC) $(CFLAGS) grep/s21_cat.c libs21_string.a -o s21_cat

clean:
	rm -rf cat/s21_cat *.o
