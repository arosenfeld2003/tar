CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRCS = src/main.c src/create_archive.c src/list_archive.c src/extract_archive.c src/update_archive.c src/append_archive.c src/utils.c
OBJS = $(SRCS:.c=.o)
TARGET = my_tar

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)

