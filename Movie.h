#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date {
    int day, month, year;
public:
    Date() : day(1), month(1), year(2000) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    int daysSince() const { 
        return year * 365 + month * 30 + day; 
    }

    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
};

class Name {
    string first, last;
public:
    Name() : first(""), last("") {}
    Name(string f, string l) : first(f), last(l) {}

    friend ostream& operator<<(ostream& out, const Name& n);
    friend istream& operator>>(istream& in, Name& n);
};

class Director {
    Name name;
    int experience;
    string nationality;
public:
    Director() : name(), experience(0), nationality("") {}

    friend ostream& operator<<(ostream& out, const Director& d);
    friend istream& operator>>(istream& in, Director& d);
};

class Movie {
protected:
    string title;
    Date releaseDate;
    double rating;
    Director* director;

public:
    Movie() : title(""), releaseDate(), rating(0.0), director(nullptr) {}
    virtual ~Movie() {}
    virtual void displayDetails() const = 0;
    virtual double calculateScore() const = 0;
    virtual string getGenre() const = 0;

    void setDirector(Director* d);
    string getTitle() const;
    double getRating() const;
    Date getDate() const;

    friend ostream& operator<<(ostream& out, const Movie& m);
    friend istream& operator>>(istream& in, Movie& m);
};
