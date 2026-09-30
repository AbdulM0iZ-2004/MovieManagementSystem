#pragma once
#include "Movie.h"

class ActionMovie : public Movie {
    char violenceLevel;
    int noOfFightScenes;
    bool hasStunts;

public:
    ActionMovie() : Movie(), violenceLevel('D'), noOfFightScenes(0), hasStunts(false) {}

    void displayDetails() const override;
    double calculateScore() const override;
    string getGenre() const override;

    friend istream& operator>>(istream& in, ActionMovie& m);

};
