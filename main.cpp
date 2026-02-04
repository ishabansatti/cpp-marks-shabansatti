// test_student.cpp
#include <iostream>
#include <iomanip>      // for std::fixed and std::setprecision
#include <string>
#include "student.h"    // include our struct header

using namespace std;

// Function to check one student and return score (0–10)
int evaluateStudent(const Student& s) {
    int score = 0;

    cout << "\nEvaluating student: " << s.name << " (Roll: " << s.rollNumber << ")\n";

    // Test 1: name is not empty
    if (!s.name.empty()) {
        score += 2;
        cout << "[OK] Name is set\n";
    } else {
        cout << "[FAIL] Name is empty\n";
    }

    // Test 2: roll number is positive
    if (s.rollNumber > 0) {
        score += 2;
        cout << "[OK] Roll number is positive\n";
    } else {
        cout << "[FAIL] Roll number <= 0\n";
    }

    // Test 3: marks are in valid range 0–100
    bool marksValid = true;
    for (int i = 0; i < 3; ++i) {
        if (s.marks[i] < 0 || s.marks[i] > 100) {
            marksValid = false;
            break;
        }
    }
    if (marksValid) {
        score += 3;
        cout << "[OK] All marks are between 0 and 100\n";
    } else {
        cout << "[FAIL] Some marks are out of range (0–100)\n";
    }

    // Test 4: percentage is correctly calculated (allow small floating-point difference)
    float expected = (s.marks[0] + s.marks[1] + s.marks[2]) / 3.0f;
    if (abs(s.percentage - expected) < 0.01f) {
        score += 3;
        cout << "[OK] Percentage calculated correctly ("
             << fixed << setprecision(2) << s.percentage << "%)\n";
    } else {
        cout << "[FAIL] Wrong percentage. Expected ~"
             << fixed << setprecision(2) << expected
             << "%, got " << s.percentage << "%\n";
    }

    cout << "→ Final score for this student: " << score << "/10\n";
    return score;
}

int main() {
    cout << "=== Student Struct Test Program ===\n\n";

    // Test case 1 - Good data
    Student s1;
    s1.name = "Ahmed Khan";
    s1.rollNumber = 101;
    s1.marks[0] = 85.5f;
    s1.marks[1] = 92.0f;
    s1.marks[2] = 78.0f;
    s1.calculatePercentage();

    int score1 = evaluateStudent(s1);

    // Test case 2 - Missing name
    Student s2;
    s2.name = "";
    s2.rollNumber = 202;
    s2.marks[0] = 65;
    s2.marks[1] = 70;
    s2.marks[2] = 88;
    s2.calculatePercentage();

    int score2 = evaluateStudent(s2);

    // Test case 3 - Invalid marks
    Student s3;
    s3.name = "Sara Ahmed";
    s3.rollNumber = 303;
    s3.marks[0] = 95;
    s3.marks[1] = 110;      // invalid
    s3.marks[2] = -5;       // invalid
    s3.calculatePercentage();

    int score3 = evaluateStudent(s3);

    // Overall result
    cout << "\n=== Summary ===\n";
    cout << "Test 1: " << score1 << "/10\n";
    cout << "Test 2: " << score2 << "/10\n";
    cout << "Test 3: " << score3 << "/10\n";

    int total = score1 + score2 + score3;
    cout << "Total score: " << total << "/30  ("
         << fixed << setprecision(1)
         << (total / 30.0 * 100) << "%)\n";

    if (total >= 25) {
        cout << "Excellent! The struct implementation looks solid.\n";
    } else if (total >= 18) {
        cout << "Good, but some issues need fixing.\n";
    } else {
        cout << "Needs improvement - check the failing tests above.\n";
    }

    return 0;
}