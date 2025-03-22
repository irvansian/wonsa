#include "wreader.h"
#include "cmd_sanitizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *match_cmd(const char *input_cmd) {
    FILE *file = fopen("Wonsafile", "r");

    if (file == NULL) {
        perror("Wonsafile not found in current dir");
        return NULL;
    }

    char line_buf[64];
    char *sh_cmd;

    while (fgets(line_buf, sizeof(line_buf), file)) {
        char *line_cmd = strtok(line_buf, ":");
        if (strcmp(line_cmd, input_cmd) != 0) {
            continue;
        }
        
        sh_cmd = strtok(NULL, "");
        break;
    }
    
    fclose(file);

    trim_space(sh_cmd);

    if (sh_cmd == NULL) {
        perror("Shell command not found");
        return NULL;
    }

    char *buf = (char *) malloc(sizeof(char) * (strlen(sh_cmd) + 1));
    strcpy(buf, sh_cmd);
    return buf;
}

void free_cmd(char *str) {
    free(str);
}