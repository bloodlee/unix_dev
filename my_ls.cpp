#include <sys/types.h>
#include <dirent.h>

#include <iostream>
#include <cstdlib>

using namespace std;

int
main(int argc, char* argv[])
{
  DIR* dp;
  struct dirent* dirp;

  if (argc != 2) {
    cerr << "a single argument (the directory name) is required" << endl;
    exit(1);
  }

  if ((dp = opendir(argv[1])) == NULL) {
    cerr << "Can't open " << argv[1] << endl;
    exit(1);
  }

  while ((dirp = readdir(dp)) != NULL) {
    cout << dirp->d_name << endl;
  }

  closedir(dp);
  exit(0);
}



