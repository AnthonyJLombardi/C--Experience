// Buffer.h

#ifndef _Buffer_h_
#define _Buffer_h_

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <map>

class Buffer
{
public:
    void display() const;
    const std::string & file_name() const { return file_name_; }
    void move_to_next_page();
    void move_to_previous_page();
    bool open(const std::string file_name);
    void set_window_height(int h) { window_height_ = h; }
    void set_line_length(int l) {line_length_ = l;}
    bool search(const std::string & s);
    bool go(const int & link_number);
    bool back();

private:
    std::vector<std::string> v_lines_;
    int ix_top_line_ = 0;
    std::string file_name_;
    int window_height_;
    int line_length_;
    std::vector<std::string> anchors_;
    std::vector<std::string> p_files_;
    void to_plain_(std::vector<std::string> words);
    bool open_(const std::string new_file_name, bool new_open);
};

inline void Buffer::move_to_next_page()
{
    ix_top_line_ += window_height_;
    if (ix_top_line_ >= v_lines_.size())
        ix_top_line_ -= window_height_;
}

inline void Buffer::move_to_previous_page()
{
    ix_top_line_ -= window_height_;
    if (ix_top_line_ < 0)
        ix_top_line_ = 0;
}

#endif
