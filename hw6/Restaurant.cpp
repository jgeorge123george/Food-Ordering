#include "restaurant.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void Restaurant::addRestaurants(string restaurantName) {
    // Check if the restaurant already exists in the list
    ifstream restaurantList("restaurants.txt");
    string line;
    while (getline(restaurantList, line)) {
        if (line == restaurantName) {
            restaurantList.close();
            return;
        }
    }
    restaurantList.close();

    // Add the restaurant to the list
    ofstream listOfRest("restaurants.txt", ios::app);
    if (!listOfRest) {
        cout << "Unable to open restaurants.txt for appending." << endl;
        return;
    }
    listOfRest << restaurantName << endl;
    listOfRest.close();

    // Create the individual restaurant file
    string textFile = restaurantName + ".txt";
    ofstream restaurantFile(textFile, ios::app);
    if (!restaurantFile) {
        cout << "Unable to create the restaurant file: " << textFile << endl;
        return;
    }

    vector<Item> items = this->menu;
    for (int i = 0; i < items.size(); i++) {
        restaurantFile << "Name: " << items[i].itemName << endl;
        restaurantFile << "Description: " << items[i].description << endl;
        restaurantFile << "Price: $" << items[i].price << endl;
        restaurantFile << endl;
    }

    restaurantFile.close();
}



void Restaurant::displayRestaurants() {
    ifstream restaurantList("restaurants.txt");
    string restaurantName;
    cout << "List of Restaurants:" << endl;

    if (restaurantList.is_open()) {
        while (getline(restaurantList, restaurantName)) {
            cout << restaurantName << endl;
        }
        restaurantList.close();
    } else {
        cout << "Unable to open the restaurants.txt file." << endl;
    }
}

void Restaurant:: displayMenu(string name) {
    string fileName = name + ".txt";
    ifstream file(fileName);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
}

void Restaurant::writeOrder(string order, string delivery, string restaurant) {
    string file = restaurant + "_orders.txt";
    ofstream orders (file, ios::app);
    if(orders.is_open()) {
        orders << order << endl << delivery;
    }
    else
    {
        cout << "couldn't open";
    }
}

void Restaurant::addRestaurant(string name, string itemName, string description, double price) {
    string text = name + ".txt";
    ofstream file(text, ios::app);
    if(file.is_open()) {
        file << "Name: " << itemName << endl;
        file << "Description: " << description << endl;
        file << "Price: $" << price << endl;
    }
}

void Restaurant::addMenuItem(string restaurant, string itemName, string description, double price) {
    string textFile = restaurant+ ".txt";
    ofstream rest(textFile, ios::app);
    vector<Item> items = {{itemName, description, price}};
    Restaurant temp(restaurant, items);
    if (rest.is_open()) {
        for (int i = 0; i < items.size(); i++) {
            rest << "Name: " << items[i].itemName << endl;
            rest << "Description: " << items[i].description << endl;
            rest << "Price: $" << items[i].price << endl;
            rest << endl;
        }
        rest.close();
        cout << "Restaurant file created successfully!" << endl;
    } else {

        cout << "Unable to create the restaurant file." << endl;
    }
}


void Restaurant:: viewMenu(string restName) {
    string file = restName + ".txt";
    ifstream restFile(file);
    string line;
    if(restFile.is_open()) {
        while(getline(restFile, line)) {
            cout << line << endl;
        }
        restFile.close();
    }
}

void Restaurant::viewOrders(string restName) {
    string file = restName + "_orders.txt";
    ifstream restFile(file);
    string line;
    if(restFile.is_open()) {
        while(getline(restFile, line)) {
            cout << line << endl;
        }
        restFile.close();
    }
}







