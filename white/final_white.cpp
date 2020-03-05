#include <iostream>
#include <exception>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>

using namespace std;

class Date {
public:
    Date() {};
    Date(int y, int m, int d) {
      Year = y;
      Month = m;
      Day = d;
    };
    int GetYear() const {
        return Year;
    };
    int GetMonth() const {
        return Month;
    };
    int GetDay() const {
        return Day;
    };

private:
    int Year;
    int Month;
    int Day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() < rhs.GetYear())
        return true;
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() < rhs.GetMonth())
            return true;
        else if (lhs.GetMonth() == rhs.GetMonth()) {
            return (lhs.GetDay() < rhs.GetDay());
        }
    }
    return false;
}

//    bool operator<(const Date& lhs, const Date& rhs) {
//        // воспользуемся тем фактом, что векторы уже можно сравнивать на <:
//        // создадим вектор из года, месяца и дня для каждой даты и сравним их
//        return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
//               vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
//    }

void wrong_date(stringstream& stream, string& line) {
    if (stream.peek() != '-') {
        throw domain_error("Wrong date format: " + line);
    }
    stream.ignore(1);
}

void valid_date(int Day, int Month) {
    if (Month < 1 || Month > 12) {
        throw invalid_argument("Month value is invalid: " + to_string(Month));
    }
    if (Day < 1 || Day > 31) {
        throw invalid_argument("Day value is invalid: " + to_string(Day));
    }
}

void check_format(string& line) {
    if (!isdigit(line[line.size() - 1]))
        throw domain_error("Wrong date format: " + line);
    int i, j;
    i = j = 0;
    for (char& c : line) {
        if (c == '-') {
            i++;
            j++;
            continue;
        }
        else if (i > 2 || isalpha(c))
            throw domain_error("Wrong date format: " + line);
        i = 0;
    }
    if (j > 2)
        throw domain_error("Wrong date format: " + line);
}

istream& operator>>(istream& input, Date& date) {
    string line;
    try {
        input.ignore(1);
        getline(input, line, ' ');
        check_format(line);
        stringstream stream(line);
        int Year, Month, Day;
        stream >> Year;
        wrong_date(stream, line);
        stream >> Month;
        wrong_date(stream, line);
        stream >> Day;
        valid_date(Day, Month);
        date = Date(Year, Month, Day);
    } catch (exception& e) {
        cout << e.what() << endl;
        exit(0);
    }
    return input;
}

//    Date ParseDate(const string& date) {
//        istringstream date_stream(date);
//        bool ok = true;
//
//        int year;
//        ok = ok && (date_stream >> year);
//        ok = ok && (date_stream.peek() == '-');
//        date_stream.ignore(1);
//
//        int month;
//        ok = ok && (date_stream >> month);
//        ok = ok && (date_stream.peek() == '-');
//        date_stream.ignore(1);
//
//        int day;
//        ok = ok && (date_stream >> day);
//        ok = ok && date_stream.eof();
//
//        if (!ok) {
//            throw logic_error("Wrong date format: " + date);
//        }
//        return Date(year, month, day);
//    }

ostream& operator<<(ostream& out, const Date& date) {
    cout << setfill('0')
         << setw(4) << date.GetYear() << "-"
         << setw(2) << date.GetMonth() << "-"
         << setw(2) << date.GetDay();
    return out;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        events[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (events.count(date) && events[date].count(event)) {
            events[date].erase(event);
            return true;
        }
        return false;
    }
    int  DeleteDate(const Date& date) {
        int events_count = 0;
        if (events.count(date)) {
            events_count = events[date].size();
            events.erase(date);
        }
        return events_count;
    }
    void Find(const Date& date) const {
        if (events.count(date)) {
            for (auto& event : events.at(date)) {
                cout << event << endl;
            }
        }
    }
    void    printAll() const {
        for (auto& oneDate : events) {
            for (const string& event : oneDate.second) {
                cout << oneDate.first << " " << event << endl;
            }
        }
    }

private:
    map<Date, set<string>> events;
};

int     main() {
    Database db;

    string cmd;
    while (getline(cin, cmd)) {
        stringstream line(cmd);
        line >> cmd;
        if (cmd == "") {
            continue;
        }

        Date date;
        string event;
        if (cmd == "Add") {
            line >> date >> event;
            db.AddEvent(date, event);
        } else if (cmd == "Print") {
            db.printAll();
        } else if (cmd == "Del") {
            line >> date >> event;
            if (event != "") {
                if (db.DeleteEvent(date, event) == true)
                    cout << "Deleted successfully\n";
                else
                    cout << "Event not found\n";
            } else
                cout << "Deleted " << db.DeleteDate(date) << " events\n";
        } else if (cmd == "Find") {
            line >> date;
            db.Find(date);
        } else {
            cout << "Unknown command: " << cmd << endl;
            return (0);
        }
    }
    return (0);
 }




//    Wrong date format:
//    a1-1-1
//    1a-1-1
//    1-a1-1
//    1-1a-1
//    1-1-a1
//    1-1-1a
//    1-1-a
//            a-1-1
//    1-a-1
//    1-1--a
//    -1-1
//    1-1-
//    -1-1-
//    1---1-1
//    1-1---1
//    1-1--
//    --1-1
//
//    1--1-0
//    Month value is invalid: -1
//    1-1--1
//    Day value is invalid: -1
//    1--1--1
//    Month value is invalid: -1
//
//    На пустой дб:
//    Del 1-1-1
//    Deleted 0 events
//            Del 1-1-1 a
//            Event not found
//            Find 1-1-1
//    Print
