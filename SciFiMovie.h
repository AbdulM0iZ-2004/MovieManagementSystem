#pragma once
#include "Movie.h"

class SciFiMovie : public Movie {
    int techLevel;
    bool hasAliens;
    int futureYear;

public:
    SciFiMovie() : Movie(), techLevel(1), hasAliens(false), futureYear(0) {}

    void displayDetails() const override;
    double calculateScore() const override;
    string getGenre() const override;

    friend istream& operator>>(istream& in, SciFiMovie& m);
};
