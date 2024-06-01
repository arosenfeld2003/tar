#include "utils.h"
#include <unistd.h>
#include <string.h>

void print_error(const char *message) {
    write(STDERR_FILENO, message, strlen(message));
}
