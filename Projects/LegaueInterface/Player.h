#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <string>
#include <limits>

class Player {

public:
	Player() : first_name_(), last_name_(), year_(1990), status_(-1), valid_(true) {}

	Player(const Player & other) : first_name_(other.first_name_), last_name_(other.last_name_), year_(other.year_), status_(other.status_) {}

	std::string first_name() const { return first_name_; }
	std::string last_name()  const { return last_name_; }
	int year() const { return year_; }
	int status() const { return status_; }
	bool valid() const { return valid_; }

	void set_first_name(const std::string & new_first_name) { first_name_ = new_first_name; }
	void set_last_name(const std::string & new_last_name) { last_name_ = new_last_name; }
	void set_year(int new_year) { year_ = new_year; }
	void set_status(int new_status) { status_ = new_status; }
	void set_valid(int new_valid) { valid_ = new_valid; }
	
	void display(std::ostream& out, int season_year) const;
	
	friend std::istream & operator>>(std::istream& in, Player& p);
	friend std::ostream & operator<<(std::ostream& out, const Player& p);
	
private:
	std::string first_name_;
	std::string last_name_;
	int year_;
	int status_;
	bool valid_;
	
	std::string calculate_category_(int season_year) const;
};



#endif
