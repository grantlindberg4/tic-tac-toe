CC = clang++
CPPFLAGS = -Wall -pedantic -g -std=c++11
OBJS := $(addprefix build/,grid.o grid_game.o tictactoe.o new_game.o)

.DEFAULT: all

.PHONY: all

all: build/tictactoe

.PHONY: test

test: build/tictactoe_test

build:
	mkdir -p build

$(OBJS): | build

build/%.o: src/%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

build/tictactoe: $(OBJS) build/main.o
	$(CC) $(CPPFLAGS) $^ -o $@

build/tictactoe_test: $(OBJS) build/tictactoe_test.o
	$(CC) $(CPPFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -rf ./build/
