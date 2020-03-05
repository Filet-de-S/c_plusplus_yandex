#include <algorithm>
#include <vector>
#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

int     main() {
    int q;
    cin >> q;

    vector <string> mod;
    for (int i = 0; i < q; ++i) {
        string n;
        cin >> n;
        mod.push_back(n);
    }
    sort(begin(mod), end(mod), [] (string a, string b) {
        string b1;
        string a1;
        for (auto &c : a) {
            a1 += tolower(c);
        }
        for (auto &c : b) {
            b1 += tolower(c);
        }
        return (a1 < b1);
    });
    for (const auto& num : mod) {
        cout << num << " ";
    }
}