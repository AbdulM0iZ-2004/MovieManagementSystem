#include "AnimationMovie.h"

void AnimationMovie::displayDetails() const {
    cout << "[Animation] " << *this << ", Style: " << animationStyle << ", Age: " << ageGroup << ", Musical: " << isMusical << endl;
}
string AnimationMovie::getGenre() const {
    return "Animation";
}
double AnimationMovie::calculateScore() const {
    return static_cast<int>((rating * releaseDate.daysSince() * (ageGroup / animationStyle))) % 10;
}
istream& operator>>(istream& in, AnimationMovie& m) {
    in >> static_cast<Movie&>(m);
    cout << "Enter Style (1-3), AgeGroup (5/7/18), IsMusical (0/1): ";
    in >> m.animationStyle >> m.ageGroup >> m.isMusical;
    return in;
}
