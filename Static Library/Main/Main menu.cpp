#include <iostream>
#include "raylib.h"
#include <string>

using namespace std;

void browseMovies();
void searchByCity();
void bookTicket();
void adminPanel();

int main() {
    int choice;

    do {
  
        cout << "\n========================================" << endl;
        cout << "      CINEMACONNECT BOOKING SYSTEM      " << endl;
        cout << "========================================" << endl;
        cout << "1. Browse All Movies" << endl;
        cout << "2. Search Cinemas by City" << endl;
        cout << "3. Book a Ticket" << endl;
        cout << "4. Admin Portal" << endl;
        cout << "0. Exit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            continue;
        }

        switch (choice) {
        case 1:
            browseMovies();
            break;
        case 2:
            searchByCity();
            break;
        case 3:
            bookTicket();
            break;
        case 4:
            adminPanel();
            break;
        case 0:
            cout << "Thank you for using CinemaConnect. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid selection. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}


void browseMovies() {
    cout << "\n--- Current Movies ---" << endl;
    cout << "1. Interstellar\n2. The Dark Knight\n3. Inception" << endl;
}

void searchByCity() {
    string city;
    cout << "\nEnter City Name: ";
    cin >> city;
    cout << "Fetching cinemas in " << city << "..." << endl;
}

void bookTicket() {
    cout << "\nRedirecting to seat selection..." << endl;
}

void adminPanel() {
    string password;
    cout << "\nEnter Admin Password: ";
    cin >> password;
    if (password == "admin123") {
        cout << "Access Granted. [Admin Menu Placeholder]" << endl;
    }
    else {
        cout << "Incorrect Password!" << endl;
    }
}