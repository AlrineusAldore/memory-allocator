#pragma once

#include <unistd.h>

typedef struct Header_t {
    size_t size;
    bool is_free;
} Header_t;


void* my_malloc(size_t bytes);

void my_free(void* ptr);