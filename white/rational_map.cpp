#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

int Nod(int& numer, int& denom) {
    int a, b, left;
    a = numer;
    b = denom;
    while ((left = a % b)) {
        a = b;
        b = left;
    }
    numer = numer / b;
    denom = denom / b;
    if (denom < 0) {
        denom = -denom;
        numer = -numer;
    }
    return b;
}

class Rational {
public:
    Rational() {
        numer = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        numer = numerator;
        denom = denominator;
        if ((numer < 0 && denom < 0) || denom < 0) {
            numer = -numer;
            denom = -denom;
        }
        if (numer == 0)
            denom = 1;
        else
            Nod(numer, denom);
    }

    int Numerator() const {
        return (numer);
    }

    int Denominator() const {
        return (denom);
    }

private:
    int numer;
    int denom;
};

void ReadyRat(const Rational& lhs, const Rational& rhs, int& nok, int& ld, int& rd) {
    ld = lhs.Denominator();
    rd = rhs.Denominator();
    if (ld == rd) {
        nok = rd;
        ld = lhs.Numerator();
        rd = rhs.Numerator();
        return;
    }
    int nod = Nod(ld, rd);
    nok = (lhs.Denominator() * rhs.Denominator()) / nod;
    ld = nok / lhs.Denominator() * lhs.Numerator();
    rd = nok / rhs.Denominator() * rhs.Numerator();
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() &&
           lhs.Denominator() == rhs.Denominator();
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    int nok, ld, rd;
    ReadyRat(lhs, rhs, nok, ld, rd);
    if (lhs.Numerator() < 0 && lhs.Denominator() < 0)
        ld = -ld;
    if (rhs.Numerator() < 0 && rhs.Denominator() < 0)
        rd = -rd;
    if (ld < rd)
        return true;
    return false;
}
// Вставьте сюда реализацию operator == для класса Rational из второй части

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
