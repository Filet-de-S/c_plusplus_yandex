#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    int column, str;
    string line;

    if (input >> str && input >> column) {
        for (int j = 0; j < str; j++) {
            int x;
            for (int i = 0; i < column - 1; i++) {
                input >> x;
                input.ignore(1);
                cout << setw(10) << x << " ";
            }
            input >> x;
            input.ignore(1);
            cout << setw(10) << x;
            if (j + 1 != str)
                cout << endl;
        }
    }
}