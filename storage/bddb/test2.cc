#include <iostream>
#include <errno.h>
#include <fcntl.h>
#define ulint unsigned long
using namespace std;
ulint bddb_create_table_umask = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP;
int main() {
  int fd = open("/tmp/test2.ibd", O_WRONLY|O_CREAT, bddb_create_table_umask);
  if (fd == -1)
    cout<<errno<<"\n";
  else
    cout<<"haha\n";
  cout<<"end\n";
}
