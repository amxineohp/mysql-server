#include <my_base.h>
#define PAGESIZE 16384  //16k
class Column {
  enum          type;
  int           size;
public:
  Column(enum type);
  ~Column();
}

class Row {
  Column**      columns;
  int           numColumns;
public:
  Row();
  ~Row();

}
class Table {
  int     table_id;
  char*   table_name;
  char**  column_name
  ulint** column_type; 
  int     num_cols;

  
  Page() {


  }
  

    
}

