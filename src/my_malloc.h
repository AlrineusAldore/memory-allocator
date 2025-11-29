#pragma once

#include <unistd.h>

/// Union to align memory. In actuality, only use struct Header.
typedef union MemBlock {
    struct {
        size_t size;
        bool is_free;
        union MemBlock* next;
    } header;

    /// Only here to make memory block align with biggest size type, not to actually use it.
    long double alignment;
} MemBlock;


void* my_malloc(size_t bytes);

void my_free(void* ptr);