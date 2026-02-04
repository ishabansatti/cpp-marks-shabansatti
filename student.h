// student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    std::string name;
    int rollNumber;
    float marks[3];     // marks in 3 subjects
    float percentage;

    // Simple member function to calculate percentage
    void calculatePercentage() {
        float total = marks[0] + marks[1] + marks[2];
        percentage = (total / 300.0f) * 100.0f;
    }

    // Helper to display student info
    void display() const {
        std::cout << "Name        : " << name << "\n";
        std::cout << "Roll Number : " << rollNumber << "\n";
        std::cout << "Marks       : " << marks[0] << ", "
                  << marks[1] << ", " << marks[1] << "\n";
        std::cout << "Percentage  : " << percentage << "%\n";
    }
};


#endif
