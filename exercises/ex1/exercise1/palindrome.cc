# include <iostream>
using std::cout;
using std::string;
using std::swap;

string palindrome(const string& x) {
    int size = x.size();
    string xcopy = x;
    for (int e = 0; e <= size; ++e) {
        swap(xcopy[e], xcopy[size-e]);
        cout << xcopy << '\n';
    }
    return xcopy;
};

int main() {
    string s = "test";
    cout << palindrome(s);
}