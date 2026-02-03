CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = app
OBJS = main.o helper.o

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c helper.h
	$(CC) $(CFLAGS) -c main.c

helper.o: helper.c helper.h
	$(CC) $(CFLAGS) -c helper.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)

help:
	@echo "Usage:"
	@echo "  make        → Build the app"
	@echo "  make run    → Run the app"
	@echo "  make clean  → Remove binaries"