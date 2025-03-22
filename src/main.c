#include <stdio.h>
#include <string.h>
#include "wreader.h"
#include "cmd_exec.h"

int main(int argc, char **argv) {
    if (strcmp(argv[0], "wonsa")) {
        printf("Command %s is unknown", argv[0]);
        return -1;
    }

    if (argc > 2) {
        printf("Command too long");
        return -1;
    }

    char *sh_cmd = match_cmd(argv[1]);
    exec_cmd(sh_cmd);
    free_cmd(sh_cmd);

    return 0;
}