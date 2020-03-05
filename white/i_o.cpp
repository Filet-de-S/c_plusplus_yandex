#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");
    if (input) {
        string line;
        while (getline(input, line))
            cout << line << endl;
    }
}