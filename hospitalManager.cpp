#include <iostream>
#include <fstream>
#include <string>

void patientManager();
void addPatient();
void viewPatients();
void searchPatient();
void removePatient();
void doctorManager();
void addDoctor();
void viewDoctors();
void searchDoctor();
void removeDoctor();

int main() {

    int choice;

    std::cout << "Welcome to the Hospital Management system\n";
    
    do {
        std::cout << "Please select what you would like to do: \n";
        std::cout << "1. Patient Manager\n";
        std::cout << "2. Doctor Manager\n";
        std::cout << "Please enter a choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: 
                patientManager();
                break;
            case 2:
                doctorManager();
                break;
            case 3:
                std::cout << "Thank your for using hospital manager";
                break;
            default:
                std::cout << "Please enter a valid choice. \n";
            break;
        }
    } while (choice != 3);
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
            std::cout << "Patient Added\n";
            break;
        case 2: 
            viewPatients();
        case 3:
            searchPatient();
        break;
        case 4:
            removePatient();
        break;
        case 5: 
            std::cout << "edit";
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
            for (int i = 0; i < 6; i++) {
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

void doctorManager() {

    int choice;

    std::cout << "1. Add Doctor\n";
    std::cout << "2. View All Doctors\n";
    std::cout << "3. Search Doctor\n";
    std::cout << "4. Remove Doctor\n";
    std::cin >> choice;

    switch (choice) {
        case 1: 
            addDoctor();
            break;
        case 2: 
            viewDoctors();
            break;
        case 3:
            searchDoctor();
            break;
        case 4: 
            removeDoctor();
            break;
    }
}

void addDoctor() {

    std::string idNumber;
    std::string firstName;
    std::string lastName;
    std::string birthday;
    std::string address;
    std::string phoneNumber;
    std::string gender;

    std::cout << "Please enter you medical identification number: ";
    std::cin >> idNumber;

    std::cout << "Please enter the doctor's first name: ";
    std::cin >> firstName;

    std::cout << "Please enter the doctor's last name: ";
    std::cin >> lastName;

    std::cout << "Please enter the doctor's date of birth (DD/MM/YYYY): ";
    std::cin >> birthday;
    std::cin.ignore();

    std::cout << "Please enter the doctor's address: ";
    std::getline(std::cin, address);

    std::cout << "Please enter the doctor's phone number: ";
    std::cin >> phoneNumber;

    std::cout << "Please enter the doctor's gender: ";
    std::cin >> gender;

    std::ofstream file;
    file.open("doctor.txt", std::ios::app);
    file << "Medical Identification Number: " << idNumber << "\n";
    file << "First Name: " << firstName << "\n";
    file << "Last Name: " << lastName << "\n";
    file << "Birthday: " << birthday << "\n";
    file << "Address: " << address << "\n";
    file << "Phone number: " << phoneNumber << "\n";
    file << "Gender: " << gender << "\n";
    file << "\n";
    file.close();
}

void viewDoctors() {

    std::ifstream file("doctor.txt");
    std::string line;
    
    while (getline(file, line)) {
        std::cout << line << "\n";
    }
    file.close();
}

void searchDoctor() {

    std::string idNumber;

    std::cout << "Please enter the doctor's medical identification number: ";
    std::cin >> idNumber;

    std::ifstream file("doctor.txt");
    if (!file.is_open()) {
        std::cout << "Error: Could not open file";
    }

    std::string line;
    bool found = false;

    while (getline(file, line)) {
        if (line == "Medical Identification Number: " +  idNumber) {
            getline(file, line);
            found = true;
            std::cout << "Medical Identificaiton Number: " << idNumber << "\n";
            std::cout << line << "\n";
            for (int i = 0; i < 5; i++) {
                getline(file, line);
                std::cout << line << "\n";
            }
            break;
        }
        std::cout << "Doctor not found";

    }
    if (!found) {
        std::cout << "Doctor not found";
    }
    file.close();

}

void removeDoctor() {

    std::string idNumber;
    std::string line;
    bool found = false;
    bool skip = false;

    std::cout << "Please enter the doctor's Medical Identification Number: ";
    std::cin >> idNumber;

    std::ofstream tempFile("dtemp.txt");

    std::ifstream file("doctor.txt");
    while (getline(file, line)) {
        if (line == "Medical Identification Number: " + idNumber) {
            skip = true;
            for (int i = 0; i < 6; i++) {
                getline(file, line);
            }
            found = true;
        } else {
            if (!skip) {
                tempFile << line << "\n";
            }
        }
    }

    if (!found) {
        std::cout << "Doctor not found";
    } else {
        std::cout << "Doctor removed successfully";
    }

    file.close();
    tempFile.close();

    std::remove("doctor.txt");
    std::rename("dtemp.txt", "doctor.txt");

}