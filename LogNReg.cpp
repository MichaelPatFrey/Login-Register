#include <iostream>
#include <fstream> // allows for the reading, writing, and creation of files
#include <string>
bool isLoggedIn() {
    std::string username, password;
    std::string un, pw; // will use to compare with the strings above

    std::cout << "Enter a username: ";
    std::cin >> username;
    std::cout << "Enter a password: ";
    std::cin >> password;

    std::ifstream read(username + ".txt"); // ifstream will read the file in the "" 
    getline(read, un); // will read the username
    getline(read, pw); // will read the password

    if(un == username && pw == password) { // checks if un is the same as username and pw the same as password. if so returns true.
        return true;
    }
    else {
        return false;
    }
}


int main() {
    int userChoice;

    std::cout << std::endl;
    std::cout << "Main Menu: " << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "1. Register" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << std::endl;
    std::cout << "Your choice: ";
    std::cin >> userChoice;

    if (userChoice == 1) {
        std::string username, password;

        std::cout << "Registration: " << std::endl;
        std::cout << std::endl;
        std::cout << "Select a username: ";
        std::cin >> username;
        std::cout << "Select a password: ";
        std::cin >> password;

        std::ofstream file; // ofstream creates a file
        file.open(username + ".txt");
        file << username << std::endl << password;
        file.close();
        std::cout << "Welcome " << username << "!" << std::endl;
    }
    else if (userChoice == 2) { // user chooses to login to an account
        bool status = isLoggedIn();

        if(!status) { // if isLoggedIn(); returns false this will activate
            system("clear");
            std::cout << std::endl;
            std::cout << "Invalid login!" << std::endl;
            main();
            return 0;
        }
        else { // if isLoggedIn() returns true, the dashboard is displayed
            std::cout << "Successfully logged in!" << std::endl;
            std::cout << std::endl;

            int choiceTwo;
            // Display the dashboard:
            std::cout << "Welcome back!" << std::endl;
            std::cout << std::endl;
            std::cout << "DASHBOARD" << std::endl;
            std::cout << "This is placeholder text, could be anything." << std::endl; // example of what could appear on the the user's dashboard
            std::cout << std::endl;
            std::cout << "1. Sign Out" << std::endl;
            std::cout << "2. Back to main menu" << std::endl;
            std::cout << "Your choice: " << std::endl;
            std::cin >> choiceTwo;

            if (choiceTwo == 1) {
                system("exit"); // will exit the program
            }
            else if (choiceTwo == 2) {
                main();
            }
            return 1;
        }
    }
}