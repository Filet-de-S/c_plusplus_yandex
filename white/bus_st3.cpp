#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
int main() {
    int q;
    cin >> q;

    map<set<string>, int> stops;
    for(int i = 0; i < q; ++i) {
        int c;
        cin >> c;
        set<string> new_n;
        for (int j = 0; j < c; ++j) {
            string val;
            cin >> val;
            new_n.insert(val);
        }
        if (stops.count(new_n) == 1)
            cout << "Already exists for " << stops[new_n] << endl;
        else {
            int c = stops.size() + 1;
            stops[new_n] = c;
            cout << "New bus " << c <<endl;
        }
    }
}