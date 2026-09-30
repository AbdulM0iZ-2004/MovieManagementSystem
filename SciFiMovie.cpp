#include "SciFiMovie.h"

void SciFiMovie::displayDetails() const {
    cout << "[SciFi] " << *this << ", Tech: " << techLevel << ", Aliens: " << hasAliens << ", Year: " << futureYear << endl;
}
string SciFiMovie::getGenre() const {
    return "SciFi";
}
double SciFiMovie::calculateScore() const {
    return static_cast<int>((rating * releaseDate.daysSince() * techLevel)) % 10;
}
istream& operator>>(istream& in, SciFiMovie& m) {
    in >> static_cast<Movie&>(m);
    cout << "Enter TechLevel (1-3), Has Aliens (0/1), FutureYear: ";
    in >> m.techLevel >> m.hasAliens >> m.futureYear;
    return in;
}
