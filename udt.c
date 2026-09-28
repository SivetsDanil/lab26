#include "udt.h"
#include <stdio.h>
const data_type NIL = {0, '\0'};

void udt_create(udt *u) {
    u->size = 0;
}
bool udt_is_empty(const udt *u) {
    return u->size == 0;
}
void udt_push_front(udt *u, const data_type data) {
    if (u->size < UDT_MAX) {
        u->items[u->size] = data;
        u->size++;
    }else printf("size error");
}
void udt_push_back(udt *u, const data_type data) {
    if (u->size < UDT_MAX) {
        for (int i = u->size; i > 0; i--) {
            u->items[i] = u->items[i-1];
        }
        u->items[0] = data;
        u->size++;
    }else printf("size error");
}
data_type udt_pop_front(udt *u) {
    if (u->size > 0) {
        u->size--;
        return u->items[u->size];
    } else printf("size error");
    return NIL;
}
data_type udt_pop_back(udt *u) {
    if (u->size > 0) {
        data_type first = u->items[0];
        for (int i = 0; i < u->size; i++) {
            u->items[i] = u->items[i+1];
        }
        u->size--;
        return first;
    } else printf("size error");
    return NIL;
}
void udt_print(const udt *u) {
    for (int i = u->size; i > 0; i--) {
        printf("%d: %c\n", u->items[i-1].key, u->items[i-1].value);
    }
}
size_t udt_size(const udt *u) {
    return u->size;
}
void udt_insert(udt *u, const data_type data) {
    udt_push_front(u, data);
}
void udt_erase(udt *u, const key_type key) {
    int f = 0;
    for (int i = u->size - 1; i >= 0; i--) {
        if (u->items[i].key != key) continue;
        f = 1;
        for (int j = i; j < u->size-1; j++) {
            u->items[j] = u->items[j+1];
        }
        u->size--;
        break;
    }
    if (f == 0) {
        printf("Not found\n");
    }
}
