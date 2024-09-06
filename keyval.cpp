#include "keyval.h"
#include <cstring>

Entry::Entry(const char* k, const char* v, const char* sep) 
{
    strcpy(this->data, k);
    strcat(this->data, " ");
    strcat(this->data, v);
    this->data[strlen(k)] = '\0';
    this->val_head = strlen(k) + 1;
}
const char *Entry::key()
{
    return this->data;
}

const char *Entry::val()
{
    return this->data+this->val_head;
}

void Entry::set(const char* line, const char sep) 
{
    strcpy(this->data, line);
    for (size_t idx=0; idx < strlen(line); idx++) {
        if (line[idx] == sep) {
            this->data[idx] = '\0';
            this->val_head = idx+1;
            break;
        }
    }
}

void Entry::set(const char *k, const char* v, const char sep)
{
    this->sep[0] = sep;
    strcpy(this->data, k);
    strcat(this->data, " ");
    strcat(this->data, v);
    this->data[strlen(k)] = '\0';
    this->val_head = strlen(k) + 1;
}

void Entry::cat(char* buf)
{
    strcat(buf, this->key());
    strcat(buf, this->sep);
    strcat(buf, this->val());
}

size_t KeyValSet::parse_line(char *line)
{
    // read a single line out of the input string, and parse a key=val entry from it.
    size_t line_end_idx = 0;
    for (line_end_idx=0; line_end_idx < strlen(line); line_end_idx++) {
        if (line[line_end_idx] == '\n') {
            break;
        }
    }
    if (line_end_idx == 0) {
        return 0;
    }

    line[line_end_idx] = '\0';
    

    this->entries[this->count].set(line);
    this->count++;
    return line_end_idx;
}

void KeyValSet::cat(char* buf) 
{
    for (size_t idx = 0; idx < this->count; idx++) 
    {
        this->entries[idx].cat(buf);
        strcat(buf, "\n");
    }
}

const char *KeyValSet::get(const char* key) 
{
    for (size_t idx=0; idx < this->count; idx++)
    {
        if (strcmp(key, this->entries[idx].key()) == 0)
        {
            return this->entries[idx].val();
        }
    }

    // not found 
    return nullptr;
}

void KeyValSet::parse(char* buf) 
{
    size_t offset = 0;
    size_t total_len = strlen(buf);
    // read the first line
    size_t bytes_read = this->parse_line(buf);
    while(bytes_read > 0)
    {
        // read the next line
        offset += bytes_read+1;
        if (offset >= total_len-1)
        {
            // we've hit the end of the line
            break;
        }
        bytes_read = this->parse_line(buf+offset+1);
    }
}
