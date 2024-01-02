#include <string>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

class Login {
private:
    string userName;
    string password;
public :
    Login(string userName, string password) {
        this->userName = userName;
        this->password = password;
    }





    void writeToFile();
    bool checkUserName(string userName);
    bool checkPassword(string password, string userName);


};

