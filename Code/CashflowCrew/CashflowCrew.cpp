#include <iostream>
#include <fstream>
#include <string>

void displayASCIIArt() {
    std::cout << R"(
 __          __  _                            _           _____          _     ______ _               _ 
 \ \        / / | |                          | |         / ____|        | |   |  ____| |             | |
  \ \  /\  / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |     __ _ ___| |__ | |__  | | _____      _| |
   \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \  | |    / _` / __| '_ \|  __| | |/ _ \ \ /\ / / |
    \  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |___| (_| \__ \ | | | |    | | (_) \ V  V /|_|
     \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/   \_____\__,_|___/_| |_|_|    |_|\___/ \_/\_/ (_)
                                                                                                        
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
        std::cout << "Passwords do not match. Try again.\n"; // checks if passwords match
        return false;
    }

    inFile.open("users.txt"); // checks if the username already exists
    std::string existingUsername, existingEmail, existingPassword;
    while (inFile >> existingUsername >> existingEmail >> existingPassword) {
        if (existingUsername == username) {
            std::cout << "Username already exists. Try a different username.\n";
            inFile.close();
            return false;
        }
    }
    inFile.close();

    // saves new user details to file
    outFile.open("users.txt", std::ios::app);
    outFile << username << " " << email << " " << password << "\n";
    outFile.close();

    std::cout << "Sign-up successful!\n";
    return true;
}

bool login() {
    std::string username, password;
    std::ifstream inFile;

    std::cout << "LOGIN\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    inFile.open("users.txt");
    std::string existingUsername, existingEmail, existingPassword;
    while (inFile >> existingUsername >> existingEmail >> existingPassword) {
        if (existingUsername == username && existingPassword == password) { // checks if data on file match
            std::cout << "Login successful!\n";
            inFile.close();
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