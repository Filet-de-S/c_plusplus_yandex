#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string  buses_for_stop(const map<int, vector<string>>& bus_stops, const string& stop, string parent) {
    string buses = "";
    for (const auto& st_v : bus_stops) {
        if (parent == st_v.second[0])
            continue;
        for (const string& st : st_v.second) {
            if (st == stop && st != st_v.second[0]) {
                buses += st_v.second[0] + " ";
            }
        }
    }
    return (buses);
}

map<string, vector<string>> normap(const map<int, vector<string>>& bus_stops) {
    map<string, vector<string>> norm;

    for (auto& vect : bus_stops) {
        for (int i = 1; i < vect.second.size(); ++i) {
            norm[vect.second[0]].push_back(vect.second[i]);
        }
    }
    return norm;
}

int main() {
    int q;
    cin >> q;

    int stop_count;
    string cmd;
    string bus;
    string stop;
    string buses;
    int bus_count = 0;
    map <int, vector<string>> bus_stops;
    for(int i = 0; i < q; ++i) {
        cin >> cmd;
        if (cmd == "NEW_BUS") {
            cin >> bus >> stop_count;
            bus_stops[bus_count].push_back(bus);
            for(int j = 0; j < stop_count; ++j) {
                cin >> stop;
                bus_stops[bus_count].push_back(stop);
            }
            bus_count++;
        }
        else if (cmd == "BUSES_FOR_STOP") {
            cin >> stop;
            buses = buses_for_stop(bus_stops, stop, "");
            if (buses == "")
                cout << "No stop\n";
            else
                cout << buses << endl;
        }
        else if (cmd == "STOPS_FOR_BUS") {
            cin >> bus;
            int exist = 0;
            for (const auto& st_v : bus_stops) {
                if (st_v.second[0] == bus) {
                    exist = 1;
                    for (int j = 1; j < st_v.second.size(); ++j) {
                        buses = buses_for_stop(bus_stops, st_v.second[j], bus);
                        cout << "Stop " << st_v.second[j] << ": " <<
                            (buses == "" ? "no interchange" : buses) << endl;
                    }
                    break;
                }
            }
            if (exist == 0)
                cout << "No bus\n";
        }
        else {
            map <string, vector<string>> alpha = normap(bus_stops);
            string out = "";
            for (const auto& vect : alpha) {
                out = "Bus ";
                out += vect.first + ": ";
                for (const auto& stops : vect.second) {
                    out += stops + " ";
                }
                cout << out << endl;
            }
            if (out == "")
                cout << "No buses\n";
        }
    }
    return (0);
}