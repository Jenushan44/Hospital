#include <iostream>
#include <fstream>
#include <string>

void addPatient();

int main() {

    int choice;

    std::cout << "Welcome to the Hospital Management system\n";

    std::cout << "Please select what you would like to do: \n";
    
    std::cout << "1. Add a patient\n";
    std::cin >> choice;

    switch(choice) {
        case 1: 
            addPatient();
        break;
    }

    return 0;
}

void addPatient() {

    std::string firstName;
    std::string lastName;
    std::string birthday;
    std::string address;
    std::string phoneNumber;
    std::string gender;

    std::cout << "Please enter patient first name: ";
    std::cin >> firstName;

    std::cout << "Please enter patient last name: ";
    std::cin >> lastName;

    std::cout << "Please enter your date of birth (DD/MM/YYY): ";
    std::cin >> birthday; 
    std::cin.ignore();

    std::cout <<"Please enter patient address: ";
    std::getline(std::cin, address);

    std::cout <<"Please enter patient phone number: ";
    std::cin >> phoneNumber;

    std::cout << "Please enter your gender: ";
    std::cin >> gender;

    std::ofstream file;
    file.open("patient.txt", std::ios::app);
    file << "First Name: " << firstName << "\nLast Name: " << lastName << "\n"; 
    file << "Birthday: " << birthday << "\n";
    file << "Address: " << address << "\n";
    file << "Phone number: " << phoneNumber << "\n";
    file << "Gender: " << gender << "\n";
 
}