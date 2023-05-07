CC = g++ -std=c++17
SOURSE = model/s21_calc.cc
TEST_LIBS = -lgtest -lgmock -pthread
FLAG_LEAKS = -lgtest -lstdc++ -lpthread -std=c++17 -g -lcheck
GCC=$(CC) -Wall -Wextra -Werror -Wuninitialized

all: build install 

build:
	cd view && qmake

test:
	rm -rf gtest/test
	$(GCC) -lgtest -lgmock -pthread gtest/s21_gtest.cc $(SOURSE) -o gtest/test
	gtest/test

dvi:
	open 'https://github.com/Selloni/SmartCalc-v2.0'

install: uninstall
	cd view && qmake && make -j6 && make clean && mv smartcalk.app ~/Desktop/

open:
	cd ~/Desktop && open smartcalk.app

uninstall:
	cd ~/Desktop && rm -rf smartcalk.app 

clean: 
	rm -rf gtest/test
	cd view && qmake && make clean

dist:
	mkdir build
	tar -cf build/dist.tar smartcalk.app
