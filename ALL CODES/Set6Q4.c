#include <stdio.h>

int main() {
  int block_size = 8192; // 8 KB
  int ptr_size = 4; // 4 bytes
  int direct_blocks = 12;
  int single_indirect = block_size / ptr_size; // 2048 blocks
  int double_indirect = single_indirect * single_indirect; // 4194304 blocks  
  int triple_indirect = double_indirect * single_indirect; // 879609302016 blocks
  
  long int max_size = direct_blocks * block_size; // 98304 bytes
  max_size += single_indirect * block_size; // 16777216 bytes 
  max_size += double_indirect * block_size; // 34359738368 bytes
  max_size += triple_indirect * block_size; // 72057594037927936 bytes
  
  printf("Maximum file size is %ld bytes\n", max_size);

  return 0;
}