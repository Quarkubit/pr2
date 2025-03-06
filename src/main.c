#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "help.h"
#include "users.h"
#include "processes.h"
#include "log.h"

int main(int argc, char *argv[]) {
    int opt;
    int show_users = 0, show_processes = 0, show_help = 0;
    char *log_path = NULL, *error_path = NULL;

    static struct option long_options[] = {
        {"users", no_argument, 0, 'u'},
        {"processes", no_argument, 0, 'p'},
        {"help", no_argument, 0, 'h'},
        {"log", required_argument, 0, 'l'},
        {"errors", required_argument, 0, 'e'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "uphl:e:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'u': show_users = 1; break;
            case 'p': show_processes = 1; break;
            case 'h': show_help = 1; break;
            case 'l': log_path = optarg; break;
            case 'e': error_path = optarg; break;
            default: fprintf(stderr, "Unknown option\n"); exit(EXIT_FAILURE);
        }
    }

    if (show_help) {
        print_help();
        exit(EXIT_SUCCESS);
    }

    if (!show_users && !show_processes) {
        fprintf(stderr, "ERROR: No action specified. Use -u, -p, or -h for help.\n");
        exit(EXIT_FAILURE);
    }

    if (log_path && !redirect_output(log_path)) {
        fprintf(stderr, "ERROR redirecting output to %s\n", log_path);
        exit(EXIT_FAILURE);
    }

    if (error_path && !redirect_errors(error_path)) {
        fprintf(stderr, "ERROR redirecting errors to %s\n", error_path);
        exit(EXIT_FAILURE);
    }

    if (show_users) print_users();
    if (show_processes) print_processes();

    return EXIT_SUCCESS;
}
