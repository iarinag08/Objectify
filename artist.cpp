#include "artist.hpp"

Artist::Artist(const std::string& _nume, int _ascultatori)
    : nume(_nume), ascultatori(_ascultatori) {}

const std::string& Artist::getNume() const { return nume; }

std::ostream& operator<<(std::ostream& os, const Artist& a) {
    os << a.nume << " (" << a.ascultatori << " ascultatori lunari)";
    return os;
}