#include "revenues.h"

void displayASCIIArt() {
    std::cout << R"(
------------------------------------------------------------------------------------------------------------------------
    ______                    __       ________ __                               ______                                 
   /      \                  |  \     |        |  \                             /      \                                
  |  $$$$$$\ ______   _______| $$____ | $$$$$$$| $$ ______  __   __   __       |  $$$$$$\ ______   ______  __   __   __ 
  | $$   \$$|      \ /       | $$    \| $$__   | $$/      \|  \ |  \ |  \      | $$   \$$/      \ /      \|  \ |  \ |  \
  | $$       \$$$$$$|  $$$$$$| $$$$$$$| $$  \  | $|  $$$$$$| $$ | $$ | $$      | $$     |  $$$$$$|  $$$$$$| $$ | $$ | $$
  | $$   __ /      $$\$$    \| $$  | $| $$$$$  | $| $$  | $| $$ | $$ | $$      | $$   __| $$   \$| $$    $| $$ | $$ | $$
  | $$__/  |  $$$$$$$_\$$$$$$| $$  | $| $$     | $| $$__/ $| $$_/ $$_/ $$      | $$__/  | $$     | $$$$$$$| $$_/ $$_/ $$
   \$$    $$\$$    $|       $| $$  | $| $$     | $$\$$    $$\$$   $$   $$       \$$    $| $$      \$$     \\$$   $$   $$
    \$$$$$$  \$$$$$$$\$$$$$$$ \$$   \$$\$$      \$$ \$$$$$$  \$$$$$\$$$$         \$$$$$$ \$$       \$$$$$$$ \$$$$$\$$$$ 
                                                                                                                        
------------------------------------------------------------------------------------------------------------------------

)" << "\n";
}

bool signUp() {
    std::string username, email, password, confirmPassword;
    std::ofstream outFile;
    std::ifstream inFile;

    std::cout << "SIGN UP\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "E-mail: ";
    std::cin >> email;
    std::cout << "Password: ";
    std::cin >> password;
    std::cout << "Confirm Password: ";
    std::cin >> confirmPassword;


    if (password != confirmPassword) {
        std::cout << "Passwords do not match. Try again.\n"; // Checks if passwords match
        return false;
    }

    inFile.open("users.txt"); // Checks if the username already exists
    std::string existingUsername, existingEmail, existingPassword;
    while (inFile >> existingUsername >> existingEmail >> existingPassword) {
        if (existingUsername == username) {
            std::cout << "Username already exists. Try a different username.\n";
            inFile.close();
            return false;
        }
    }
    inFile.close();

    // Saves new user details to file
    outFile.open("users.txt", std::ios::app);
    outFile << username << " " << email << " " << password << "\n";
    outFile.close();

    std::cout << "Sign-up successful!\n";
    revenues();
}

// Function to handle user login
bool login() {
    std::string username, password;
    std::ifstream inFile;

    // Collect login details from user
    std::cout << "LOGIN\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    // Open file to validate username and password
    inFile.open("users.txt");
    std::string existingUsername, existingEmail, existingPassword;
    while (inFile >> existingUsername >> existingEmail >> existingPassword) {
        if (existingUsername == username && existingPassword == password) { // checks if data on file match
            std::cout << "Login successful!\n";
            inFile.close();
            revenues();
            return 0;
        }
    }
    inFile.close();

    std::cout << "Invalid username or password. Try again.\n";
    return false;
}

int main() {
    displayASCIIArt();
    int choice;
    std::cout << "To get started, log into or create an account." << std::endl;

    do {
        std::cout << "\n1. Sign Up\n2. Login\n3. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            signUp();
            break;
        case 2:
            login();
            break;
        case 3:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}