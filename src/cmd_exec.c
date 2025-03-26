#include <stdio.h>
#include <stdlib.h>
#include "cmd_exec.h"

void exec_cmd(const char *cmd) {
    int ret_code = system(cmd);

    if (ret_code != 0) {
        perror("command execution failed: returned non zero");
    }
}