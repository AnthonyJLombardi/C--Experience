#include "SortFile.h"
using namespace std;

void SortFile::run() {
    b_.get_filename();
    if(!b_.read_file())
        cout << "ERROR: reading from file";
    b_.sort_file();
    if(!b_.write_file())
        cout << "ERROR: writing to file";
}

int main() {
    SortFile s;
    s.run();

    return 0;
}