# CC = gcc
# CFLAGS = -Wall -Werror -Wextra

# SRC = s21_math.c
# OBJ = $(SRC:.c=.o)
# TARGET = s21_math

# TEST_SRC = s21_math_test.c
# TEST_OBJ = $(TEST_SRC:.c=.o)
# TEST_TARGET = s21_math_test
# TEST_LIBS = -lcheck -lm -lpthread

# s21_math.a: s21_math.o
# 	$(CC) -c $(SRC)
# 	ar rcs s21_math.a $(OBJ)

# gcov_report: s21_math.a 
# 	$(CC) $(CFLAGS) --coverage s21_math_test.c s21_math.c s21_math.a  -o gcov_test $(TEST_LIBS)
# 	chmod +x *
# 	./gcov_test
# 	gcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
# 	genhtml -o  gcov_test.info
# 	index.html

# gcov_report: add_gcover_flag
# 	$(CC) &

# .PHONY: all clean


# all: $(TARGET) $(TEST_TARGET)

# $(TARGET): $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# $(TEST_TARGET): $(TEST_OBJ) $(OBJ)
# 	$(CC) $(CFLAGS) $(TEST_OBJ) $(OBJ) $(TEST_LIBS) -o $(TEST_TARGET)

# clean:
# 	rm -rf $(TARGET) $(TEST_TARGET) $(OBJ) $(TEST_OBJ)
# 	rm -f *.gc*

.PHONY: all clean

CC=gcc
CFLAGS=-Wall -Wextra -Werror
LDFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage

all: s21_math.a

s21_math.a:
	$(CC) $(CFLAGS) -c s21_math.c
	ar rc s21_math.a *.o
	ranlib s21_math.a
	
clean:
	-rm -rf gcov_report/ *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt

test:
	$(CC) $(CFLAGS) $(LDFLAGS) s21_math.c tests/*.c

gcov_report:
	$(CC) $(CFLAGS) $(LDFLAGS) $(GCOVFLAGS) s21_math.c tests/*.c -o gcov_main
	./gcov_main
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	open gcov_report/index.html
