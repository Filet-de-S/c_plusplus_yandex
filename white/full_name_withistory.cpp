#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

class Person {
public:
    Person(const string& first, const string& last, int year) {
        f_name[year] = first;
        l_name[year] = last;
    }

    void ChangeFirstName(int year, const string& first_name) {
        if (GetFullName(year) == "No person")
            return;
        f_name[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        if (GetFullName(year) == "No person")
            return;
        l_name[year] = last_name;
    }
    string GetFullName(int year) const {
            int fl_f = -1;
            int fl_l = -1;
            for (int i = year; i > -1; --i) {
                if (fl_f == -1 && f_name.count(i) > 0)
                    fl_f = i;
                if (fl_l == -1 && l_name.count(i) > 0)
                    fl_l = i;
                if (fl_l != -1 && fl_f != -1)
                    break;
            }
        map<int, string> f_copy;
        map<int, string> l_copy;
        if (fl_f == -1 && fl_l == -1)
                return "No person";
            else if (fl_l == -1) {
                f_copy = f_name;
                return f_copy[fl_f] + " with unknown last name";
            }
            else if (fl_f == -1) {
                l_copy = l_name;
                return l_copy[fl_l] + " with unknown first name";
            }
            else {
                l_copy = l_name;
                f_copy = f_name;
                return f_copy[fl_f] + " " + l_copy[fl_l];
            }
    }
    string GetFullNameWithHistory(int year) const {
        vector<string>names(0);
        vector<string>l_names(0);
        for (int i = year; i > -1; --i) {
            map<int, string> f_copy;
            map<int, string> l_copy;
            l_copy = l_name;
            f_copy = f_name;
            if (f_name.count(i) > 0)
                names.push_back(f_copy[i]);
            if (l_name.count(i) > 0)
                l_names.push_back(l_copy[i]);
        }
        if (names.empty() && l_names.empty())
            return "No person";
        string s_names;
        string sl_names;
        if (l_names.empty()) {
            s_names = HistoryName(names);
            return s_names + " with unknown last name";
        }
        if (names.empty()) {
            sl_names = HistoryName(l_names);
            return sl_names + " with unknown first name";
        }
        sl_names = HistoryName(l_names);
        s_names = HistoryName(names);
        return s_names + " " + sl_names;
    }
private:
    string HistoryName(vector<string> names) const {
        int s = names.size();
        if (s == 1)
            return (names[0]);
        else if (s == 2 && names[1] != names[0])
            return (names[0] + " (" + names[1] + ")");
        string old_names = names[0] + " (";
        for (int i = 1; i < s; ++i) {
            if (names[i] == names[i - 1])
                continue;
            old_names += names[i] + ", ";
        }
        if (old_names == (names[0] + " ("))
            return names[0];
        old_names.erase(old_names.length() - 2);
        old_names += ")";
        return (old_names);
    }

    map<int, string> f_name;
    map<int, string> l_name;
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}