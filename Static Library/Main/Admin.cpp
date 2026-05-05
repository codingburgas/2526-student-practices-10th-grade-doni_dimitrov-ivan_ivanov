
#include "admin.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static const string MOVIES_FILE = "movies.txt";

static void loadMovies(vector<string>& movies) {
    movies.clear();
    ifstream in(MOVIES_FILE);
    if (!in.is_open()) return;
    string line;
    while (getline(in, line)) {
        if (!line.empty())
            movies.push_back(line);
    }
}

static void saveMovies(const vector<string>& movies) {
    ofstream out(MOVIES_FILE, ios::trunc);
    for (const auto& m : movies) out << m << '\n';
}

static void listMovies(const vector<string>& movies) {
    cout << "\n--- Current Movies ---\n";
    if (movies.empty()) {
        cout << "(no movies available)\n";
        return;
    }
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i] << '\n';
    }
}

static void addMovie() {
    vector<string> movies;
    loadMovies(movies);

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover newline
    cout << "\nEnter movie name to add: ";
    string name;
    getline(cin, name);
    if (name.empty()) {
        cout << "No name entered. Aborting.\n";
        return;
    }

    // Prevent duplicate exact entries
    if (find(movies.begin(), movies.end(), name) != movies.end()) {
        cout << "Movie already exists.\n";
        return;
    }

    movies.push_back(name);
    saveMovies(movies);
    cout << "Added \"" << name << "\"\n";
}

static void deleteMovie() {
    vector<string> movies;
    loadMovies(movies);
    if (movies.empty()) {
        cout << "\nNo movies to delete.\n";
        return;
    }

    listMovies(movies);
    cout << "\nEnter movie number to delete (0 to cancel): ";
    int idx;
    if (!(cin >> idx)) {
        cout << "Invalid input.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    if (idx == 0) {
        cout << "Cancelled.\n";
        return;
    }
    if (idx < 1 || static_cast<size_t>(idx) > movies.size()) {
        cout << "Invalid index.\n";
        return;
    }
    string removed = movies[idx - 1];
    movies.erase(movies.begin() + (idx - 1));
    saveMovies(movies);
    cout << "Deleted \"" << removed << "\"\n";
}

void adminPanel() {
    string password;
    cout << "\nEnter Admin Password: ";
    cin >> password;
    if (password != "admin123") {
        cout << "Incorrect Password!\n";
        return;
    }

    vector<string> movies;
    int choice = -1;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. List Movies\n";
        cout << "2. Add Movie\n";
        cout << "3. Delete Movie\n";
        cout << "0. Exit Admin\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            loadMovies(movies);
            listMovies(movies);
            break;
        case 2:
            addMovie();
            break;
        case 3:
            deleteMovie();
            break;
        case 0:
            cout << "Exiting admin panel.\n";
            break;
        default:
            cout << "Invalid selection. Please try again.\n";
        }
    } while (choice != 0);
}