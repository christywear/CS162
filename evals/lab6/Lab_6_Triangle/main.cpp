#include <iostream>
#include "header.hpp"

using namespace std;

/*******************************
 *
 * Triangle Class
 *
 * Finished Code By Lawrence Warner
 * CS 162 C++
 * Last Modified: 2/21/19
 *
 *******************************/

int main()
{
    Triangle first;
// show that default is properly built
    cout << "Default is 3,4, 5 triangle, should be scalene and right" << endl;
    cout << " for default a is " << first.getA() << " b is " << first.getB() << " c is " << first.getC() << endl;
    cout << " default " << (first.isEquilateral() ? "is" : "is not") << " equalateral" << endl;
    cout << " default " << (first.isScalene() ? "is" : "is not") << " scalene" << endl;
    cout << " default " << (first.isIsosceles() ? "is" : "is not") << " isosceles" << endl;
    cout << " default " << (first.isRight() ? "is" : "is not") << " right" << endl << endl;

// test setter methods
    first.setA(2);
    first.setB(2);
    first.setC(3);
    cout << "Modified is 2, 2, 3 triangle, should be isosceles" << endl;
    cout << " for modified a is " << first.getA() << " b is " << first.getB() << " c is " << first.getC() << endl;
    cout << " modified " << (first.isEquilateral() ? "is" : "is not") << " equalateral" << endl;
    cout << " modified " << (first.isScalene() ? "is" : "is not") << " scalene" << endl;
    cout << " modified " << (first.isIsosceles() ? "is" : "is not") << " isosceles" << endl;
    cout << " modified " << (first.isRight() ? "is" : "is not") << " right" << endl << endl;

// test overloaded constructor
    Triangle second(4,4,4);
    cout << "Second is 4, 4, 4 triangle, should be equalateral and isosceles" << endl;
    cout << " for second a is " << second.getA() << " b is " << second.getB() << " c is " << second.getC() << endl;
    cout << " second " << (second.isEquilateral() ? "is" : "is not") << " equalateral" << endl;
    cout << " second " << (second.isScalene() ? "is" : "is not") << " scalene" << endl;
    cout << " second " << (second.isIsosceles() ? "is" : "is not") << " isosceles" << endl;
    cout << " second " << (second.isRight() ? "is" : "is not") << " right" << endl << endl;

    return 0;
}
