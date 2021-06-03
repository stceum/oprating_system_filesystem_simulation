#include <iostream>

#include "fs.h"

int main() {
  //   create_disk((char *)"test_disk", 512 * (1048576));
  //   int sizes[2] = {268173304, 268173304};
  //   char *names[8] = {(char *)"p1", (char *)"p2"};
  //   create_partitions((char *)"test_disk", 2, sizes, names);

  virtual_disk test_d = read_disk((char *)"test_disk");
  // partition_format(&test_d, 1);
  fs_init(&test_d, 0);
  //   uint32_t fd = sys_open("/file1", O_CREAT);
  uint32_t fd = sys_open("/file1", O_RDWR);
//   write
    sys_write(fd, "Hello world\n", 12);
    sys_close(fd);
    std::cout << fd << " closed!" << std::endl;
  // read
//   char test[64];
//   memset(test, 0, 64);
//   sys_read(fd, test, 64);
//   std::cout << test << std::endl;
  return 0;
}