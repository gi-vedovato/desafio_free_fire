CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
TARGET = free_fire_game
TEST_TARGET = test_inventory
OBJS = game.o inventory.o
TEST_OBJS = test_inventory.o inventory.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

game.o: game.c inventory.h
	$(CC) $(CFLAGS) -c game.c

test_inventory.o: test_inventory.c inventory.h
	$(CC) $(CFLAGS) -c test_inventory.c

inventory.o: inventory.c inventory.h
	$(CC) $(CFLAGS) -c inventory.c

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all test clean run
