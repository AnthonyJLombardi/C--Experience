#ifndef _SONG_H
#define _SONG_H

#include <string>
#include <iostream>
class Song {
public:
    friend bool operator==(const Song & s1, const Song & s2);
    friend std::istream & operator>>(std::istream & in, Song & s);
    friend std::ostream & operator<<(std::ostream & out, const Song & s);

    Song(): Song("invalid", "invalid",-1) {}
    Song(std::string t) : Song(t,"unknown", -1) {}
    Song (std::string t, std::string a, int y) : title_(t), artist_(a), year_(y) {}

    std::string title() const {return title_;}
    std::string artist() const {return artist_;}
    int year() const {return year_;}

    void set_title(std::string t) {title_=t;}
    void set_artist(std::string a) {artist_=a;}
    void set_year(int y) {year_=y;}
    void set(std::string t, std::string a, int y);
private:
    std::string title_;
    std::string artist_;
    int year_;
};

inline std::ostream & operator<<(std::ostream & out, const Song & s) {
    //@param: output stream and a song object passed by constant reference
    //@return: prints out all variables related to the song object
    out << s.title() << std::endl << s.artist() << std::endl << s.year() << std::endl;
    return out;
}
inline void Song::set(std::string t, std::string a, int y) {
    title_=t;
    artist_=a;
    year_=y;
}

inline bool operator==(const Song & s1, const Song & s2) {
    //@param: two songs passed as constant reference
    //@return: returns true if the title, artist, and year of a song object are all exactly the same
    return (s1.title() == s2.title()) && (s1.artist() == s2.artist()) && (s1.year() == s2.year());
}

#endif
