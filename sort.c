#include <stdio.h>
#include <stdlib.h>

#include "udt.h"


data_type remove_max(udt *s) {
    data_type top = udt_pop_front(s);
    if (udt_is_empty(s))
        return top;
    data_type m = remove_max(s);
    if (top.key > m.key) {
        udt_push_front(s, m);
        return top;
    }
    udt_push_front(s, top);
    return m;
}
udt sort_selection(udt *src) {
    udt new;
    udt_create(&new);
    while (!udt_is_empty(src))
        udt_push_front(&new, remove_max(src));
    return new;
}

int main(void) {
    udt s; udt_create(&s);
    udt_insert(&s, (data_type){1,'A'});
    udt_insert(&s, (data_type){2,'B'});
    udt_insert(&s, (data_type){3,'C'});
    udt_print(&s);
    udt_erase(&s, 1);
    udt_print(&s);
    udt_erase(&s, 3);
    udt_print(&s);
    udt_insert(&s, (data_type){5,'K'});
    udt_insert(&s, (data_type){1,'S'});
    udt_insert(&s, (data_type){13,'P'});
    udt_insert(&s, (data_type){31,'I'});
    udt_insert(&s, (data_type){31,'O'});
    udt_insert(&s, (data_type){300,'N'});
    s = sort_selection(&s);
    printf("---------------\n");
    udt_print(&s);
    return 0;
}