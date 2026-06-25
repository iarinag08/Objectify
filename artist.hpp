#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <string>
#include <iostream>
#include <vector>

class Artist {
private:
    std::string nume;
    int ascultatori;

public:
    explicit Artist(const std::string& _nume = "Unknown", int _ascultatori = 0);
    const std::string& getNume() const;
    friend std::ostream& operator<<(std::ostream& os, const Artist& a);
};

template <typename T>
class Catalog {
private:
    std::vector<T> elemente;
public:
    void adauga(const T& element) {
        elemente.push_back(element);
    }
    void afiseazaCatalog() const {
        for (const auto& el : elemente) {
            std::cout << el << "\n";
        }
    }
};

#endif