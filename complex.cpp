#include <iostream>
#include "complex.hpp"

using namespace std;
using C = complex<double>;

int main() {

    C z1(1.0, -3.0);
    C z2(1.0, 6.0);

    C z3 = z1*z2;
    double r = 5.0;
    
    cout << "Initial number: " << z1 << endl;
    cout << "Real part: " << z1.real() << endl;
    cout << "Im part: " << z1.im() << endl;
    cout << "Conjugate: " << z1.conjugate() << endl;
    cout << "Multiplication between complexes: " << z1 << " * " << z2 << " = " << z3 << endl;
    cout << "Multiplication between reals: " << z1 << " * " << r << " = " << z1*r << endl;

}