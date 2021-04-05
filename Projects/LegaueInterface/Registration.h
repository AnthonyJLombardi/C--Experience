#ifndef _REGISTRATION_H_
#define _REGISTRATION_H_

#include <string>
#include "PlayerList.h"

#ifndef _CLEAR_
#define _CLEAR_
const char clear_command[] = "cls"; // for Windows
//const char clear_command[] = "clear"; // for Linux and possibly Mac's
#endif 

const std::string file_name = "registraion.txt";

class Registration {
public:
    void run();
private:
    void display_();
    std::string error_message_;
    void execute_command_(int command, bool & done);
    PlayerList player_list_;
};


#endif
