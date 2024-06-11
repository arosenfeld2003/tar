#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "create.h"
#include "list.h"
#include "extract.h"
#include "update.h"
#include "append.h"
#include "utils.h"

const char *no_files = "my_tar: no files or directories specified\n";
const char *no_options = "my_tar: Must specify one of -c, -r, -t, -u, -x\n";

void show_correct_usage() {
    const char *explain = "Minimum 3 arguments required: program name, flag(s), filename(s)\n";
    const char *usage = "Usage: my_tar -[crudxt]f archive.tar [files...]\n";
    write(STDERR_FILENO, usage, strlen(explain));
    write(STDERR_FILENO, usage, strlen(usage));
}

int main (int argc, char* argv[]) {
    // minimum 3 arguments required: program name, flag(s), filename(s)
    if (argc < 3) {
        show_correct_usage();
        return 1;
    }

    char mode = '\0';
    char *archive_file = NULL;

    // flags
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            for (int j = 1; argv[i][j] != '\0'; j++) {
                switch (argv[i][j]) {
                    // only one of these flags can be passed
                    case 'c': case 'r': case 'u': case 'd': case 't': case 'x':
                        if (mode != '\0') {
                            print_error("my_tar: Can't specify multiple modes\n");
                            return 1;
                        }
                        mode = argv[i][j];
                        break;
                    case 'f':
                        if (i + 1 >= argc) {
                            print_error(no_files);
                            return 1;
                        }
                        archive_file = argv[++i];
                        break;
                    default:
                        show_correct_usage();
                        return 1;
                }
            }
        } else {
            break;
        }
    }

    if (mode == '\0') {
        print_error(no_options);
        return 1;
    }

    // index for file args
    int file_arg_start = 3;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            file_arg_start = i;
            break;
        }
    }

    switch (mode) {
        case 'c':
            create_archive(archive_file, &argv[file_arg_start], argc - file_arg_start);
            break;
        case 'r':
            append_archive(archive_file, &argv[file_arg_start], argc - file_arg_start);
            break;
        case 't':
            list_archive(archive_file);
            break;
        case 'u':
            update_archive(archive_file, &argv[file_arg_start], argc - file_arg_start);
            break;
        case 'x':
            extract_archive(archive_file);
            break;
        default:
            print_usage();
            return 1;
    }

    return 0;
}