CC = clang++
CPPFLAGS = -Wall -pedantic -g
OBJS := $(addprefix build/,3x3grid.o grid.o)

.DEFAULT: all

.PHONY: all

all: build/3x3grid

build:
	mkdir -p build

$(OBJS): | build

build/%.o: src/%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

build/3x3grid: $(OBJS) build/3x3grid.o
	$(CC) $(CPPFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -rf ./build/