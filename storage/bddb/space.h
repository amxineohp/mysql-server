#include "my_base.h"

class TableSpace {
  int           id;
  char*         name;
  ulint         freelist;
  mutex         mfl;
  mutex         mhead;
  Page*         headPage;

public:
  TableSpace(char* name);
  virtual int extend(int size);
  virtual int lock_freelist();
  virtual int lock_head();
  virtual int getfd();

}

