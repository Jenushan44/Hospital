#include <iostream>
#include <fstream>
#include <string>

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

class Patient : public Person {

public:
    std::string healthCard;

    void identification() {
        Person::personDetails();
        std::cout << "Please enter your health card number: ";
        std::cin >> healthCard;
    }

    void addPatient() {
        std::ofstream file("patient.txt", std::ios::app);
        file << "Health Card Number: " << healthCard << "\n";
        file << "First name: " << firstName << "\n";
        file << "Last name: " << lastName << "\n";
        file << "Birthday: " << birthday << "\n";
        file << "Address: " << address << "\n";
        file << "Phone Number: " << phoneNumber << "\n";
        file << "Gender: " << gender << "\n";
        file.close();
        std::cout << "Patient details saved\n";
    }

    void viewPatient() {
        std::string line;
        std::ifstream file("patient.txt");
        if (!file.is_open()) {
            std::cout << "File not found";
        }   
        while(getline(file, line)) {
            std::cout << line << "\n";
        }
        file.close();
    }

    void searchPatient() {
        std::string healthCard;
        std::string line;
        bool found = false;

        std::cout << "Please enter the health card number: ";
        std::cin >> healthCard;

        std::ifstream file("patient.txt");
        if (!file.is_open()) {
            std::cout << "File not found";
        }
        while (getline(file, line)) {
            if (line == "Health Card Number: " + healthCard) {
                getline(file, line);
                found = true;
                std::cout << "Health Card Number: " << healthCard << "\n";
                std::cout << line << "\n";
                for (int i = 0; i < 5; i++) {
                    getline(file, line);
                    std::cout << line << "\n";
                }
                break;
            }
        }
        if (!found) {
            std::cout << "Patient not found\n";
        }
        file.close();
    }
};

class Doctor : public Person {

public:
    std::string doctorID;

    void identification() {
        Doctor::personDetails();
        std::cout << "Please enter your Doctor Id number: ";
        std::cin >> doctorID;
    }

    void addDoctor() {
        std::ofstream file("doctor.txt", std::ios::app);
        file << "Doctor Id: " << doctorID << "\n";
        file << "First Name: " << firstName << "\n";
        file << "Last Name: " << lastName << "\n";
        file << "Birthday: " << birthday << "\n";
        file << "Address: " << address << "\n";
        file << "Phone number: " << phoneNumber << "\n";
        file << "Gender: " << gender << "\n";
        file.close();
        std::cout << "Doctor details saved\n";
    }

    void viewDoctor() {
        std::string line;
        std::ifstream file("doctor.txt");
        if (!file.is_open()) {
            std::cout << "File not found\n";
        }
        while(getline(file, line)) {
            std::cout << line << "\n";
        }
        file.close();
    }

    void searchDoctor() {
        std::string line;
        std::string doctorID;
        bool found = false;

        std::cout << "Please enter the Doctor's Id: ";
        std::cin >> doctorID;

        std::ifstream file("doctor.txt");

        if (!file.is_open()) {
            std::cout << "File not found\n";
        }
        while(getline(file,line)) {
            if (line == "Doctor Id: " + doctorID) {
                getline(file, line);
                found = true;
                std::cout << "Doctor ID: " << doctorID;
                for (int i = 0; i < 5; i++) {
                    getline(file, line);
                    std::cout << line << "\n";
                }
                break;
            }
        }  
        if (!found) {
            std::cout << "Doctor not found";
        } 
    }
};

int main() {

    int choice;
    std::cout << "Welcome to the Hospital Manager\n";
    
    Patient p;
    Doctor d;

    do {    
        std::cout << "1. Add Patient\n";
        std::cout << "2. View Patients\n";
        std::cout << "3. Search Patient\n";
        std::cout << "4. Add Doctor\n";
        std::cout << "5. View Doctor\n";
        std::cout << "6. Seach Doctor\n";
        std::cout << "7. Exit\n";
        std::cout << "Please enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: 
                p.identification();
                p.addPatient();
                break;
            case 2:
                p.viewPatient();
                break;
            case 3:
                p.searchPatient();
                break;
            case 4:
                d.identification();
                d.addDoctor();
                break;
            case 5:
                d.viewDoctor();
                break;
            case 6:
                d.searchDoctor();
                break;
            case 7:
                std::cout << "Thank you for using the hospital manager";
                break;
            default:
                std::cout << "Please enter a valid choice";
                break;
        }
    } while (choice != 7);
}