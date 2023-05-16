#include <iostream>
#include <string>
#include <list>
#include <algorithm>

struct TicketRequest {
    std::string destination;
    std::string flightNumber;
    std::string passengerName;
    std::string desiredDepartureDate;

    bool operator==(const TicketRequest& other) const {
        return destination == other.destination &&
            flightNumber == other.flightNumber &&
            passengerName == other.passengerName &&
            desiredDepartureDate == other.desiredDepartureDate;
    }
};

class TicketSystem {
public:
    void addRequest(const TicketRequest& request) {
        requests.push_back(request);
    }

    void removeRequestByFlightNumber(const std::string& flightNumber) {
        requests.remove_if([&](const TicketRequest& request) {
            return request.flightNumber == flightNumber;
            });
    }

    void removeRequestByDate(const std::string& date) {
        requests.remove_if([&](const TicketRequest& request) {
            return request.desiredDepartureDate == date;
            });
    }

    void printRequestsByFlightAndDate(const std::string& flightNumber, const std::string& date) {
        for (const auto& request : requests) {
            if (request.flightNumber == flightNumber && request.desiredDepartureDate == date) {
                std::cout << "Destination: " << request.destination << '\n';
                std::cout << "Flight Number: " << request.flightNumber << '\n';
                std::cout << "Passenger Name: " << request.passengerName << '\n';
                std::cout << "Desired Departure Date: " << request.desiredDepartureDate << '\n';
                std::cout << '\n';
            }
        }
    }

    void printAllRequests() {
        for (const auto& request : requests) {
            std::cout << "Destination: " << request.destination << '\n';
            std::cout << "Flight Number: " << request.flightNumber << '\n';
            std::cout << "Passenger Name: " << request.passengerName << '\n';
            std::cout << "Desired Departure Date: " << request.desiredDepartureDate << '\n';
            std::cout << '\n';
        }
    }

private:
    std::list<TicketRequest> requests;
};

int main() {
    TicketSystem ticketSystem;

    // Додавання інформації про пасажирів та виліт
    TicketRequest request1;
    request1.destination = "Paris";
    request1.flightNumber = "AF1234";
    request1.passengerName = "John Doe";
    request1.desiredDepartureDate = "2023-05-20";
    ticketSystem.addRequest(request1);

    TicketRequest request2;
    request2.destination = "New York";
    request2.flightNumber = "UA5678";
    request2.passengerName = "Jane Smith";
    request2.desiredDepartureDate = "2023-06-15";
    ticketSystem.addRequest(request2);

    TicketRequest request3;
    request3.destination = "London";
    request3.flightNumber = "BA4321";
    request3.passengerName = "Bob Johnson";
    request3.desiredDepartureDate = "2023-07-10";
    ticketSystem.addRequest(request3);

    bool running = true;
    while (running) {
        std::cout << "Menu:\n";
        std::cout << "1. Add request\n";
        std::cout << "2. Remove request by flight number\n";
        std::cout << "3. Remove request by departure date\n";
        std::cout << "4. Print requests by flight number and date\n";
        std::cout << "5. Print all requests\n";
        std::cout << "6. Remove all requests\n";
        std::cout << "7. Exit\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            TicketRequest request;
            std::cout << "Enter destination: ";
            std::cin >> request.destination;
            std::cout << "Enter flight number: ";
            std::cin >> request.flightNumber;
            std::cout << "Enter passenger name: ";
            std::cin >> request.passengerName;
            std::cout << "Enter desired departure date: ";
            std::cin >> request.desiredDepartureDate;

            ticketSystem.addRequest(request);
            break;
        }
        case 2: {
            std::string flightNumber;
            std::cout << "Enter flight number: ";
            std::cin >> flightNumber;

            ticketSystem.removeRequestByFlightNumber(flightNumber);
            break;
        }
        case 3: {
            std::string date;
            std::cout << "Enter departure date: ";
            std::cin >> date;

            ticketSystem.removeRequestByDate(date);
            break;
        }
        case 4: {
            std::string flightNumber;
            std::string date;
            std::cout << "Enter flight number: ";
            std::cin >> flightNumber;
            std::cout << "Enter departure date: ";
            std::cin >> date;

            ticketSystem.printRequestsByFlightAndDate(flightNumber, date);
            break;
        }
        case 5:
            ticketSystem.printAllRequests();
            break;
        case 6:
            ticketSystem = TicketSystem();
            break;
        case 7:
            running = false;
            break;
        default:
            std::cerr << "Invalid choice\n";
        }
    }

    return 0;
}
