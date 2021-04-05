#include <string>
#include <iostream>
#ifndef BOOK_H
#define BOOK_H
class book {
public:
    friend std::istream & operator>>(std::istream & in, book & b);
    friend std::ostream & operator<<(std::ostream & out, const book & b);
    inline std::string get_title() {return title_;}
    inline int get_year() {return year_;}
private:
    std::string title_;
    std::string author_;
    int year_;
};

inline std::istream & operator>>(std::istream & in, book & b) {
    getline(in,b.title_);
    getline(in, b.author_);
    in >> b.year_;
    in.get();
    return in;
}

inline std::ostream & operator<<(std::ostream & out, const book & b) {
    out << b.title_ << std::endl << b.author_ << std::endl << b.year_ << std::endl;
    return out;
}
#endif
