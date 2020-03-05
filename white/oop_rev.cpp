#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

class ReversibleString {
    public:
        void Reverse() {
            string tmp;
            for (int i = str.length() - 1; i > -1; --i) {
                tmp += str[i];
            }
            str = tmp;
        }

        string ToString() const {
            return str;
        }

        ReversibleString() {}
        ReversibleString(const string& inpstr) {
            str = inpstr;
        }

    private:
        string str = "";
};


int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
