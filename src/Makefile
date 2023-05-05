CC = g++ -std=c++17
SOURSE = model/s21_calc.cc
TEST_LIBS = -lgtest -lgmock -pthread
FLAG_LEAKS = -lgtest -lstdc++ -lpthread -std=c++17 -g -lcheck
GCC=$(CC) -Wall -Wextra -Werror -Wuninitialized

all: test

test: clean
	$(GCC) -lgtest -lgmock -pthread gtest/s21_gtest.cc $(SOURSE) -o build/test
	build/test

dvi:
	open 'https://github.com/Selloni/SmartCalc-v2.0'

install:
	mv Makefile cloneMake && qmake && make && make clean && rm Makefile && mv cloneMake Makefile

uninstall:
		rm -rf smartcalk.app

debug:
	$(CC) $(SOURSE) -g

clean:
	rm -rf build/* &&
 	cd view && make clean


dist:
	mkdir build
	tar -cf build/dist.tar smartcalk.app

clang:
	mv ../materials/linters/.clang-format .clang-format
	clang-format -i s21_*.c s21_*.h
	clang-format -n s21_*.c s21_*.h
	mv .clang-format ../materials/linters/.clang-format