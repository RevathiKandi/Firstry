#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<string> courseNames(numCourses);
    vector<int> credits(numCourses);
    vector<char> grades(numCourses);

    float totalPoints = 0;
    int totalCredits = 0;

    // Grade to point mapping
    auto gradeToPoint = [](char grade) {
        switch (grade) {
            case 'A': return 10;
            case 'B': return 9;
            case 'C': return 8;
            case 'D': return 7;
            case 'E': return 6;
            case 'F': return 0;
            default: return -1;
        }
    };

    // Input section
    for (int i = 0; i < numCourses; ++i) {
        cout << "\nEnter course " << i + 1 << " name: ";
        cin >> courseNames[i];
        cout << "Enter credits for " << courseNames[i] << ": ";
        cin >> credits[i];
        cout << "Enter grade (A-F) for " << courseNames[i] << ": ";
        cin >> grades[i];

        int point = gradeToPoint(toupper(grades[i]));
        if (point == -1) {
            cout << "Invalid grade entered. Try again.\n";
            i--; // repeat this course
            continue;
        }

        totalPoints += point * credits[i];
        totalCredits += credits[i];
    }

    float cgpa = totalPoints / totalCredits;

    // Output section
    cout << fixed << setprecision(2);
    cout << "\nCourse Grades:\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << courseNames[i] << ": Grade " << grades[i]
             << ", Credits " << credits[i] << "\n";
    }

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}