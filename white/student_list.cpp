#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <fstream>
#include <iomanip>

using namespace std;

struct Student {
    string FirstName;
    string LastName;
    int Day;
    int Month;
    int Year;
};

int main() {
    int StudCount;
    cin >> StudCount;

    vector<Student> students;
    if (StudCount < 0 || StudCount > 10000)
        cout << "bad request\n";
    else for (int i = 0; i < StudCount; i++) {
        string first, last;
        int day, month, year;
        cin >> first >> last >> day >> month >> year;
        students.push_back({first, last, day, month, year});
    }

    int m;
    int students_sz = students.size();

    cin >> m;
    if (m < 0 || m > 10000)
        cout << "bad request\n";
    else for (int i = 0; i < m; i++) {
        string cmd;
        int n;
        cin >> cmd >> n;
        int ni = n - 1;
        if (n > 0 && cmd == "name" && n <= students_sz)
                cout << students[ni].FirstName << " " << students[ni].LastName << endl;
        else if (n > 0 && cmd == "date" && n <= students_sz)
            cout << students[ni].Day << "." << students[ni].Month << "." << students[ni].Year << endl;
        else
            cout << "bad request\n";
    }
}