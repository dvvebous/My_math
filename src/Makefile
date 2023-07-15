CC=gcc
CFLAGS=-Wall -Wextra -Werror
LDFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage
TEST_LIBS = -lcheck -lm -lpthread

.PHONY: all clean

all: s21_math.a test gcov_report

s21_math.a:
	$(CC) $(CFLAGS) -c s21_math.c
	ar rc s21_math.a *.o
	ranlib s21_math.a
	
clean:
	-rm -rf gcov_report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt

test:
	$(CC) $(CFLAGS) $(LDFLAGS) s21_math.c tests/*.c

style_check:
	clang-format --style=Google -n $(SRCS) *.c *.h
	
style:
	clang-format --style=Google -i $(SRCS) *.c *.h

gcov_report:
	$(CC) $(CFLAGS) $(LDFLAGS) $(GCOVFLAGS) s21_math.c tests/*.c -o gcov_main
	./gcov_main
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html
