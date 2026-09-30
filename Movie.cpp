#include "Movie.h"

// Date
ostream& operator<<(ostream& out, const Date& d) {
    out << d.day << "/" << d.month << "/" << d.year;
    return out;
}
istream& operator>>(istream& in, Date& d) {
    in >> d.day >> d.month >> d.year;
    return in;
}

//Name
ostream& operator<<(ostream& out, const Name& n) {
    out << n.first << " " << n.last;
    return out;
}
istream& operator>>(istream& in, Name& n) {
    in >> n.first >> n.last;
    return in;
}

//Director
ostream& operator<<(ostream& out, const Director& d) {
    out << d.name << ", Exp: " << d.experience << " yrs, " << d.nationality;
    return out;
}
istream& operator>>(istream& in, Director& d) {
    cout << "Enter First and Last Name: ";
    in >> d.name;
    cout << "Experience (years) and Nationality: ";
    in >> d.experience >> d.nationality;
    return in;
}

void Movie::setDirector(Director* d) { director = d; }
string Movie::getTitle() const { return title; }
double Movie::getRating() const { return rating; }
Date Movie::getDate() const { return releaseDate; }

ostream& operator<<(ostream& out, const Movie& m) {
    out << "Title: " << m.title << ", Date: " << m.releaseDate << ", Rating: " << m.rating;
    if (m.director) out << ", Director: " << *m.director;
    return out;
}
istream& operator>>(istream& in, Movie& m) {
    cout << "Enter Title: ";
    in.ignore();
    getline(in, m.title);
    cout << "Enter Release Date (dd mm yyyy): ";
    in >> m.releaseDate;
    cout << "Enter Rating: ";
    in >> m.rating;
    return in;
}
