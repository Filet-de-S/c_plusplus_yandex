#include <iostream>
#include <exception>

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

    Rational(int numerator) {
        throw invalid_argument("");
    }

    Rational(int numerator, int denominator) {
        numer = numerator;
        denom = denominator;
        if (denom == 0) {
           throw invalid_argument("");
        }
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

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(),
                    lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0)
        throw domain_error("");
    return Rational(lhs.Numerator() * rhs.Denominator(),
                    lhs.Denominator() * rhs.Numerator());
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

istream& operator>>(istream &stream, Rational& out) {
    int numer, denom;
    stream >> numer;
    stream.ignore(1);
    stream >> denom;
    out = Rational(numer, denom);
    return stream;
}

ostream& operator<<(ostream& out, const Rational& input) {
    out << input.Numerator() << "/" << input.Denominator();
    return out;
}

int main() {
    Rational num1;
    Rational num2;
    char oper;

    try {
        cin >> num1 >> oper >> num2;
        if (oper == '+') {
            cout << (num1 + num2);
        } else if (oper == '-') {
            cout << (num1 - num2);
        } else if (oper == '*') {
            cout << (num1 * num2);
        } else {
            cout << (num1 / num2);
        }
    } catch (invalid_argument&) {
        cout << "Invalid argument\n";
    } catch (domain_error&) {
        cout << "Division by zero\n";
    }
    return 0;
}
