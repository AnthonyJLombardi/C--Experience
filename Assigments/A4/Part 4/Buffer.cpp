// Buffer.cpp

#include "Buffer.h"
#include <algorithm>
using namespace std;

void Buffer::display() const
{
    int ix_stop_line_ = ix_top_line_ + window_height_;
    for (int i = ix_top_line_; i < ix_stop_line_; ++i) {
        if (i < v_lines_.size())
            cout << std::setw(6) << i+1 << "  " << v_lines_[i];
        cout << '\n';
    }
}

bool Buffer::open(const string & new_file_name)
{
    std::ifstream file(new_file_name);
    if (!file)
        return false;

    v_lines_.clear();
    // Note: the vector is cleared only after we know the file
    // opened successfully.

    string line;
    while (getline(file, line))
        v_lines_.push_back(line);

    file_name_ = new_file_name;
    ix_top_line_ = 0;
    return true;
}

bool Buffer::search(const string & s) {
    //@param: takes one string passed by constant reference
    //@return: returns true if the s is found in one of the files lines from the top one being displayed and false if it is not found
    for(int x = ix_top_line_; x<v_lines_.size(); x++) {
        if(v_lines_.at(x).find(s) != string::npos) {
            ix_top_line_ = x;
            return true;
        }
    }
    return false;
}

