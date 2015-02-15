#define PAGESIZE 16384  //16k
#define F_SPACEID 0
#define F_PAGEID F_SPACEID + 4 
#define F_PREPAGE F_PAGEID + 4
#define F_NEXTPAGE F_PREPAGE + 4
#define F_PAGETYPE F_NEXTPAGE + 1
typedef unsigned long ulint;

class Page{
private:
  char* page;
public:
  Page(ulint size) {
    page = new char[size];
  }
  Page() {
    page = new char[PAGESIZE];
  }


  virtual int store() = 0;
  virtual int read() = 0;
  virtual ~Page() {};

}


class DataPage:public Page{
  int                     spaceid   =     0;
  ulint                   pageid    =     0;
  ulint                   nextPage;
  ulint                   prevPage;
  char                    type;
  Column**                columns;
  bool                    isReaded = 0;
public: 
  DataPage();
  int read();
  int store();
  Column**        getColumns(enum columnType);
  Column          readNextColumn(enum columnType);
  int             write(Column** columns)
  int             setID(int spaceid, ulint pageid);
private:
  int read(int spaceid, ulint pageid);
}

