#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <string>
#include <iostream>

class Artist {
private:
    std::string nume;
    int ascultatori;

public:
    explicit Artist(const std::string& _nume = "Unknown", int _ascultatori = 0);
    const std::string& getNume() const;
    friend std::ostream& operator<<(std::ostream& os, const Artist& a);
};

#endif