#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    Complex operator + (const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator - (const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator / (const Complex& other) {
        float denominator = other.real * other.real + other.imag * other.imag;
        float realPart = (real * other.real + imag * other.imag) / denominator;
        float imagPart = (imag * other.real - real * other.imag) / denominator;
        return Complex(realPart, imagPart);
    }

    friend ostream& operator << (ostream& out, const Complex& c);
};

ostream& operator << (ostream& out, const Complex& c) {
    if (c.imag >= 0)
        out << c.real << " + " << c.imag << "i";
    else
        out << c.real << " - " << -c.imag << "i";
    return out;
}

int main() {
    Complex c1(4, 5), c2(2, -3);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "Sum = " << c1 + c2 << endl;
    cout << "Difference = " << c1 - c2 << endl;
    cout << "Quotient = " << c1 / c2 << endl;

    return 0;
}
