# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

vector<string> find_trigrams(const string &s) {
    vector<string> trigrams;
    int sz = s.size();
    for (int idx = 0; idx+3 <= sz; ++idx) {
        trigrams.push_back(
            string(s.begin()+idx, s.begin()+idx+3)
        );
    }
    sort(trigrams.begin(), trigrams.end());
    return trigrams;
}

int main() {
    string s;
    while (cin >> s) {
        transform(s.begin(), s.end(), s.begin(),[](unsigned char c) { return std::tolower(c); });
        vector<string> trigrams = find_trigrams(s);
        cout << s << " " << trigrams.size() << " ";
        for (string tri : trigrams) {
            cout << tri << " ";
        }
        cout << "\n";
    }
    return 0;
}
