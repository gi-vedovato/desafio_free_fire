CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
TARGET = free_fire_game
OBJS = game.o inventory.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

game.o: game.c inventory.h
	$(CC) $(CFLAGS) -c game.c

inventory.o: inventory.c inventory.h
	$(CC) $(CFLAGS) -c inventory.c

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
