#include "student_records.hpp"
#include <iostream>

using namespace std;

bool isValidStudentId(string id) {
    if (id.length() == 0) { // consider combining these two if statements
        return false;
    }
    if (id.length() < 3) {
        return false;
    }
    if (id[0] < 'A' || id[0] > 'Z') { //double logic should be removed. This doesn't seem useful, so I'll take out the second if.
        return false;
    }
    // TODO:// A valid ID should have at least 3 characters.// A valid ID should start with an uppercase letter.
    // Hint: You may compare characters directly, such as id[0] >= 'A'.
    return true;
}

bool isValidScore(double score) {
    // TODO: Return true when score is between 0 and 100, inclusive.
    return score >= 0 && score <= 100;; // double ; is not wrong, but definitely not needed
}

void printStudent(const Student& student) {
    cout << student.id << " "
         << student.name << " "
         << student.score << " "
         << determineLetterGrade(student.score) //good multi-line cout
         << endl;
}

void printStudents(const Student students[], int size) {
    if (students == nullptr || size <= 0) {
        cout << "No students to print." << endl; //no need for a return statement here
        return;
    }

    for (int i = 0; i < size; i++) {
        printStudent(students[i]); 
    }
}

double calculateAverageScore(const Student students[], int size) {
    if (students == nullptr || size <= 0) {
        return 0.0;
    }
    double total = 0; //since you'll return 0 anyway, you could simply return total and place this variable at the top.

    for (int i = 0; i < size; i++) {
        total += students[i].score;
    }
    
    return total / size;
}
// TODO:// If the array is null or size is invalid, return 0.0.// Otherwise, return the average score.
double findHighestScore(const Student students[], int size) {
    if (students == nullptr || size <= 0) {
        return 0.0;
    }
    double highest = students[0].score;

    for (int i = 1; i < size; i++) {

        if (students[i].score > highest) {
            highest = students[i].score;
        }
    }
    // TODO:// If the array is null or size is invalid, return 0.0.// Otherwise, return the highest score.
    return highest;
}

int findStudentById(const Student students[], int size, string targetId) {
    
    if (students == nullptr || size <=0) {
        return -1; //works in this specific constraint
    }

    for (int i = 0; i < size; i++) {

        if (students[i].id == targetId) {
            return i;
        }
    }
    // TODO:// Search by comparing students[i].id to targetId.// Return the index of the matching student.
    // Return -1 if no student is found.
    return -1;
}

char determineLetterGrade(double score) {
   
    if (score >= A_MINIMUM) {
        return 'A';
    }
    else if (score >= B_MINIMUM) {
        return 'B';
    }
    else if (score >= C_MINIMUM) {
        return 'C';
    }
    else if (score >= D_MINIMUM) {
        return 'D';
    }
    else {
        return 'F';
    }
}
