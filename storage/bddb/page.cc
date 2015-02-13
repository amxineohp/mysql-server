#define PAGESIZE 16384  //16k
#define F_SPACEID 0
#define F_PAGEID F_SPACEID + 4 
#define F_PREPAGE F_PAGEID + 4
#define F_NEXTPAGE F_PREPAGE + 4
#define F_PAGETYPE F_NEXTPAGE + 1

class Page {
  int     spaceid;
  int     pageid;
  byte*   type; 
  byte*   page[PAGESIZE];
  
  Page() {


  }
  

    
}

