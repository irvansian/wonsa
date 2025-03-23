#ifndef LLIST_H
#define LLIST_H

typedef struct linked_list {
    char *cmd;
    struct linked_list *next;
} llist;

#endif