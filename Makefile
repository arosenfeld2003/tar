CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRCS = src/main.c src/create.c src/list.c src/extract.c src/update.c src/append.c src/utils.c
OBJS = $(SRCS:.c=.o)
TARGET = my_tar

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)

