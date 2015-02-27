//for space head
#define S_PAGE_PTR                  4
#define F_SPACE_NUM_COLUMNS         0
#define S_SPACE_NUM_COLUMNS         2
#define F_SPACE_FREE_LIST           F_SPACE_NUM_COLUMNS + S_SPACE_NUM_COLUMNS 
#define S_SPACE_FREE_LIST           4
#define F_SPACE_COLUMNS_LIST        F_SPACE_FREE_LIST + S_SPACE_FREE_LIST 
#define S_SPACE_COLUMN_ID           2
#define S_SPACE_COLUMN_TYPE         2
#define S_SPACE_COLUMN_PTR          4

// for space free list page
#define F_SPACE_FREE_NEXT           0
#define S_SPACE_FREE_NEXT           4
#define F_SPACE_FREE_TAIL           F_SPACE_FREE_NEXT + S_SPACE_FREE_NEXT 
#define F_SPACE_FREE_START          F_SPACE_FREE_TAIL + S_PAGE_PTR
#define S_SPACE_FREE_START          2

// for table head page
#define F_COLUMN_LAST_PAGE          0

#define ulint unsigned long 
ulint bddb_create_table_umask = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP;
