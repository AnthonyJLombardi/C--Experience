#include "String.h"
String::String(const char cs[]) {
    buffer_ = get_new_buffer(strlen(cs));
    size_ = strlen(cs);
    for(int x = 0; x < size_; x++)
        buffer_[x] = cs[x];
}

String & String::operator+(const String & other) {
    char* tmp = get_new_buffer(size_ + other.length());
    for(int x = 0; x < size_; x++)
        tmp[x] = buffer_[x];
    int y=size_,z=0;
    while(y < size_+ other.length() && z < other.length()) {
        tmp[y] = other[z];
        y++; z++;
    }
    size_ +=other.length();
    delete[] buffer_;
    buffer_ = tmp;
    return *this;
}
String & String::operator=(const String & other) {
    delete[] buffer_;
    size_ = other.length();
    buffer_ = get_new_buffer(size_);
    for(int x = 0; x < size_; x++)
        buffer_[x] = other[x];
    return *this;
}
