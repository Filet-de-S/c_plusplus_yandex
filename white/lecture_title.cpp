#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

struct Specialization {
    string value;
    explicit Specialization (string new_value) {
        value = new_value;
    }
};

struct Course {
    string value;
    explicit Course (string new_value) {
        value = new_value;
    }
};

struct Week {
    string value;
    explicit Week (string new_value) {
        value = new_value;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization spec_o, Course course_o, Week week_o) {
        specialization = spec_o.value;
        course = course_o.value;
        week = week_o.value;
    }
};

int main() {
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );
}