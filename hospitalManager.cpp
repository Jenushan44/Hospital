#include <iostream>
#include <fstream>
#include <string>

void patientManager();
void addPatient();
void viewPatients();
void searchPatient();

int main() {

    int choice;

    std::cout << "Welcome to the Hospital Management system\n";
    std::cout << "Please select what you would like to do: \n";
    
    std::cout << "1. Patient Manager\n";
    std::cin >> choice;

    switch(choice) {
        case 1: 
            patientManager();
        break;
        default:
            std::cout << "Please enter a valid choice. \n";
        break;
    }
}

void patientManager() {

    int choice;

    std::cout << "1. Add Patient\n";
    std::cout << "2. View All Patients\n";
    std::cout << "3. Search Patient\n";
    std::cout << "Please enter a choice: ";
    std::cin >> choice;

    switch(choice) {
        case 1: 
            addPatient();
            break;
        case 2: 
            viewPatients();
        case 3:
            searchPatient();
        break;
        default:
        std::cout << "Please enter a valid choice: ";
        break;
    } 
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
    file << "\n";
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

    std::string firstName;                                             
    std::string lastName;

    std::cout << "Please enter the first name of the patient: ";
    std::cin >> firstName;

    std::cout << "Please enter the last name of the patient: ";
    std::cin >> lastName;

    std::ifstream file("patient.txt");
    if (!file.is_open()) {
        std::cout << "Error: Could not open file";
    }

    std::string line;
    bool found = false;

    while (getline(file, line)) {
        if (line == "First Name: " + firstName) {
            getline(file, line);
            if (line == "Last Name: " + lastName) {
                found = true;
                std::cout << "First Name: " << firstName << "\n";
                std::cout << line << "\n"; 
                for (int i = 0; i < 4; ++i) {
                    getline(file, line);
                    std::cout << line << "\n";
                }
                break;
            }
        }
    }
    if (!found) {
        std::cout << "Patient " << firstName << " " << lastName << " not found.\n";
    }

    file.close();


}


