#include <unistd.h>
#include <iostream>
#include <cstdlib>

using namespace std;

#define BUFFSIZE 8192

int main(void) {
  int n;
  char buf[BUFFSIZE];

  while ( (n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      cerr << "write error" << endl;
      exit(1);
    }
  }

  if (n < 0) {
    cerr << "read error" << endl;
    exit(1);
  }

  exit(0);
}
