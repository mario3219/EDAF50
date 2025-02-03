# include <iostream>
using std::cout;
using std::string;
using std::swap;

bool palindrome(const string& x) {
    int size = x.size();
    string xcopy = x;
    for (int e = 0; e <= size-e-1; ++e) {
        swap(xcopy[e], xcopy[size-e-1]);
    }
    if (xcopy == x) {
        return true;
    } else {
        return false;
    }
};

int main() {
    string s1 = "test";
    cout << palindrome(s1) << "\n";
    string s2 = "tsest";
    cout << palindrome(s2) << "\n";
}