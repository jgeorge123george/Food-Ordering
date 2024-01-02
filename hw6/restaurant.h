#include <string>
#include <map>
#include "item.h"
#include <vector>
using namespace std;
class Restaurant {
public:
    string name;
    vector<Item> menu;


    Restaurant(const string name, vector<Item> menu) {
        this->name = name;
        this->menu = menu;
    }

    void addRestaurants(string restaurantName);
    void displayRestaurants();
    void displayMenu(string name);
    void writeOrder(string order, string delivery, string restaurant);
    void addRestaurant(string name, string itemName, string description, double price);

   void addMenuItem(string restaurant, string itemName, string description, double price);

  void viewMenu(string restName);

  void viewOrders(string restName);




};

