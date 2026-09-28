
#ifndef LAB26_UDT_H
#define LAB26_UDT_H

#include <stdbool.h>
#include <stddef.h>

#define UDT_MAX 64

typedef int  key_type;
typedef char value_type;

typedef struct {
    key_type   key;
    value_type value;
} data_type;
extern const data_type NIL;
typedef struct {
    data_type items[UDT_MAX];
    size_t    size;
} udt;
void udt_create(udt *);
bool udt_is_empty(const udt *);
void udt_push_front(udt *, const data_type);
void udt_push_back(udt *, const data_type);
data_type udt_pop_front(udt *);
data_type udt_pop_back(udt *);
void   udt_print(const udt *);
size_t udt_size(const udt *);
void   udt_insert(udt *, const data_type);
void   udt_erase(udt *, const key_type);
#endif //LAB26_UDT_H