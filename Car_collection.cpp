#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    int year;
    float price;

public:
    Car(string m = "", int y = 0, float p = 0.0f) : model(m), year(y), price(p) {}

    ~Car() {
        cout << "Car \"" << model << "\" destroyed.\n";
    }

    void input() {
        cout << "Enter model: ";
        getline(cin, model);
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter price: ";
        cin >> price;
        cin.ignore(); // clean up after numeric input
    }

    void display() const {
        cout << "Model: " << model << ", Year: " << year << ", Price: $" << price << endl;
    }
};

class CarCollection {
private:
    Car* cars;
    int size;

public:
    CarCollection() {
        cout << "How many cars do you want to enter?\n";
        cin >> size;
        cin.ignore(); 
        cars = new Car[size];
        for (int i = 0; i < size; ++i) {
            cout << "\nEnter details for car " << i + 1 << ":\n";
            cars[i].input();
        }
    }

    ~CarCollection() {
        delete[] cars;
        cout << "\nCarCollection destroyed.\n";
    }

    void displayCars() const {
        cout << "\n--- Car List ---\n";
        for (int i = 0; i < size; ++i) {
            cars[i].display();
        }
    }
};

int main() {
    CarCollection collection;
    collection.displayCars();
    return 0;
}
