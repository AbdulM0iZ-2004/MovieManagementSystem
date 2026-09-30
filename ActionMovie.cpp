#include "ActionMovie.h"

void ActionMovie::displayDetails() const {
    cout << "[Action] " << *this << ", Fights: " << noOfFightScenes << ", Stunts: " << hasStunts << ", Level: " << violenceLevel << endl;
}

string ActionMovie::getGenre() const {
    return "Action";
}

double ActionMovie::calculateScore() const {
    int mult = noOfFightScenes > 7 ? 2 : noOfFightScenes;
    int expl = noOfFightScenes > 5 ? 8 : 2;
    return static_cast<int>((rating * releaseDate.daysSince() * mult / expl)) % 10;
}
istream& operator>>(istream& in, ActionMovie& m) {
    in >> static_cast<Movie&>(m);
    cout << "Enter ViolenceLevel (D/M/U), NoOfFights, HasStunts (0/1): ";
    in >> m.violenceLevel >> m.noOfFightScenes >> m.hasStunts;
    return in;
}
