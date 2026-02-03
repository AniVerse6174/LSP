# Makefile for static library project

CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = app
LIB = libmath.a
OBJS = add.o sub.o mul.o div.o

lib: $(LIB)

$(LIB): $(OBJS)
	ar rcs $(LIB) $(OBJS)

%.o: %.c math.h
	$(CC) $(CFLAGS) -c $< -o $@

app: main.c $(LIB)
	$(CC) $(CFLAGS) main.c -L. -lmath -o $(TARGET)

run: app
	./$(TARGET)

clean:
	rm -f $(TARGET) $(LIB) *.o

help:
	@echo "Usage:"
	@echo "  make lib   → Build static library"
	@echo "  make app   → Build app using libmath.a"
	@echo "  make run   → Run the app"
	@echo "  make clean → Remove binaries"