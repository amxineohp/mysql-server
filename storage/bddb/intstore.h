#define intstore(d, s, l) do {  switch (l) { \
                                case(2):  int2store(d,s); \
                                case(4):  int4store(d,s); \
                                case(5):  int5store(d,s); \
                                case(6):  int6store(d,s); \
                                case(8):  int8store(d,s); \
                              }; \
                           } while (0) 
