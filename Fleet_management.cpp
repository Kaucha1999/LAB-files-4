#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    int year;
    float price;
public:
    Car() : model(""), year(0), price(0.0f) {}

    virtual ~Car() {
        cout << "Deleting Car: " << model << endl;
    }

    void inputBasic() {
        cout << "Model: ";
        getline(cin, model);
        cout << "Year: ";
        cin >> year;
        cout << "Price: ";
        cin >> price;
        cin.ignore();
    }

    void displayBasic() const {
        cout << "Model: " << model << ", Year: " << year << ", Price: $" << price << endl;
    }

    virtual void input() = 0;
    virtual void display() const = 0;
};

class ElectricCar : public Car {
    float batterySize;
public:
    void input() override {
        inputBasic();
        cout << "Battery Size (kWh): ";
        cin >> batterySize;
        cin.ignore();
    }

    void display() const override {
        displayBasic();
        cout << "Battery: " << batterySize << " kWh" << endl;
    }
};

class GasCar : public Car {
    float fuelCapacity;
public:
    void input() override {
        inputBasic();
        cout << "Fuel Capacity (liters): ";
        cin >> fuelCapacity;
        cin.ignore();
    }

    void display() const override {
        displayBasic();
        cout << "Fuel Capacity: " << fuelCapacity << " L" << endl;
    }
};

class HybridCar : public Car {
    float batterySize, fuelCapacity;
public:
    void input() override {
        inputBasic();
        cout << "Battery Size (kWh): ";
        cin >> batterySize;
        cout << "Fuel Capacity (liters): ";
        cin >> fuelCapacity;
        cin.ignore();
    }

    void display() const override {
        displayBasic();
        cout << "Battery: " << batterySize << " kWh, Fuel: " << fuelCapacity << " L" << endl;
    }
};

int main() {
    int n;
    cout << "How many cars do you want to enter? ";
    cin >> n;
    cin.ignore();

    Car** cars = new Car*[n];
    int* types = new int[n];

    for (int i = 0; i < n; ++i) {
        cout << "\nCar " << i + 1 << " Type (1 = Electric, 2 = Gas, 3 = Hybrid): ";
        cin >> types[i];
        cin.ignore();

        if (types[i] == 1) {
            cars[i] = new ElectricCar();
        } else if (types[i] == 2) {
            cars[i] = new GasCar();
        } else {
            cars[i] = new HybridCar();
        }

        cout << "Enter details for Car " << i + 1 << ":\n";
        cars[i]->input();
    }

    cout << "\n--- Car Details ---\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nCar " << i + 1 << ":\n";
        if (types[i] == 1) {
            static_cast<ElectricCar*>(cars[i])->display();
        } else if (types[i] == 2) {
            static_cast<GasCar*>(cars[i])->display();
        } else {
            static_cast<HybridCar*>(cars[i])->display();
        }
    }

    for (int i = 0; i < n; ++i) {
        delete cars[i];
    }

    delete[] cars;
    delete[] types;

    return 0;
}
