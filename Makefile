TARGET = main

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRCS = main.c myMalloc.c

OBJS = $(SRCS:.c=.o)

DEPS = myMalloc.h

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
