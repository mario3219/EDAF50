#include <iostream>
#include "edit_distance.h"
#include <algorithm>

using namespace std;

int edit_distance(const string& x, const string& y) {
    int d[x.size()+1][y.size()+1];

    for (int i = 0; i <= x.size(); ++i) {d[i][0] = i;}
    for (int j = 0; j <= y.size(); ++j) {d[0][j] = j;}

    for (int i = 1; i <= x.size(); ++i) {
        for (int j = 1; j <= y.size(); ++j) {
            if (x[i-1] == y[j-1]) {
                d[i][j] = d[i-1][j-1];
            } else {
                int a = d[i-1][j-1]+1;
                int b = d[i-1][j]+1;
                int c = d[i][j-1]+1;
                d[i][j] = min({a,b,c});
            }
        }
    }
    return d[x.size()][y.size()];
}