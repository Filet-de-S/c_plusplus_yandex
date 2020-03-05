#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

class Incognizable {
    public:
    Incognizable() {}
    Incognizable(int i) {}
    Incognizable(int i, int j) {}

};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}