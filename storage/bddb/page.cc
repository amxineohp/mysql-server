#include "page.h"
#include "mis.h"
#include "intstore.h"
#include <string.h>

Page::Page(ulint size):page{new char[size]}, size{size} {
}

Page::Page(){
  new (this) Page(PAGESIZE);
}

Page::~Page() {
  delete[] page;
}


int Page::store(int fd, ulint offset) {
  int ret;
  if (offset !=0)
  lseek(fd, offset, 0);
  ret = ::write(fd,page,size);
  ret |= fsync(fd);
  return ret;
}

int Page::write(char* src, int size) {
    memcpy(page,src, size);
    return 0;
}


DataPage::DataPage() {
  Page();
  this->isReaded           = 0;
  this->pageid             = 0;
  this->spaceid            = 0;
  this->writeOffset        = 0;
}

int DataPage::setID(int spaceid, ulint pageid) {
  this->spaceid            = spaceid;
  this->pageid             = pageid;
  return 0;
}

int DataPage::setNextPage(ulint pageid) {
  this->nextPage           = pageid;
}
int DataPage::setPrevPage(ulint pageid) {
  this->prevPage           = pageid;
}
int DataPage::setType(char type) {
  this->type = type;
}

