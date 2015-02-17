#include "mis.h"
#include "page.h"
#include "intstore.h"
#include <iostream>
#include <errno.h>
using namespace std;
/* tom start  */
ulint bddb_create_table_umask = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP;
int bddb_create_table_def(char* name ) {
  /* first let's create the ibd file */
  int fd;
  fd = open(name, O_WRONLY|O_CREAT, bddb_create_table_umask);
  if (fd == -1) {
    cout<<errno;
  }

  /* write the head data */
  Page* headPage       =   new Page();
  char* buf            =   new char[PAGESIZE];
  char* oldbuf        =   buf;
  buf                 +=  F_SPACE_COLUMNS_LIST;

  int numCols=0, type, index, offset=0;
  for (int i=0; i<10; i++) {  //will it end???
    numCols++;
    index = i + 1;
    intstore(buf, index, S_SPACE_COLUMN_ID);
    buf += S_SPACE_COLUMN_ID;
    type = 1;
    intstore(buf, type, S_SPACE_COLUMN_TYPE);
    buf += S_SPACE_COLUMN_TYPE;
    intstore(buf, 0, S_SPACE_COLUMN_PTR);
  }
  buf = oldbuf;
  buf += F_SPACE_NUM_COLUMNS;
  intstore(buf, numCols, S_SPACE_NUM_COLUMNS);
  buf += F_SPACE_NEXT_PAGE;
  intstore(buf, 0, S_SPACE_NEXT_PAGE);
  headPage->write(buf,PAGESIZE);
  headPage->store(fd,0);

  close(fd);
  delete[] oldbuf;
  delete headPage;
  return 0;
}

/* tom end */
int main() {
  cout<<"Test start";
  int ret = bddb_create_table_def("/tmp/test.ibd");
  cout<<"test end";
}

