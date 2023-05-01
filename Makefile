G = g++ -std=c++17
GCC = $(G) -Wall -Wextra -Werror -Wuninitialized
TEST_LIBS = -lgtest -lgmock -pthread
FLAG_LEAKS = -lgtest -lstdc++ -lpthread -std=c++17 -g -lcheck

all: test

test: clean
	$(GCC) $(TEST_LIBS) src/s21_gtest.cc -o test.o
	./test
#./test --gtest_repeat=10 --gtest_break_on_failure

clean:
	@ rm -rf test

