#include <iostream>
#include <string>

// Base Class (Level 1)
class Vehicle {
protected:
    std::string manufacturer;

public:
    Vehicle(const std::string& brand) : manufacturer(brand) {}
    
    void displayVehicleInfo() const {
        std::cout << "Manufacturer: " << manufacturer << std::endl;
    }
};

// Intermediate Derived Class (Level 2)
class Car : public Vehicle {
protected:
    int numberOfDoors;

public:
    Car(const std::string& brand, int doors) 
        : Vehicle(brand), numberOfDoors(doors) {}
        
    void displayCarInfo() const {
        displayVehicleInfo(); // Calling inherited base function
        std::cout << "Doors: " << numberOfDoors << std::endl;
    }
};

// Ultimate Derived Class (Level 3)
class ElectricCar : public Car {
private:
    double batteryCapacity; // kWh

public:
    ElectricCar(const std::string& brand, int doors, double battery)
        : Car(brand, doors), batteryCapacity(battery) {}
        
    void displayElectricCarInfo() const {
        displayCarInfo(); // Calling intermediate class function
        std::cout << "Battery Capacity: " << batteryCapacity << " kWh" << std::endl;
    }
};

int main() {
    // Instantiate an object of the ultimate derived class
    ElectricCar myTesla("Tesla", 4, 75.5);
    
    std::cout << " Accessing local and inherited members via Chained Inheritance" << std::endl;
    
    // Demonstrate usage of the ultimate method which utilizes the entire chain
    myTesla.displayElectricCarInfo();
    
    return 0;
}