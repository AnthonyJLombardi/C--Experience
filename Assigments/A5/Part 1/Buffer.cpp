#include "Buffer.h"
using namespace std;

bool Buffer::read_file() {
    ifstream file(file_name_);
    if(!file)
        return false;
    string line;
    while(getline(file, line)) {
        file_lines_.push_back(line);
    }
    file.close();
    return true;
}

bool Buffer::write_file() {
    ofstream file(file_name_);
    if(!file)
        return false;
    for(string s: file_lines_)
        file << s;
    return true;
}