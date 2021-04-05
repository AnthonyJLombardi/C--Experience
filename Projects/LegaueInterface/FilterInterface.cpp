#include "FilterInterface.h"

void FilterInterface::display_()
{
    const std::string long_separator(50, '-');
    const std::string short_separator(8, '-');

    system(clear_command);
    std::cout << "Summer Soccer League Registration" << std::endl;
    std::cout << "Season: " << season_year_ << std::endl;
	std::cout << "Filter for Player" << std::endl;
    if (!error_message_.empty()) 
	{
        std::cout << "ERROR: " + error_message_ << std::endl;
        error_message_.clear();
    } else 
    {
    	std::cout << std::endl;
	}
	std::cout << long_separator << std::endl;
    player_.display(std::cout, season_year_);
    std::cout << long_separator << std::endl;
    std::cout << "  (1) First Name (2) Last Name  (3) Year of Birth (4) Registration Status (5) Search (6) Cancel" << std::endl;
    std::cout << short_separator << std::endl;
}

void FilterInterface::execute_command_(int command, bool & done, bool & search)
{
    switch (command) 
	{
        case 1: 
		{
            std::cout << "First Name: ";
            std::string first_name;
            getline(std::cin, first_name);
            player_.set_first_name(first_name);
            break;
        }

        case 2: 
		{
            std::cout << "Last Name: ";
            std::string last_name;
            getline(std::cin, last_name);
            player_.set_last_name(last_name);
            break;
        }

        case 3: 
		{
            std::cout << "Year of Birth: ";
            int year;
            std::cin >> year;
            int age = season_year_ - year;
            if (std::cin.fail()) 
            {
            	error_message_ = "input was not an integer";
            	std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			} 
			else
			{
				if (age < 4 || age > 16) error_message_ = "invalid age. players must be between 4 and 16 (inclusive)";  
				else player_.set_year(year);	
			}
            
            break;
        }

        case 4: 
		{
            std::cout << "Status (paid or unpaid): ";
            std::string status;
            getline(std::cin, status);
            if (status == "paid") player_.set_status(1);
            else if (status == "unpaid") player_.set_status(0);
            else error_message_ = "invalid status. valid statuses are paid and unpaid";
            break;
        }
        
        case 5:
        {
        	bool criteria;
        	if (!player_.first_name().empty()) criteria = true;
        	if (!player_.last_name().empty()) criteria = true;
        	if (player_.status() != -1) criteria = true;
        	int age = season_year_ - player_.year();
        	if (age >= 4 && age <= 16) criteria = true;
			if (criteria)
			{
				done = true; search = true; 
			} 
			else
			{
				error_message_ = "include at least one search criteria";
			}
        	break;
		}
        	
		case 6:
		{
			done = true; search = false;
			break;
		}
		
		default:
		{
			error_message_ = "invalid command";
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			}
			break;
		}
		
		 

    }
}

Player FilterInterface::run()
{

    bool done = false;
    bool search = false;
    while (!done) 
	{
        display_();

        std::cout << "command: ";
        int command;
        std::cin >> command;
        std::cin.get();

        execute_command_(command, done, search);

        std::cout << std::endl;
    }
    
    
    player_.set_valid(search);
    
    return player_;
    
}
