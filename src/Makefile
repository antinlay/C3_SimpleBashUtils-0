CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -g
OS=$(shell uname)

s21_cat:
	$(CC) $(CFLAGS) cat/s21_cat.c -o cat/s21_cat
	bash cat/cat_test.sh

s21_grep:
	$(CC) $(CFLAGS) grep/s21_grep.c -o grep/s21_grep
	bash grep/grep_test.sh

check:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config cat/s21_cat.c
	cp ../materials/linters/CPPLINT.cfg cat/CPPLINT.cfg
	cp ../materials/linters/CPPLINT.cfg grep/CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c cat/s21_cat.* grep/s21_grep.*
	rm cat/CPPLINT.cfg grep/CPPLINT.cfg
	make s21_cat
	make s21_grep
ifeq ($(OS), Darwin)
	leaks --atExit -- cat/s21_cat -set cat/bytes.txt
	leaks --atExit -- grep/s21_grep -e grep/bytes.txt
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt cat/s21_cat -set cat/bytes.txt
endif

clean:
	rm -rf cat/s21_cat cat/s21_cat.dSYM grep/s21_grep grep/s21_grep.dSYM *.o RESULT_VALGRIND.txt
