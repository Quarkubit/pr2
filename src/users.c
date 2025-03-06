#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"

typedef struct {
    char *name;
    char *home;
} User;

static int compare_users(const void *a, const void *b) {
    return strcmp(((User*)a)->name, ((User*)b)->name);
}

void print_users() {
    struct passwd *pw;
    User *users = NULL;
    size_t count = 0;

    setpwent();
    while ((pw = getpwent()) != NULL) {
        User *temp = realloc(users, (count + 1) * sizeof(User));
        if (!temp) { perror("realloc"); exit(EXIT_FAILURE); }
        users = temp;
        users[count].name = strdup(pw->pw_name);
        users[count].home = strdup(pw->pw_dir);
        if (!users[count].name || !users[count].home) { perror("strdup"); exit(EXIT_FAILURE); }
        count++;
    }
    endpwent();

    qsort(users, count, sizeof(User), compare_users);

    for (size_t i = 0; i < count; i++) {
        printf("%s: %s\n", users[i].name, users[i].home);
        free(users[i].name);
        free(users[i].home);
    }
    free(users);
}
