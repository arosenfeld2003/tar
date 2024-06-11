CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRCS = src/main.c src/create.c src/list.c src/extract.c src/update.c src/append.c src/utils.c
OBJS = $(SRCS:.c=.o)
ARCHIVE = test_archive.tar
TEST_FILES = test_file1.txt test_file2.txt
TARGET = my_tar

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET) $(ARCHIVE) $(TEST_FILES)

test: all
	@for test in tests/*.sh; do \
        echo "Running $$test..."; \
        bash $$test || exit 1; \
    done
	@echo "All tests passed."