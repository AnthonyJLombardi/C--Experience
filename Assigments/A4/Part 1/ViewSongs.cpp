#include <string>
#include <fstream>
#include "Song.h"
#include <iostream>
#include <istream>

using namespace std;

void wait() {
    cout<<"Press ENTER to continue:"<< endl;
    cin.ignore(1);
}
bool read_songs(const string & fileName) {
    //@param: a filename passed by constant reference
    //@return: returns true if there are no errors, false other wise
    fstream file(fileName);
    if(!file) {
        cout << "ERROR: reading file";
        return false;
    }
    Song s1;
    file >> s1;
    if(file.eof()) {
        cout<< "No songs to display";
        return true;
    }
    cout << s1;
    while(file >> s1) {
        wait();
        cout << s1 << endl;
        //wait();
    }
    cout << "There are no more songs to display";
    return true;
}
string get_filename(ostream & out, istream & in) {
    //@param: output and input streams
    //@return: returns the filename
    out << "Enter File Name:" << endl;
    string tmp;
    getline(in, tmp);
    return tmp;
}
void run() {
    read_songs(get_filename(cout, cin));
}