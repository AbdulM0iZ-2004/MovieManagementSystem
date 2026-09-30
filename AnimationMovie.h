#pragma once
#include "Movie.h"

class AnimationMovie : public Movie {
    int animationStyle;
    int ageGroup;
    bool isMusical;

public:
    AnimationMovie() : Movie(), animationStyle(1), ageGroup(5), isMusical(false) {}

    void displayDetails() const override;
    double calculateScore() const override;
    string getGenre() const override;

    friend istream& operator>>(istream& in, AnimationMovie& m);
};
