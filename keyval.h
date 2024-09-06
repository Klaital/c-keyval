#ifndef LIB_KEYVAL
#define LIB_KEYVAL

#ifndef KEYVAL_ENTRY_MAX_SIZE 
#define KEYVAL_ENTRY_MAX_SIZE 128
#endif

#ifndef KEYVAL_MAX_ENTRIES
#define KEYVAL_MAX_ENTRIES 20
#endif

#include <cstring>

class Entry {
    char data[KEYVAL_ENTRY_MAX_SIZE] = "";
    char sep[2] = "=";
    size_t val_head = 0;
    
public:
    Entry() = default;
    Entry(const char *k, const char* v, const char* sep);

    const char* key();
    const char* val();
    void set(const char *k, const char* v, const char sep);
    void set(const char *line, const char sep='=');
    void cat(char* buf);

    bool as_bool();
};

class KeyValSet {
    Entry entries[KEYVAL_MAX_ENTRIES];
    size_t count = 0;
    char sep[2] = "=";

public:
    KeyValSet() = default;
    KeyValSet(const char sep) {this->sep[0] = sep;}

    size_t parse_line(char* line);
    void cat(char* buf);
    size_t length() const {return this->count;}

    void parse(char* buf);
    const char* get(const char* key);
    bool get_bool(const char* key);
};

#endif
