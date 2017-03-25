CC = clang++
CPPFLAGS = -Wall -pedantic -g -std=c++11
OBJS := $(addprefix build/,grid.o grid_game.o tictactoe.o)

.DEFAULT: all

.PHONY: all

all: build/3x3grid

.PHONY: test

test: build/3x3grid_test

build:
	mkdir -p build

$(OBJS): | build

build/%.o: src/%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

build/3x3grid: $(OBJS) build/3x3grid.o
	$(CC) $(CPPFLAGS) $^ -o $@

build/3x3grid_test: $(OBJS) build/3x3grid_test.o
	$(CC) $(CPPFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -rf ./build/
