#include "table.h"
#include "mis.h"
#include "my_base.h"
#define PAGESIZE 16384  //16k
#define F_SPACEID 0
#define F_PAGEID F_SPACEID + 4 
#define F_PREPAGE F_PAGEID + 4
#define F_NEXTPAGE F_PREPAGE + 4
#define F_PAGETYPE F_NEXTPAGE + 1

class Page {
private:
  char* page;
  int   size;
public:

  Page(ulint size); 
  Page(); 
  ~Page();
  virtual int store(int fd, ulint offset);
  //virtual int setZero(); virtual int read() ;
  virtual int write(char* src, int size); 
};


class DataPage:public Page {
  int                     spaceid;
  ulint                   pageid;
  ulint                   nextPage;
  ulint                   prevPage;
  char                    type;
  int                     writeOffset;
  bool                    isReaded;
public: 
  DataPage();
  int             read();
  int             readColumns();
  int             readColumn(int offset);
  int             writeColumns();
  int             setID(int spaceid, ulint pageid);
  int             setType(char type); 
  int             setNextPage(ulint pageid); 
  int             setPrevPage(ulint pageid); 
private:
  int read(int spaceid, ulint pageid);
};

