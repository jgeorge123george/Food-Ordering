
#include <iostream>
#include <fstream>
#include "login.h"
#include <string>


using namespace std;

void Login::writeToFile() {
    ofstream credentials("credentials.txt", ios::app);
    if (credentials.is_open()) {
        credentials << this->userName << ":" << this->password << endl;
        credentials.close();
    }
}

bool Login::checkUserName(string userName) {
    string line;
    size_t pos;
    ifstream credentials("credentials.txt");
    while (getline(credentials, line)) {
        pos = line.find(":");
        if (pos != string::npos) {
            string storedUserName = line.substr(0, pos);
            if (storedUserName == userName) {
                return true;
            }
        }
    }
    return false;
}

bool Login::checkPassword(string userName, string password) {
    string line;
    ifstream credentials("credentials.txt");
    while (getline(credentials, line)) {
        size_t pos = line.find(":");
        if (pos != string::npos && line.substr(0, pos) == userName) {
            string pass = line.substr(pos + 1);
            credentials.close();
            return pass == password;
        }
    }
    credentials.close();
    return false;
}






