#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int     main() {
    int q;
    cin >> q;

    map<string, set<string>> synoms;
    for(int i = 0; i < q; ++i) {
        string cmd;
        cin >> cmd;
        string one, two;
        set<string> tmp;
        if (cmd == "ADD") {
            cin >> one >> two;
            synoms[one].insert(two);
            synoms[two].insert(one);
        }
        else if (cmd == "COUNT") {
            string query;
            cin >> query;
            int i = 0;
            if (synoms.count(query) == 1)
                i = synoms[query].size();
            cout << i << endl;
        }
        else {
            cin >> one >> two;
            if (synoms.count(one) == 1) {
                if (synoms[one].count(two) == 1)
                    cout << "YES\n";
                else cout << "NO\n";
            } else cout << "NO\n";
        }
    }

}