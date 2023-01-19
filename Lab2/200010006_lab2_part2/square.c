#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        exit(0);
    }

    int n = atoi(argv[argc - 1]);
    int res = n * n;
    printf("Current process id: %u, Current result: %d\n", getpid(), res);

    char *v[argc];
    for (int i = 1; i < argc - 1; i++) {
        v[i - 1] = argv[i];
    }

    char res_str[20];
    sprintf(res_str, "%d", res);
    v[argc - 2] = res_str;
    v[argc - 1] = NULL;

    execvp(v[0], v);
    return 0;
}