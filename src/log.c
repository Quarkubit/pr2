#include <stdio.h>
#include "log.h"

int redirect_output(const char *path) {
    FILE *file = freopen(path, "w", stdout);
    return file != NULL;
}

int redirect_errors(const char *path) {
    FILE *file = freopen(path, "w", stderr);
    return file != NULL;
}
