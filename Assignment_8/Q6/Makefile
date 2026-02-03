# Makefile for shared library build

CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = app
LIB = libmath.so
SRC = math.c
HDR = math.h

so: $(LIB)

$(LIB): $(SRC) $(HDR)
	$(CC) -fPIC -c $(SRC)
	$(CC) -shared -o $(LIB) math.o

app: main.c $(LIB)
	$(CC) $(CFLAGS) main.c -L. -lmath -o $(TARGET)

run: app
	LD_LIBRARY_PATH=. ./$(TARGET)

clean:
	rm -f $(TARGET) $(LIB) *.o

help:
	@echo "Usage:"
	@echo "  make so    → Build shared library"
	@echo "  make app   → Build app using libmath.so"
	@echo "  make run   → Run the app (sets LD_LIBRARY_PATH)"
	@echo "  make clean → Remove binaries"