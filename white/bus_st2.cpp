#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int main() {
    int q;
    cin >> q;

    map <vector<string>, int> stops_route;
    int new_v;
    int new_r;
    for (int i = 0; i < q; ++i) {
        vector<string> route;
        cin >> new_r;
        for (int j = 0; j < new_r; ++j) {
            string stop;
            cin >> stop;
            route.push_back(stop);
        }
        if (stops_route.count(route) != 0)
            cout << "Already exists for " << stops_route[route] <<endl;
        else {
            new_v = stops_route.size();
            new_v++;
            stops_route[route] = new_v;
            cout << "New bus " << new_v<<endl;
        }
    }
}