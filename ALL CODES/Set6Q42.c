#include <stdio.h>

#define BLOCK_SIZE 8192  // 8 KB in bytes
#define POINTER_SIZE 4    // Size of a pointer to a disk block in bytes

#define DIRECT_BLOCKS 12
#define SINGLE_INDIRECT_BLOCKS (BLOCK_SIZE / POINTER_SIZE)
#define DOUBLE_INDIRECT_BLOCKS (SINGLE_INDIRECT_BLOCKS * SINGLE_INDIRECT_BLOCKS)
#define TRIPLE_INDIRECT_BLOCKS (DOUBLE_INDIRECT_BLOCKS * SINGLE_INDIRECT_BLOCKS)

#define INODE_SIZE (3 * POINTER_SIZE + DIRECT_BLOCKS * POINTER_SIZE)

// Function to calculate the maximum size of a file that can be stored in the file system
long long calculateMaxFileSize() {
    // Calculate the maximum size based on the available blocks
    long long maxFileSize =
        DIRECT_BLOCKS * BLOCK_SIZE +
        SINGLE_INDIRECT_BLOCKS * BLOCK_SIZE +
        DOUBLE_INDIRECT_BLOCKS * BLOCK_SIZE * BLOCK_SIZE / POINTER_SIZE +
        TRIPLE_INDIRECT_BLOCKS * BLOCK_SIZE * BLOCK_SIZE * BLOCK_SIZE / (POINTER_SIZE * POINTER_SIZE);

    return maxFileSize;
}

int main() {
    long long maxFileSize = calculateMaxFileSize();

    // Print the result
    printf("Maximum size of a file that can be stored in the file system: %lld bytes\n", maxFileSize);

    return 0;
}
