TableSpace::TableSpace(char* name){
  this.name = name;
}

virtual int TableSpace::extend(int size) {
  int numPages  = size * EXTENTSIZE;

  int fd = open(name, O_APPEND, bddb_create_table_umask);
  while ( numPages > 0 ) {

    numPages--;
  }
}
