# Makefile with help target

CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = app
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

help:
	@echo "Usage:"
	@echo "  make        → Build the app"
	@echo "  make run    → Run the app"
	@echo "  make clean  → Remove the binary"