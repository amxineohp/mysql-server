#include <classes.h>

int DataPage::read() {
  isReaded = 1;
  return 0;
}

int DataPage::store() {
  ha_bddb::storePage(this);
}
