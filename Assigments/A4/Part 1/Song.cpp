#include "Song.h"
#include <iostream>
using namespace std;

istream & operator>>(istream & in, Song & s) {
    //@param: an input stream and a song passed by reference
    //@return: reads in user input from an input stream and sets the corresponding values into the song object
    getline(in,s.title_);
    getline(in, s.artist_);
    in >> s.year_;
    in.ignore();
    return in;
}
