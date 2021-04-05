#ifndef _PLAYER_LIST_H_
#define _PLAYER_LIST_H_

#include<iostream>
#include<string>
#include<map>
#include<fstream>

#include"Player.h"

using namespace std;

class PlayerList
{
public:
	
    PlayerList() : itr_current_entry_(m_.begin()), year_(1990) {}
    PlayerList(const PlayerList & new_player_list) : m_(new_player_list.m_), itr_current_entry_(new_player_list.itr_current_entry_), year_(new_player_list.year_) {}
    
    // year methods
    
	void set_new_year(const int & year) { year_ = year; }
    int get_year() const { return year_; }
    
	// capacity
	bool empty() const { return m_.empty(); }
	void clear_players();
	
	// modifiers
	bool add(Player & p);
	bool edit_current(const Player & p);
	bool remove_current();
	
	// I/O methods
    void display_current_player() const;
    void read_file(const string & filename);
    void write_file(const string & filename) const;
    
    // element access
    void move_to_next();
    void move_to_previous();
    Player get_current() const { return itr_current_entry_->second; }
    
    
    // operations
    bool find(const Player & p);
    PlayerList filter(const Player & p) const;

private:
    map<string, Player> m_;
    map<string, Player>::iterator itr_current_entry_;
    int year_;
};

// capacity
inline void PlayerList::clear_players()
{
    m_.clear();
    itr_current_entry_ = m_.begin();
}

// modifiers
inline void PlayerList::remove_current()
{
    auto temp = next(itr_current_entry_, 1);
    m_.erase(itr_current_entry_);
    itr_current_entry_ = temp;
}

// I/O methods
inline void PlayerList::display_current_player() const
{
    if(m_.empty())
        std::cout << "no available player" << std::endl;
    itr_current_entry_->second.display(std::cout, year_);
}







#endif // PLAYER_LIST_INCLUDED
