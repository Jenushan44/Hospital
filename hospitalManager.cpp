#include <iostream>
#include <fstream>
#include <string>

void personDetails();
void printDetails();

class Person {
public:
    std::string firstName;
    std::string lastName;
    std::string birthday;
    std::string address;
    std::string phoneNumber;
    std::string gender;

    void personDetails() {
        std::cout << "Please enter first name: ";
        std::cin >> firstName;

        std::cout << "Please enter last name: ";
        std::cin >> lastName;

        std::cout << "Please enter date of birth (DD/MM/YYYY): ";
        std::cin >> birthday;
        std::cin.ignore();

        std::cout << "Please enter the address: ";
        std::getline(std::cin, address);

        std::cout << "Please enter the phone number: ";
        std::cin >> phoneNumber;

        std::cout << "Please enter the gender: ";
        std::cin >> gender;
    }

    void printDetails() {
        std::cout << "First name: " << firstName << "\n";
        std::cout << "Last name: " << lastName << "\n";
        std::cout << "Birthday: " << birthday << "\n";
        std::cout << "Address: " << address << "\n";
        std::cout << "Phone Number: " << phoneNumber << "\n";
        std::cout << "Gender: " << gender << "\n";
    }

};

class Patient : public Person{

public:
    std::string healthNumber;
    
    void personDetails() {
        Person::personDetails();
        std::cout << "Please enter your health card number: ";
        std::cin >> healthNumber;
    }

    void addToFile() {
        std::ofstream file("patient.txt", std::ios::app);
        file << "Health Card Number: " << healthNumber << "\n";
        file << "First name: " << firstName << "\n";
        file << "Last name: " << lastName << "\n";
        file << "Birthday: " << birthday << "\n";
        file << "Address: " << address << "\n";
        file << "Phone Number: " << phoneNumber << "\n";
        file << "Gender: " << gender << "\n";
        file.close();
        std::cout << "Patient details saved";
    }
};

int main() {

    int choice;

    std::cout << "Welcome to the Hospital Manager\n";
    
    Patient p;
    
    do {    
        std::cout << "1. Patient Details\n";
        std::cout << "2. Add Patient\n";
        std::cout << "3. Exit";
        std::cin >> choice;

        switch (choice) {
            case 1: 
                p.printDetails();
                break;
            case 2: 
                p.personDetails();
                p.addToFile();
                break;
            case 3:
                std::cout << "Thank you for using the hospital manager";
                break;
            default:
                std::cout << "Please enter a valid choice";
                break;
        }
    } while (choice != 3);
}

