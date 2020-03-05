#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, string> countries;
    int q;
    cin >> q;
    string cmd, country, capital;

    for (int i = 0; i < q; i++) {
        cin >> cmd;
        if (cmd == "CHANGE_CAPITAL") {
            cin >> country >> capital;
            if (countries.count(country) == 0) {
                countries[country] = capital;
                cout << "Introduce new country " << country << " with capital " << capital << endl;
            } else if (countries[country] == capital) {
                cout << "Country " << country << " hasn't changed its capital\n";
            } else {
                cout << "Country " << country << " has changed its capital from " <<
                    countries[country] << " to " << capital << endl;
                countries[country] = capital;
            }
        }
        else if (cmd == "RENAME") {
            string new_c;
            cin >> country >> new_c;
            if (countries.count(country) == 0 ||
                countries.count(new_c) == 1 ||
                countries[country] == new_c) {
                cout << "Incorrect rename, skip\n";
            }
            else {
                cout <<"Country " << country << " with capital " << countries[country] <<
                    " has been renamed to " << new_c << endl;
                string t_cap = countries[country];
                countries.erase(country);
                countries[new_c] = t_cap;
            }
        }
        else if (cmd == "ABOUT") {
            cin >> country;
            if (countries.count(country) == 0)
                cout << "Country "<< country << " doesn't exist\n";
            else
                cout << "Country "<< country << " has capital " << countries[country] << endl;
        }
        else {
            if (countries.size() == 0)
                cout << "There are no countries in the world\n";
            else {
                for (auto &c : countries) {
                    cout << c.first << "/" << c.second << " ";
                }
            }
        }
    }
    return (0);
}