#include <iostream>
#include "restaurant.h"
#include "login.h"
#include <map>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    // Domino's

    // Domino's items
    Item basic_pizza("Basic Pizza", "cheese pizza with garlic sauce", 10.00);
    Item deluxe_pizza("Deluxe Pizza", "cheese pizza with vegetable toppings and garlic sauce", 15.00);
    Item premium_pizza("Premium Pizza", "cheese pizza with vegetable toppings, pepperoni, and garlic sauce", 10.00);

    // Domino's menu
    vector<Item> dominoMenu;
    dominoMenu.push_back(premium_pizza);
    dominoMenu.push_back(deluxe_pizza);
    dominoMenu.push_back(basic_pizza);

    // Domino's restaurant
    Restaurant dominos("Domino's", dominoMenu);



    // Chick-fil-A

    // Chick-fil-A items
    Item spicy_sandwich("Spicy Chicken Sandwich", "chicken sandwich with pickles", 10.00);
    Item grilled_nuggets("Grilled Nuggets", "8 piece grilled nuggets", 10.00);
    Item french_fries("Waffle Fries", "french fries shaped like waffles", 5.00);

    // Chick-fil-A menu
    vector<Item> chick_fil_a_menu;
    chick_fil_a_menu.push_back(french_fries);
    chick_fil_a_menu.push_back(grilled_nuggets);
    chick_fil_a_menu.push_back(spicy_sandwich);

    // Chick-fil-A restaurant
    Restaurant chick_fil_a("Chick-Fil-A", chick_fil_a_menu);

    dominos.addRestaurants("Domino's");
    chick_fil_a.addRestaurants("Chick-Fil-A");


    bool userExit = false;
    bool accountCreate = false;
    bool userNameCheck = false;
    bool passwordCheck = false;
    string userType;
    string createAccount;
    string userName;
    string password;
    string addRestaurant;
    string chooseRestaurant;
    Login user("", "");
    vector<Item> empty = {};
    Restaurant rest("", empty);
    string name;
    string order = "";
    string description;
    double price;
    string delivery;
    string itemName;
    string addItem;
    string edit;
    cout << "Are you a customer or restaurant (customer or restaurant)?" << endl;
    cin >> userType;

    // Customer selected
    if (userType == "customer") {

        // Continues to ask the question until logged in
        while (!userExit) {
            // Asking what to do
            userExit = true;
            cout << "Do you want to create an account or log in (create or login)?" << endl;
            cin >> createAccount;

            // Creating an account
            if (createAccount == "create") {
                accountCreate = false;

                while (!accountCreate) {
                    cout << "Type in a username: ";
                    cin >> userName;

                    if (!user.checkUserName(userName)) {
                        accountCreate = true;
                        // Perform further actions for creating the account
                        cout << "What is the password: ";
                        cin >> password;
                        user = Login(userName, password);
                        user.writeToFile();
                        cout << "Account created successfully!" << endl;
                    } else {
                        cout << "The username you entered has already been created. Please enter a new username."
                             << endl;
                    }
                }
            }

            // Logging in
            if (createAccount == "login") {
                userNameCheck = false;

                while (!userNameCheck) {
                    cout << "Type in your username: ";
                    cin >> userName;

                    if (!user.checkUserName(userName)) {
                        cout << "The username you typed doesn't exist. Please type another one." << endl;
                    } else {
                        cout << "Type the password: ";
                        cin >> password;

                        if (user.checkPassword(userName, password)) {
                            cout << "Welcome!" << endl;
                            rest.displayRestaurants();
                            cout << "What restaurant's menu do you want to see(just type the name of the restaurant)?";
                            cin >> chooseRestaurant;
                            rest.displayMenu(chooseRestaurant);
                            cin.ignore();
                            cout << "Write the name of items you want with a space between each item?";
                            getline(cin, order);
                            cout << "How do you want to get your food(delivery or pickup)?";
                            cin >> delivery;
                            rest.writeOrder(order, delivery, chooseRestaurant);

                            userNameCheck = true;
                        } else {
                            cout << "The password is incorrect. Please try again." << endl;
                        }
                    }
                }
            }
        }
    }

    if (userType == "restaurant") {
        cout << "Would you like to add a restaurant(yes or no)?" << endl;
        cin >> addRestaurant;
        if (addRestaurant == "yes") {
            cout << "What is the name of the restaurant?" << endl;
            cin.ignore(); // Ignore the newline character from previous input
            getline(cin, name);


            userExit = false;
            while (!userExit) {
                cout << "What is the name of the item: ";
                getline(cin, itemName);


                cout << "What is the description: ";
                getline(cin, description);


                cout << "What is the price: ";
                cin >> price;
                cin.ignore(); // Ignore the newline character


                rest.addRestaurant(name, itemName, description, price);


                cout << "Would you like to add a new item to the restaurant you just created (yes or no)? ";
                getline(cin, addItem);


                if (addItem != "yes") {
                    chooseRestaurant.clear();
                    cout << "Type in the restaurant that you want to edit" << endl;
                    rest.displayRestaurants();
                    cin >> chooseRestaurant;
                    rest.displayMenu(chooseRestaurant);
                    userExit = true;
                }
            }
        } else {
            cout << "Type in the name of the restaurant you manage";
            rest.displayRestaurants();
            cin >> chooseRestaurant;
            cout << "Do you want to add to the menu or view the menu, or view the orders(add, menu, orders)?";
            cin >> edit;


            if (edit == "add") {
                cout << "What is the name of the item: ";
                cin.ignore();
                getline(cin, itemName);


                cout << "What is the description of the item: ";
                getline(cin, description);


                cout << "What is the price of the item: ";
                cin >> price;
                cin.ignore();
               rest.addMenuItem(chooseRestaurant, itemName, description, price);

            }

            if(edit == "menu") {
                rest.viewMenu(chooseRestaurant);
            }
            if(edit == "orders") {
                rest.viewOrders(chooseRestaurant);
            }


        }


    }


    return 0;
}
