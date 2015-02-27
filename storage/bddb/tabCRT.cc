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
    cout<<"ERROR%%%: the error msg for open file is: "<<errno<<":"<<strerror(errno);
    exit(1);
  }

  /* write the head data */
  Page* headPage       =   new Page();
  char* buf            =   new char[PAGESIZE];
  char* oldbuf        =   buf;
  buf                 +=  F_SPACE_COLUMNS_LIST;

  // store 2 column first is int second is char
  int numCols=0, type, index, offset=0;
  //first
    numCols++;
    intstore(buf, numCols, S_SPACE_COLUMN_ID);
    buf += S_SPACE_COLUMN_ID;
    type = 1;
    intstore(buf, type, S_SPACE_COLUMN_TYPE);
    buf += S_SPACE_COLUMN_TYPE;
    intstore(buf, 0, S_SPACE_COLUMN_PTR);
  //second
    numCols++;
    intstore(buf, numCols, S_SPACE_COLUMN_ID);
    buf += S_SPACE_COLUMN_ID;
    type = 2;
    intstore(buf, type, S_SPACE_COLUMN_TYPE);
    buf += S_SPACE_COLUMN_TYPE;
    intstore(buf, 0, S_SPACE_COLUMN_PTR);
  buf = oldbuf;
  buf += F_SPACE_NUM_COLUMNS;
  intstore(buf, numCols, S_SPACE_NUM_COLUMNS);
  buf += F_SPACE_FREE_LIST;
  intstore(buf, 0, S_SPACE_FREE_LIST);
  headPage->write(buf,PAGESIZE);
  headPage->store(fd,0);

  /*write free list head page */
  Page* flHead        = new Page();
  buf                 = oldbuf;
  intstore(buf, 0, S_SPACE_FREE_NEXT);
  buf += S_SPACE_FREE_NEXT;
  intstore(buf, 0, S_PAGE_PTR);
  buf += S_PAGE_PTR;
  intstore(buf, 0, S_SPACE_FREE_START);
  buf += S_SPACE_FREE_START;
  flHead->write(buf,PAGESIZE);
  flHead->store(fd,PAGESIZE);

  close(fd);
  delete[] oldbuf;
  delete headPage;
  return 0;
}

/* tom end */

int main() {
  cout<<"Test start";
  cout<<"please enter the tabname:\n";
  string tabname;
  cin>>tabname;
  tabname = "/tmp/" + tabname;
  int ret = bddb_create_table_def("/tmp/test.ibd");
  cout<<"test end";
}

