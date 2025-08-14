#include <stdio.h>

#define BLOCK_SIZE 8192 // 8 KB
#define POINTER_SIZE 4 // 4 bytes
#define DIRECT_BLOCKS 12

int main() {
    long long direct_storage, single_indirect_storage, double_indirect_storage, triple_indirect_storage, total_storage;

    // Calculate direct block storage
    direct_storage = DIRECT_BLOCKS * BLOCK_SIZE;

    // Calculate single indirect block storage
    int single_indirect_pointers_per_block = BLOCK_SIZE / POINTER_SIZE;
    single_indirect_storage = single_indirect_pointers_per_block * BLOCK_SIZE;

    // Calculate double indirect block storage
    int double_indirect_pointers_per_block = BLOCK_SIZE / POINTER_SIZE;
    int double_indirect_blocks_per_pointer_block = BLOCK_SIZE / POINTER_SIZE;
    double_indirect_storage = double_indirect_pointers_per_block * double_indirect_blocks_per_pointer_block * BLOCK_SIZE;

    // Calculate triple indirect block storage
    int triple_indirect_pointers_per_block = BLOCK_SIZE / POINTER_SIZE;
    int triple_double_indirect_blocks_per_pointer_block = BLOCK_SIZE / POINTER_SIZE;
    triple_indirect_storage = triple_indirect_pointers_per_block * triple_double_indirect_blocks_per_pointer_block * double_indirect_blocks_per_pointer_block * BLOCK_SIZE;

    // Calculate total storage
    total_storage = direct_storage + single_indirect_storage + double_indirect_storage + triple_indirect_storage;

    printf("Maximum file size that can be stored in the given file system: %lld bytes\n", total_storage);

    return 0;
}