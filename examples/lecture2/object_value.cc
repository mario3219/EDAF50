#include <iomanip> // I/O manipulators, for std::hex
#include <iostream>
using std::cout;
using std::endl;


/* A small program demonstrating type casts.
 * In C++, a value is simply a piece of memory
 * interpreted according to its type.
 * Here, we see that an int object (4 bytes) can
 * be interpreted as an array of characters.
 * On a little-endian machine, this will be a null-terminated
 * char array as the fourth byte is zero.
 *
 * The same int object can also be interpreted as a point object,
 * where the first two bytes is the x coordinate and bytes 3 and 4
 * is the y coordinate.
 */

class point{
public:
    point(short xx, short yy) :x{xx}, y{yy} {}
    short get_x() const {return x;}
    short get_y() const {return y;}
private:
    short x;
    short y;
};

int main()
{
    int x = 0x434241;
    cout << "x is " << x << endl;
    cout << "x as hex is " << std::hex << x << endl;
    // "old-style cast (avoid). Gives warning with -Wold-style-cast
    cout << "x as string is (char*): " << (char*) &x << endl;
    cout << "x as string is (char[4]): " << (char (&)[4]) x << endl;
    // modern C++ casts
    cout << "x as string is (char*): " << reinterpret_cast<char*>(&x) << endl;
    cout << "x as string is (char[4]): " << reinterpret_cast<char (&)[4]>(x) << endl;
    // interpret the object as a point
    point& p = reinterpret_cast<point&>(x);
    cout << "x as point is (" << p.get_x() << "," << p.get_y() << ")" << endl;
}