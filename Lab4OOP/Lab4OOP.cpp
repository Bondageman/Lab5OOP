#include <iostream>
#include <windows.h>
using namespace std;


class Calculator {
public:
    virtual double add(double a, double b) = 0;
    virtual double subtract(double a, double b) = 0;
    virtual double multiply(double a, double b) = 0;
    virtual double divide(double a, double b) = 0;
};


class TrueCalculator : public Calculator {
public:
    double add(double a, double b) override {
        return a + b;
    }

    double subtract(double a, double b) override {
        return a - b;
    }

    double multiply(double a, double b) override {
        return a * b;
    }
    
    double divide(double a, double b) override {
        if (b != 0) {
            return a / b;
        }
        else {
            cout << "Помилка: ділення на нуль!" << endl;
            return 0;
        }
    }
};

int main() {
    SetConsoleOutputCP(1251);

    Calculator* calc = new TrueCalculator;
    double a = 10, b = 5;

    cout << "Додавання: " << calc->add(a, b) << endl;
    cout << "Віднімання: " << calc->subtract(a, b) << endl;
    cout << "Множення: " << calc->multiply(a, b) << endl;
    cout << "Ділення: " << calc->divide(a, b) << endl;

    return 0;
}
