/*
 * The compiler tries really hard to compile your programs.
 * That includes implicit conversions of values, even if that
 * means loosing information.
 *
 * In this example, mixing int and unsigned gives interesting
 * results. If you're interested, try to understand why
 * the values of x and y,z are different.
 *
 * And regardless, take this as an example of why not to mix 
 * signed and unsigned types in an expression. Treat such compiler
 * warnings as errors.
 */
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int a = 6;
    unsigned int b = 10; // Run the program and study the output.
                         // Then change the type of b to int and see what happens

    int x = a - b;
    cout << "int x is " << x << endl;

    long y = a - b;
    cout << "long y is " << y << endl;

    float z = a - b;
    cout << "float z is " << z << endl;

    // Another dangerous case is comparisons between signed and unsigned.
    // Compiler warnings like these should be treated as errors

    cout << a << " - " << b << ((a-b < 0) ? " is negative\n" : " is positive\n");

    int c = -5;

    cout << c << ((c < b) ? " is less than " : " is greater than or equal to ") <<  b << "\n" ;


    // An explicit cast to a signed type gets the expected result
    // (here, we use long to accept all values of unsigned int)
    cout << "with cast: " << c << ((c < static_cast<long>(b)) ? " is less than " : " is greater than or equal to ") <<  b << "\n" ;
}