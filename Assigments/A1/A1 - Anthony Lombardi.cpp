#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    void print(ostream & out) const {
        //@param: output stream
        //@return: prints out all variables
        out << title << endl;
        out << artist << endl;
        out << year << endl;
    }
    void read(istream & in) {
        //@param: input stream
        //@return: reads in from user input for title, artist, and year
        getline (in,title);
        getline (in,artist);
        in >> year;
    }
    bool is_equal(const Song & other) const {
        //@param: Song object
        //@return: true if the title, artist, and year match between the two songs : casing must be the same for method to work properly
        return (other.title == this->title && other.artist == this->artist && other.year == this->year);
    }
private:
    string title;
    string artist;
    int year;
};

int main() {
    //test driver
    Song s;
    s.read(cin);
    s.print(cout);
    cout << endl;
    cin.ignore();
    Song other;
    other.read(cin);
    other.print(cout);
    if(s.is_equal(other))
        cout <<  "TRUE";
    else
        cout << "FALSE";
}
