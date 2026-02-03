# Makefile for building and running app

CC = gcc
TARGET = app

all: $(TARGET)

$(TARGET): main.c
	$(CC) main.c -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)