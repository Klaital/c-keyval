#ifndef LIB_KEYVAL
#define LIB_KEYVAL

#ifndef KEYVAL_ENTRY_MAX_SIZE 
#define KEYVAL_ENTRY_MAX_SIZE 128
#endif

#include <cstring>

class Entry {
    char data[KEYVAL_ENTRY_MAX_SIZE] = "";
    char sep[4] = "=";
    size_t val_head = 0;
    
public:
    Entry() = default;
    Entry(const char *k, const char* v, const char* sep);

    const char* key();
    const char* val();
    void set(const char *k, const char* v, const char* sep="=");
    void cat(char* buf);
};

#endif
