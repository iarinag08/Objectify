#include "abonament.hpp"
#include "exceptions.hpp"

Abonament::Abonament(const std::string& _cod) : cod(_cod) {}

void Abonament::afisare(std::ostream& os) const {
    os << "Cod [" << cod << "] ";
    print(os);
    os << " | Cost: " << calculeazaPret() << " EUR";
}

AbonamentPremium::AbonamentPremium() : Abonament("PREM-888") {}
Abonament* AbonamentPremium::clone() const { return new AbonamentPremium(*this); }
double AbonamentPremium::calculeazaPret() const { return 8.99; }
void AbonamentPremium::print(std::ostream& os) const { os << "Tip: PREMIUM"; }

AbonamentFamily::AbonamentFamily(int membri) : Abonament("FAM-555"), nrMembri(membri) {
    if (membri < 2 || membri > 6) throw MembriInvaliziException();
}
int AbonamentFamily::getNrMembri() const { return nrMembri; }
Abonament* AbonamentFamily::clone() const { return new AbonamentFamily(*this); }
double AbonamentFamily::calculeazaPret() const { return 12.0 + nrMembri; }
void AbonamentFamily::print(std::ostream& os) const { os << "Tip: FAMILY (" << nrMembri << " membri)"; }

AbonamentFree::AbonamentFree() : Abonament("FREE-001") {}
Abonament* AbonamentFree::clone() const { return new AbonamentFree(*this); }
double AbonamentFree::calculeazaPret() const { return 0.0; }
void AbonamentFree::print(std::ostream& os) const { os << "Tip: FREE (cu reclame)"; }

AbonamentStudent::AbonamentStudent() : Abonament("STUD-202") {}
Abonament* AbonamentStudent::clone() const { return new AbonamentStudent(*this); }
double AbonamentStudent::calculeazaPret() const { return 3.50; }
void AbonamentStudent::print(std::ostream& os) const { os << "Tip: STUDENT (Reducere 60%)"; }

Abonament* AbonamentFactory::creareAbonament(const std::string& tip, int membri) {
    if (tip == "Premium") return new AbonamentPremium();
    if (tip == "Family") return new AbonamentFamily(membri);
    if (tip == "Student") return new AbonamentStudent();
    return new AbonamentFree();
}