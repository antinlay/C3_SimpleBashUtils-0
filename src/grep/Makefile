CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -g
OS=$(shell uname)

s21_grep: clean
	$(CC) $(CFLAGS) s21_grep.c -o s21_grep
	bash grep_test.sh
	# ./s21_grep -e -l -v -c -n -f -o

check:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config s21_cat.c
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extensions=c s21_cat.c
	rm -rf CPPLINT.cfg
	make s21_cat
ifeq ($(OS), Darwin)
	leaks --atExit -- ./s21_cat -set bytes.txt
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./s21_cat -set bytes.txt
endif

clean:
	rm -rf s21_grep *.o RESULT_VALGRIND.txt
