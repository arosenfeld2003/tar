#include "../include/create.h"
#include "../include/utils.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void create_archive(const char *archive_file, char *files[], int file_count) {
    int archive_fd = open(archive_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (archive_fd < 0) {
        print_error("Cannot create archive file\n");
        return;
    }

    for (int i = 0; i < file_count; i++) {
        // write the file metadata and contents to the archive
        // for now, just print the filenames
        write(STDOUT_FILENO, files[i], strlen(files[i]));
        write(STDOUT_FILENO, "\n", 1);
    }

    close(archive_fd);
}
