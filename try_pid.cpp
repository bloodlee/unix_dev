#include <sys/types.h>
#include <sys/wait.h>
#include "ourhdr.h"
#include <iostream>

using namespace std;

int main()
{
  char buf[MAXLINE];
  pid_t pid;
  int status;

  printf("%% ");

  while (fgets(buf, MAXLINE, stdin) != NULL) {
    buf[strlen(buf) - 1] = 0;

    if ((pid = fork()) < 0) {
      // err_sys("fork error");
      cerr << "fock error" << endl;
      exit(-1);
    } else if (pid == 0) {
      execlp(buf, buf, (char*)0);
      cerr << "couldn't execute: " << buf << endl;
      exit(127);
    }

    if ((pid = waitpid(pid, &status, 0)) < 0) {
      cerr << "waitpid error" << endl;
      exit(-1);
    }

    printf("%% ");
  }

  exit(0);
}
