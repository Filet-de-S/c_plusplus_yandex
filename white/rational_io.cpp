#include <iostream>
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
    rd = nok / rhs.Denominator() * rhs.Numerator();
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() &&
           lhs.Denominator() == rhs.Denominator();
}

istream& operator>>(istream& input, Rational& out) {
    int a, b;
    if (input >> a) {
        input.ignore(1);
        input >> b;
        out = Rational(a, b);
    }
    return input;
}

ostream& operator<<(ostream& out, const Rational& input) {
    out << input.Numerator() << "/" << input.Denominator();
    return out;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
