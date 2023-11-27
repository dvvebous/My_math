CC=gcc
CFLAGS=-Wall -Wextra -Werror
LDFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage
TEST_LIBS=-lcheck -lm -lpthread

.PHONY: all clean

all: s21_math.a test gcov_report

s21_math.a:
	$(CC) $(CFLAGS) -c s21_math.c
	ar rc s21_math.a *.o
	ranlib s21_math.a
	
clean:
	-rm -rf gcov_report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt gcov_main

test:
	$(CC) $(CFLAGS)  s21_math.c tests/*.c $(LDFLAGS)

style_check:
	clang-format --style=Google -n *.c *.h
	
style:
	clang-format --style=Google -i *.c *.h

gcov_report:
	$(CC) $(CFLAGS)  $(GCOVFLAGS) s21_math.c tests/*.c -o gcov_main $(LDFLAGS)
	./gcov_main
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html
