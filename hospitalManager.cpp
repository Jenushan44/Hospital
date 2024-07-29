#include <iostream>
#include <fstream>
#include <string>

void patientManager();
void addPatient();
void viewPatients();
void searchPatient();
void removePatient();

int main() {

    int choice;

    std::cout << "Welcome to the Hospital Management system\n";
    
    do {
        std::cout << "Please select what you would like to do: \n";
        std::cout << "1. Patient Manager\n";
        std::cin >> choice;

        switch(choice) {
            case 1: 
                patientManager();
            break;
            case 2:
                std::cout << "Thank your for using hospital manager";
            break;
            default:
                std::cout << "Please enter a valid choice. \n";
            break;
        }
    } while (choice != 2);
}

void patientManager() {

    int choice;

    std::cout << "1. Add Patient\n";
    std::cout << "2. View All Patients\n";
    std::cout << "3. Search Patient\n";
    std::cout << "4. Remove Patient\n";
    std::cout << "Please enter a choice: ";
    std::cin >> choice;

    switch(choice) {
        case 1: 
            addPatient();
            std::cout << "Patient Added";
            break;
        case 2: 
            viewPatients();
        case 3:
            searchPatient();
        break;
        case 4:
            removePatient();
        break;
        default:
        std::cout << "Please enter a valid choice: ";
        break;
    } 
}

void addPatient() {

    std::string healthCard;
    std::string firstName;
    std::string lastName;
    std::string birthday;
    std::string address;
    std::string phoneNumber;
    std::string gender;

    std::cout<< "Please enter you health card number: ";
    std::cin >> healthCard;
    
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
    file << "\n";
    file << "Health Card Number: " << healthCard << "\n";
    file << "First Name: " << firstName << "\nLast Name: " << lastName << "\n"; 
    file << "Birthday: " << birthday << "\n";
    file << "Address: " << address << "\n";
    file << "Phone number: " << phoneNumber << "\n";
    file << "Gender: " << gender << "\n";
    file.close();
}

void viewPatients() {

    std::ifstream file("patient.txt");
    std::string line;
    
    while (getline(file, line)) {
        std::cout << line << "\n";
    }
    file.close();

}

void searchPatient() {

    std::string healthCard;

    std::cout << "Please enter your Health Card Number: ";
    std::cin >> healthCard;

    std::ifstream file("patient.txt");
    if (!file.is_open()) {
        std::cout << "Error: Could not open file";
    }

    std::string line;
    bool found = false;

    while (getline(file, line)) {
        if (line == "Health Card Number: " + healthCard) {
            getline(file, line);
                found = true;
                std::cout << "Health Card Number: " << healthCard << "\n";
                std::cout << line << "\n"; 
                for (int i = 0; i < 5; ++i) {
                    getline(file, line);
                    std::cout << line << "\n";
                }
                break;
        }
    }
    if (!found) {
        std::cout << "Patient not found.\n";
    }
    file.close();
}

void removePatient() {

    std::string healthCard;

    std::cout << "Please enter your Health Card Number: ";
    std::cin >> healthCard;

    std::ifstream file("patient.txt");
    if (!file.is_open()) {
        std::cout << "Error: Could not open file";
    }

    std::ofstream tempFile("temp.txt");
    if (!tempFile.is_open()) {
        std::cout << "Error: could not open file";
    }

    std::string line;
    bool found = false;
    bool skip = false;

    while (getline(file, line)) {
        if (line == "Health Card Number: " + healthCard) {
            skip = true;
            for (int i = 0; i < 5; i++) {
                getline(file, line);
            }
            found = true;
        } else {
            if (!skip) {
                tempFile << line << "\n";
            } else {
                skip = false;
                tempFile << line << "\n";
            }
        }
    }

    if (!found) {
        std::cout << "Patient not found";
    } else {
        std::cout << "Patient removed successfully";
    }

    file.close();
    tempFile.close();

    std::remove("patient.txt");
    std::rename("temp.txt", "patient.txt");

}

