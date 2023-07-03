CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = main.c s21_math.c
OBJ = $(SRC:.c=.o)
TARGET = s21_math

TEST_SRC = s21_math_test.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_TARGET = s21_math_test
TEST_LIBS = -lcheck -lm -lpthread

.PHONY: all clean

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

$(TEST_TARGET): $(TEST_OBJ) $(filter-out main.o,$(OBJ))
	$(CC) $(CFLAGS) $(TEST_OBJ) $(filter-out main.o,$(OBJ)) $(TEST_LIBS) -o $(TEST_TARGET)

clean:
	rm -rf $(TARGET) $(TEST_TARGET) $(OBJ) $(TEST_OBJ)
