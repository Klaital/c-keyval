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

void Entry::set(const char *k, const char* v, const char* sep)
{
    strcpy(this->sep, sep);
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
