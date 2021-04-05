#include "Player.h"

std::istream & operator>>(std::istream& in, Player& p)
{
	std::getline(in, p.first_name_);
	std::getline(in, p.last_name_);
	in >> p.year_;
	in >> p.status_;
	in.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	return in;
}
std::ostream & operator<<(std::ostream& out, const Player& p)
{
	out << p.first_name_ << std::endl;
	out << p.last_name_ << std::endl;
	out << p.year_ << std::endl;
	out << p.status_ << std::endl;
	return out;
}

void Player::display(std::ostream& out, int season_year) const
{
	out << "First Name: " << first_name_ << std::endl;
	out << "Last Name: " << last_name_ << std::endl;
	out << "Year of Birth: " << year_ << std::endl;
	std::string status;
	if (status_ != -1)
		status = status_ ? "paid" : "unpaid"; 
	out << "Status: " << status << std::endl;
	std::string cat = calculate_category_(season_year);
	out << "Category: " << cat << std::endl;
}

std::string Player::calculate_category_(int season_year) const
{
	int age = season_year - year_;
	if (age > 4 && age < 6) return "U6";
	if (age < 8) return "U8";
	if (age < 10) return "U10";
	if (age < 12) return "U12";
	if (age < 14) return "U14";
	if (age < 17) return "U17";
	return "invalid";
}
