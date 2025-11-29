#include "my_malloc.h"

#include <stdio.h>
#include <string.h>

void* my_malloc(size_t bytes) {
    if (bytes == 0) {
        return NULL;
    }

    // Allocate additional bytes to store block size for freeing later.
    void* mem_block = sbrk(sizeof(size_t) + bytes);
    if (mem_block == (void*)-1) {
        return NULL;
    }

    /// Store allocation size
    *((size_t*)mem_block) = bytes;

    /// Start of user's allocation is after stored size
    return mem_block + sizeof(size_t);
}

void my_free(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    /// Read the bytes before the pointer as size_t, as those are the number of bytes allocated to this pointer
    size_t bytes_num = *((size_t*)ptr - 1);
    printf("bytes to free: %lu\n", bytes_num);

    /// temp - zero out everything
    memset(sbrk(0) - bytes_num, 0, bytes_num);

    /// free bytes of pointer + header
    void* res = sbrk(-(intptr_t)(bytes_num + sizeof(size_t)));
    if (res == (void*)-1) {
        printf("ERROR: something went wrong with free\n");
    }
}