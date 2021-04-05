#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    //constructors
    Song(): Song("invalid", "invalid",-1) {}
    Song(string t) : Song(t,"unknown", -1) {}
    Song (string t, string a, int y) : title(t), artist(a), year(y) {}
    //method declarations
    void print(ostream & out) const;
    void read(istream & in);
    bool is_equal(const Song & other) const;
private:
    string title;
    string artist;
    int year;
};

inline void Song::print(ostream & out) const {
    //@param: output stream
    //@return: prints out all variables
    out << title << endl << artist << endl << year << endl;
}
inline void Song::read(istream & in) {
    //@param: input stream
    //@return: reads in from user input for title, artist, and year
    getline (in,title);
    getline (in,artist);
    in >> year;
}
inline bool Song::is_equal(const Song & other) const {
    //@param: Song object
    //@return: true if the title, artist, and year match between the two songs : casing must be the same for method to work properly
    return (other.title == this->title && other.artist == this->artist && other.year == this->year);
}

int main() {
    //test driver
    Song s1;
    s1.print(cout);
    Song s2("Foo Fighters");
    s2.print(cout);
    Song s3("Foo Fighters", "Watershed",1995);
    s3.print(cout);

    return 0;
}
