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

bool Buffer::open_(const string new_file_name, bool new_open)
{

    if (new_open)
        if(file_name_ != "")
            p_files_.push_back(file_name_);


    std::ifstream file(new_file_name);
    if (!file)
        return false;

    v_lines_.clear();
    anchors_.clear();
    // Note: the vector is cleared only after we know the file
    // opened successfully.

    vector<string> words;
    string word;

    while (file >> word)
        words.push_back(word);

    file_name_ = new_file_name;

    to_plain_(words);
    ix_top_line_ = 0;
    return true;
}

bool Buffer::open(const string new_file_name)
{
   return open_(new_file_name, true);
}

void Buffer::to_plain_(std::vector<std::string> words)
{

    /*
     * anchor_state = 0: searching for beginning of anchor
     * anchor_state = 1: searching for filename of anchor
     * anchor_state = 2: searching for end of anchor
    */
    int anchor_state = 0;
    string line;
    string file_name;

    for (std::string word: words)
    {
        if (word == "<br>")
        {
            v_lines_.push_back(line);
            line.clear();

        }
        else if (word == "<p>")
        {
            v_lines_.push_back(line);
            v_lines_.push_back("");
            line.clear();

        }
        else if (word == "<a") {
            if (anchor_state < 1)
                ++anchor_state;
        }
        else
        {
            if (anchor_state == 1)
            {
                file_name = word;
                ++anchor_state;
                continue;

            }
            else if (anchor_state == 2)
            {
                if (*(word.end() - 1) == '>')
                {
                    anchor_state = 0;
                    int anch_num = anchors_.size() + 1;
                    anchors_.push_back(file_name);
                    word.replace(word.end() - 1, word.end(), "[" + to_string(anch_num) + "]");


                }
            }

            if ((line.size() + word.size() + 1) > line_length_)
            {
                v_lines_.push_back(line);
                line.clear();
            }


            if (line.size() > 0) line += (" " + word);
            else line += word;
        }
    }
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

bool Buffer::back()
{
    if(p_files_.size() == 0)
        return false;
    std::ifstream file(p_files_.back());
    if (!file)
        return false;

    if (!open_(p_files_.back(), false))
        return false;

    p_files_.pop_back();

    return true;

}

bool Buffer::go(const int & link_number)
{
    if(anchors_.empty() || anchors_.size() < link_number)
        return false;
    if (!open_(anchors_.at(link_number-1), true))
        return false;
    return true;
}

