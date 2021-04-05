#ifndef _SEARCHINTERFACE_H_
#define _SEARCHINTERFACE_H_

#include "PlayerList.h"

#ifndef _CLEAR_
#define _CLEAR_
const char clear_command[] = "cls"; // for Windows
//const char clear_command[] = "clear"; // for Linux and possibly Mac's
#endif 

class SearchInterface {
public:
    SearchInterface(const PlayerList & new_player_list) : player_sub_list_(new_player_list) {}
    bool run();
private:
	std::string error_message_;
    PlayerList player_sub_list_;
    
    void display_();
    bool execute_command_(int command, bool & done, bool & exit);
    
};

#endif
