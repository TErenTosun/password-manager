#include "manager.hpp"

void databaseCheck(std::string database) {
    //Check if database exists. If not create one.
    std::ifstream file(database.c_str());
    if (!file.good()) {
        std::cout << "Database doesn't exist. Creating a new one." << std::endl;
        std::ofstream newFile("database.dat");
        std::cout << "Database created." << std::endl;
        newFile.close();
    }
    file.close();
}

void manager_prompt() {
    int opt;
    std::cout << "1) Save credentials"
        << std::endl
        << "2) Get credentials"
        << std::endl
        << ">";

    std::cin >> opt;
    std::cout << std::endl;
    switch (opt) {
    case 1:
        saveCredentials();
        break;
    case 2:
        getCredentials();
        break;
    default:
        std::cout << "Invalid input." << std::endl;
        break;
    }
}

int saveCredentials() {
    //Check if the database exists (Could be a text file as well)
    databaseCheck("database.dat");
    std::string domainName, username, password;
    bool domainExists = false;

    std::cout << "Enter domain name: ";
    std::cin >> domainName;
    //Check if the same domain name has been registered.
    std::ifstream databaseRead;
    std::string line;
    std::string domainCheck = "domain:" + domainName;
    databaseRead.open("database.dat", std::ios_base::in);
    while (getline(databaseRead, line)) {
        if (line == domainCheck) domainExists = true;
    }
    databaseRead.close();

    //If domain doesn't exist
    if (!domainExists) {
        std::cout << std::endl << "Enter username: ";
        std::cin >> username;
        std::cout << std::endl << "Enter password: ";
        std::cin >> password;

        std::ofstream database;
        database.open("database.dat", std::ios_base::app);

        database
            << "START"
            << std::endl
            << "domain:" << domainName
            << std::endl
            << "username:" << username 
            << std::endl 
            << "password:" << password
            << std::endl
            << "END"
            << std::endl;

        database.close();
        std::cout << "User saved." << std::endl;
        system("pause");
        return 0;
    }

    //If domain exists
    else {
        std::cout << "Domain already exists." << std::endl;
        system("pause");
        return 1;
    }
}

int getCredentials() {
    //Check if database exists
    databaseCheck("database.dat");

    //Enter domain, return username and password.
    //Take domain from user.
    std::string domain;
    std::cout << "Enter domain name: " << std::endl;
    std::cin >> domain;

    //Open the database (database.dat file).
    std::ifstream database;
    bool found = false;
    database.open("database.dat", std::ios_base::out);
    //Parse through the database.
    std::string line;
    std::string target = "domain:" + domain;
    while (getline(database, line)) {
        //Check if the domain line has the requested value.
        if (line == target) {
            getline(database, line);
            std::cout << line << std::endl;
            getline(database, line);
            std::cout << line << std::endl;
            found = true;
            system("pause");
            return 0;
        }
    }
    if (!found) {
        std::cout << "Domain name not found." << std::endl;
        system("pause");
    }
    return 1;
}
 
//Will be added in the future.
int removeCredentials() {
    //Find target domain; if domain doesn't exist, return 1.
    //Delete the domain, username and password.
    return 0;
}