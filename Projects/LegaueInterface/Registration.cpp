#include <iostream>
#include <chrono>
#include <thread>
#include "Registration.h"
#include "SearchInterface.h"
#include "PlayerInterface.h"
#include "FilterInterface.h"

using namespace std;

void Registration::run() {
    player_list_.read_file(file_name);
    bool done = false;
    while(!done) {
        display_();
        cout << "command: ";
        int command;
        cin >> command;
        cin.get();
        execute_command_(command, done);
        cout << endl;
    }
}

void Registration::display_() {
    string long_separator(50, '-');
    string short_separator(8, '-');

    system(clear_command);
	
	cout << "Summer Soccer League Registration" << endl;
	cout << "Season: " << player_list_.get_year() << endl;
	cout << "Search Window" << endl;
	if (!error_message_.empty()) 
	{
        std::cout << "ERROR: " + error_message_ << std::endl;
        error_message_.clear();
    } else 
    {
    	std::cout << std::endl;
	}
	cout << long_separator;
	
    player_list_.display_current_player();

    cout << long_separator << endl;
	cout << "1| Previous  2| Next  3| Add   4| Delete\n";
    cout << "5| Edit  6| Search 7| New Season 8| Print\n";
    cout << "9| Statistics 10| Quit " << endl;
	cout << short_separator;
}

void Registration::execute_command_(int command, bool &done) {
    switch (command) {
        case 1: 
		{
            player_list_.move_to_previous();
            break;
        }
        case 2: 
		{
            player_list_.move_to_next();
            break;
        }
        case 3: 
		{
        	PlayerInterface player_interface(player_list_.get_year());
            Player new_player = player_interface.run();
			if (new_player.valid())
				player_list_.add(new_player);
            break;
        }
        case 4: 
		{
            cout << "Are you sure you would like to remove the current player? [y/n]:";
            char ans;
            cin >> ans;
            cin.get();
             if (ans == 'y') {
                player_list_.remove_current();
                break;
            }
			else if (ans != 'n' ) 
			{
				error_message_ = "invalid response to [y/n]";
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				}
			}
            break;
        }
        case 5: 
		{
            PlayerInterface player_interface(player_list_.get_current(), player_list_.get_year());
            Player player = player_interface.run();
			if (player.valid())
				player_list_.add(player);
            break;
        }
        case 6: 
		{
            FilterInterface filter_interface(player_list_.get_year());
            Player filter = filter_interface.run();
            if (filter.valid()) {
            	PlayerList filter_list = player_list_.filter(filter);
            	SearchInterface search_interface(filter_list);
            	bool exit = search_interface.run();
            	if(exit)
				{
		            player_list_.write_file(file_name);
		            done = true;
		        }
			}
            break;
        }
        case 7: 
		{
            cout << "Are you sure you would like to start a new season (this will delete all existing players)? [y/n]:";
            char ans;
            cin >> ans;
            cin.get();
            if (ans == 'y') {
                cout << endl << "please enter the year of the current season: ";
                int new_year;
                cin >> new_year;
                cin.get();
                player_list_.set_new_year(new_year);
                player_list_.clear_players();
                break;
            } 
			else if (ans != 'n' ) 
			{
				error_message_ = "invalid response to [y/n]";
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				}
			}
            break;
        }
        case 8:
		{
            cout << "Please enter the filename: ";
            string file_name;
            getline(cin, file_name);
            player_list_.write_file(file_name);
            break;
        }
        case 9: 
		{
            //stats shit
            break;
        }
        case 10: 
		{
            player_list_.write_file(file_name);
            done = true;
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
