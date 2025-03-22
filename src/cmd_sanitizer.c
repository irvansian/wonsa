#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "cmd_sanitizer.h"

void trim_space(char *str) {
    char *start = str;
    char *end;

    while (isspace((unsigned char) *start)) {
        start++;
    }

    if (*start == '\0') {
        str[0] = '\0';
        return;
    }

    end = start + strlen(start) - 1; // ptr arithmetic
    while (end > start && isspace((unsigned char) *end)) {
        end--;
    }

    *(end + 1) = '\0';
    memmove(str, start, end - start + 2);
}
