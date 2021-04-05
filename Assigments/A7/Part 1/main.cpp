#include "Book.h"
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

typedef map<string, book> BookMap;

bool read_books(BookMap & m_books, const string & file_name) {
    ifstream file(file_name);
    if(!file)
        return false;
    book b;
    while(file >> b)
        m_books.insert(pair<string, book>(b.get_title(), b));
    return true;
}

void print_recent(const BookMap & m_books, const int & year) {
    for(auto x: m_books) {
        if(x.second.get_year() >= year)
            cout << x.second;
    }
}

int main() {
    BookMap m_books;
    read_books(m_books,"TEST.txt");
    print_recent(m_books, 1937);
}