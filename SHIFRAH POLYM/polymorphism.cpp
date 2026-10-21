#include <iostream>
#include <string>
#include <vector>

// Base Class
class Employee {
protected:
    std::string name;

public:
    Employee(const std::string& empName) : name(empName) {}
    
    // Virtual function enables runtime polymorphism
    virtual double calculatePay() const {
        return 0.0;
    }
    
    std::string getName() const { return name; }
    
    // Virtual destructor guarantees clean cleanup of derived objects
    virtual ~Employee() = default;
};

// Derived Class 1
class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    double hoursWorked;

public:
    HourlyEmployee(const std::string& empName, double rate, double hours)
        : Employee(empName), hourlyRate(rate), hoursWorked(hours) {}
        
    // Override keyword tells the compiler to verify signature matching
    double calculatePay() const override {
        return hourlyRate * hoursWorked;
    }
};

// Derived Class 2
class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(const std::string& empName, double salary)
        : Employee(empName), monthlySalary(salary) {}
        
    double calculatePay() const override {
        return monthlySalary;
    }
};

int main() {
    // Create objects of different derived classes
    HourlyEmployee worker1("Alice", 25.0, 40.0);
    SalariedEmployee worker2("Bob", 5000.0);
    
    // Demonstrate polymorphism using a vector of base class pointers
    std::vector<Employee*> payroll;
    payroll.push_back(&worker1);
    payroll.push_back(&worker2);
    
    std::cout << "--- Processing Payroll via Runtime Polymorphism ---" << std::endl;
    for (const auto& emp : payroll) {
        // The exact same method signature executes entirely different code 
        // depending on the type of object the base pointer is pointing to.
        std::cout << "Employee: " << emp->getName() 
                  << " | Processed Pay: $" << emp->calculatePay() << std::endl;
    }
    
    return 0;
}
