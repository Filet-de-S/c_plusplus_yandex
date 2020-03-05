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
        if (numer < 0 && denom < 0) {
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

void ReadyRat(Rational lhs, Rational rhs, int& nok, int& ld, int& rd) {
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
    rd = nok / rhs.Denominator() * rhs.Numerator();;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() &&
           lhs.Denominator() == rhs.Denominator();
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int ld, rd, nok;
    ReadyRat(lhs, rhs, nok, ld, rd);
    return (Rational(ld + rd, nok));
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int ld, rd, nok;
    ReadyRat(lhs, rhs, nok, ld, rd);
    return (Rational(ld - rd, nok));
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
