#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <algorithm>
#include <iostream>
#include <initializer_list>

class String {
public:
    String(buffer_(nullptr), size_(0)); //:  {}
    explicit String(const char cs[]);

    ~String() { delete[] buffer_; }

    int length() const {return size_;}
    void clear();

    char* c_str() {return buffer_;}

    char & operator[](int i) { return buffer_[i]; }
    const char & operator[](int i) const { return buffer_[i]; }
    String & operator+(const String & other);
    String & operator=(const String & other);
    friend std::ostream &operator<<(std::ostream & out, const String & s);
private:
    char * buffer_;
    int size_;
    char * get_new_buffer(int n) const;
};

inline char * String::get_new_buffer(int n) const
{
    return (n == 0 ? nullptr : new char[n]());
}
inline void String::clear() {
    delete[] buffer_;
    buffer_ = nullptr;
    size_ = 0;
}
inline std::ostream &operator<<(std::ostream & out, const String & s) {
    for(int x = 0; x < s.size_; x++)
        out << s.buffer_[x];
    return out;
}
#endif
