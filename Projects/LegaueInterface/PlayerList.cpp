#include "PlayerList.h"

// modifiers 
bool PlayerList::add(Player & p)
{
    auto result = m_.insert({p.first_name() + p.last_name(), p});
	if (result.second) 
	{
		itr_current_entry_ = result.first;
		return true;
	}
	
	return false;   
}

bool PlayerList::edit_current(const Player & p)
{
	if (m_.empty())
		return false;
		
    m_[p.first_name() + p.last_name()] = p;
    m_.erase(itr_current_entry_);
    itr_current_entry_ = m_.find(p.first_name() + p.last_name());
	return true;
}
    
    
// I/O method
void PlayerList::read_file(const string & filename)
{
    clear_players();
    ifstream in(filename);
    in >> year_;
    Player p; 
    while(in >> p)
        add(p);
}

void PlayerList::write_file(const string & filename) const
{
    ofstream out(filename);
    out << year_ << std::endl;
    for(auto pair : m_)
    	out << pair.second;   
    
}

// element access
void PlayerList::move_to_next()
{
    if(m_.empty())
        return;
    if(itr_current_entry_ == next(m_.end(), -1))
        itr_current_entry_ = m_.begin();
    else 
		++itr_current_entry_;
    
}
void PlayerList::move_to_previous()
{
    if(m_.empty())
        return;
    if(itr_current_entry_ == m_.begin())
        itr_current_entry_ = m_.end();
    else
        --itr_current_entry_;
}

// operations
bool PlayerList::find(const Player & p)
{
    auto itr = m_.find(p.first_name() + p.last_name());
    if(itr != m_.end())
        itr_current_entry_ = itr;
        return true;
    return false;
}

PlayerList PlayerList::filter(const Player & p) const
{
    PlayerList newList;
    for(auto pair : m_)
    {
        bool criteriaMet;
        if(pair.second.first_name() != p.first_name() && p.first_name() != "")
            criteriaMet = false;
        if(pair.second.last_name() != p.last_name() && p.last_name() != "")
            criteriaMet = false;
        if(pair.second.year() != p.year() && p.year() != -1)
            criteriaMet = false;
        if(pair.second.status() != p.status())
            criteriaMet = false;

        if(criteriaMet)
            newList.m_[pair.second.first_name()+pair.second.last_name()] = pair.second;
    }
    return newList;

}
