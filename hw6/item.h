#include <string>
#include <map>

using namespace std;

class Item {
public:
    string itemName;
    string description;
    double price;

    Item(string itemName, string description, double price) {
        this->itemName = itemName;
        this->description = description;
        this->price =  price;
    }
};

