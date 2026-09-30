#include "SciFiMovie.h"
#include "AnimationMovie.h"
#include "ActionMovie.h"
#include <iostream>
using namespace std;

void bubbleSortMovies(Movie* movies[], int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (movies[j]->getDate().daysSince() > movies[j + 1]->getDate().daysSince()) {
                swap(movies[j], movies[j + 1]);
            }
        }
    }
}


int main() {
    Movie* movieList[50];
    Director directorList[10];
    int movieCount = 0, directorCount = 0;
    char mainChoice;

    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Add Movie\n2. Assign Director\n3. Display Menu\n4. Search\n5. Sort by Year\n0. Exit\nChoice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case '1': {
                int genre;
                cout << "Enter Genre (1: SciFi, 2: Animation, 3: Action): ";
                cin >> genre;
                Movie* m = nullptr;
                if (genre == 1) m = new SciFiMovie();
                else if (genre == 2) m = new AnimationMovie();
                else if (genre == 3) m = new ActionMovie();
                if (m) {
                    cin >> *m;
                    movieList[movieCount++] = m;
                }
                break;
            }
            case '2': {
                Director d;
                cin >> d;
                directorList[directorCount++] = d;
                int idx;
                cout << "Assign to which movie index: ";
                cin >> idx;
                if (idx >= 0 && idx < movieCount) {
                    movieList[idx]->setDirector(&directorList[directorCount - 1]);
                }
                break;
            }
            case '3': {
                cout << "a. All\nb. SciFi\nc. Animation\nd. Action\ne. Directors\nChoice: ";
                char opt; cin >> opt;
                for (int i = 0; i < movieCount; ++i) {
                    if (opt == 'a' ||
                        (opt == 'b' && movieList[i]->getGenre() == "SciFi") ||
                        (opt == 'c' && movieList[i]->getGenre() == "Animation") ||
                        (opt == 'd' && movieList[i]->getGenre() == "Action")) {
                        movieList[i]->displayDetails();
                    }
                }
                if (opt == 'e') {
                    for (int i = 0; i < directorCount; ++i)
                        cout << directorList[i] << endl;
                }
                break;
            }
            case '4': {
                cout << "Search by title: ";
                string search;
                cin.ignore();
                getline(cin, search);
                for (int i = 0; i < movieCount; ++i)
                    if (movieList[i]->getTitle() == search)
                        movieList[i]->displayDetails();
                break;
            }
            case '5': {
                bubbleSortMovies(movieList, movieCount);
                cout << "Sorted Movies by Year:\n";
                for (int i = 0; i < movieCount; ++i)
                    movieList[i]->displayDetails();
                break;
            }
            case '0': {
                cout << "quit" <<endl;
                break;
            }
        }
    } while (mainChoice != '0');

    for (int i = 0; i < movieCount; ++i) delete movieList[i];
    return 0;
}
