CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -g
OS=$(shell uname)

s21_grep:
	$(CC) $(CFLAGS) s21_grep.c -o s21_grep
	bash grep_test.sh

check:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config s21_grep.c
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extensions=c s21_grep.c s21_grep.h
	rm CPPLINT.cfg
	make s21_grep
ifeq ($(OS), Darwin)
	leaks --atExit -- ./s21_grep -f phrase.txt s21_grep.h
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./s21_grep -f phrase.txt s21_grep.h
endif

clean:
	rm -rf s21_grep s21_grep.dSYM *.o RESULT_VALGRIND.txt log.txt
