#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>

int main() {
  std::printf("process id %d\n", getpid());
  std::exit(0);
}
