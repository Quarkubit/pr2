#include <stdio.h>
#include <stdlib.h>
#include "processes.h"

void print_processes() {
    FILE *ps = popen("ps -e -o pid,comm --sort pid", "r");
    if (!ps) { perror("popen"); exit(EXIT_FAILURE); }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), ps)) printf("%s", buffer);
    pclose(ps);
}
