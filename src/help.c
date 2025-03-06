#include <stdio.h>
#include "help.h"

void print_help() {
    printf("Usage: program [OPTIONS]\n");
    printf("Options:\n");
    printf("  -u, --users       Display users and home directories sorted alphabetically\n");
    printf("  -p, --processes   Display running processes sorted by PID\n");
    printf("  -h, --help        Display this help message\n");
    printf("  -l, --log PATH    Redirect output to PATH\n");
    printf("  -e, --errors PATH Redirect errors to PATH\n");
}
