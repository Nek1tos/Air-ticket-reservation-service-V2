#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Klas dlia zberihannia informatsii pro reisy
class Flight {
public:
    int flightNumber;
    string departure;
    string destination;
    int availableSeats;
    double price;

    Flight(int fn, string dep, string dest, int seats, double pr) {
        flightNumber = fn;
        departure = dep;
        destination = dest;
        availableSeats = seats;
        price = pr;
    }

    void displayInfo() {
        cout << "Nomer reisu: " << flightNumber << endl;
        cout << "Vidpravlennia: " << departure << endl;
        cout << "Pryznachennia: " << destination << endl;
        cout << "Dostupni mistsia: " << availableSeats << endl;
        cout << "Tsina: " << price << endl;
    }
};

// Klas dlia keruvannia broniu
class Booking {
    vector<Flight> flights;

public:
    void addFlight(int flightNumber, string departure, string destination, int availableSeats, double price) {
        Flight newFlight(flightNumber, departure, destination, availableSeats, price);
        flights.push_back(newFlight);
    }

    void displayFlights() {
        for (size_t i = 0; i < flights.size(); ++i) {
            cout << "--------------------------------" << endl;
            flights[i].displayInfo();
        }
    }

    bool bookSeat(int flightNumber) {
        for (size_t i = 0; i < flights.size(); ++i) {
            if (flights[i].flightNumber == flightNumber) {
                if (flights[i].availableSeats > 0) {
                    flights[i].availableSeats--;
                    cout << "Mistse zabroniovano na reis " << flightNumber << endl;
                    return true;
                }
                else {
                    cout << "Nemaie vilnykh mists na tsomu reisi!" << endl;
                    return false;
                }
            }
        }
        cout << "Reis ne znaideno!" << endl;
        return false;
    }
};

int main() {
    Booking bookingSystem;

    // Dodaiemo kilka reisiv
    bookingSystem.addFlight(101, "Kyiv", "Lviv", 100, 1500.50);
    bookingSystem.addFlight(102, "Kyiv", "Odesa", 50, 1800.00);
    bookingSystem.addFlight(103, "Kyiv", "Kharkiv", 75, 1700.75);

    int choice;
    do {
        cout << "\n1. Perehliadnuty dostupni reisy" << endl;
        cout << "2. Zabroniuvaty mistse" << endl;
        cout << "3. Vyity" << endl;
        cout << "Vash vybir: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bookingSystem.displayFlights();
            break;
        case 2: {
            int flightNumber;
            cout << "Vvedit nomer reisu dlia broniuvannia: ";
            cin >> flightNumber;
            bookingSystem.bookSeat(flightNumber);
            break;
        }
        case 3:
            cout << "Do pobachennia!" << endl;
            break;
        default:
            cout << "Nevirnyi vybir!" << endl;
            break;
        }
    } while (choice != 3);

    return 0;
}
