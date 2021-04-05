#ifndef BUFFER_H
#define BUFFER_H


#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Buffer {
public:
    void get_filename();
    bool read_file();
    void sort_file();
    bool write_file();
private:
    std::vector<std::string> file_lines_;
    std::string file_name_;
};

inline void Buffer::get_filename() {
    std::cout << "Please Enter The Name Of The File You Would Like Sorted: " << std::endl;
    std::getline(std::cin, file_name_);
}

inline void Buffer::sort_file() {
    std::sort(file_lines_.begin(),file_lines_.end());
}

#endif
