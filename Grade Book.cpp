#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function prototypes
double calculateAverage(double scores[], int size);
char determineGrade(double average);

int main() {
    const int NUM_STUDENTS = 5;
    const int NUM_TESTS = 4;

    string studentNames[NUM_STUDENTS];
    char letterGrades[NUM_STUDENTS];
    double testScores[NUM_STUDENTS][NUM_TESTS];

    // Introduction
    cout << "Welcome to the Grade Calculator Program.\n";
    cout << "You will enter each student's name and their test scores.\n";
    cout << "The program will calculate their average and assign a letter grade.\n\n";

    // Input student names and test scores
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Enter the name of student #" << (i + 1) << ": ";
        getline(cin, studentNames[i]);

        for (int j = 0; j < NUM_TESTS; j++) {
            do {
                cout << "Enter test score #" << (j + 1) << " for " << studentNames[i] << " (0-100): ";
                cin >> testScores[i][j];
                if (testScores[i][j] < 0 || testScores[i][j] > 100) {
                    cout << "Invalid score. Please enter a score between 0 and 100.\n";
                }
            } while (testScores[i][j] < 0 || testScores[i][j] > 100);
        }
        cin.ignore(); // Clear the newline character
    }

    // Process and display results
    cout << "\nStudent Results:\n";
    cout << left << setw(15) << "Name" << setw(10) << "Average" << "Grade\n";
    cout << string(35, '-') << endl;

    for (int i = 0; i < NUM_STUDENTS; i++) {
        double average = calculateAverage(testScores[i], NUM_TESTS);
        letterGrades[i] = determineGrade(average);

        cout << left << setw(15) << studentNames[i] << setw(10) << fixed << setprecision(2)
            << average << letterGrades[i] << endl;
    }

    return 0;
}

// Function to calculate the average of an array of scores
double calculateAverage(double scores[], int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += scores[i];
    }
    return total / size;
}

// Function to determine the letter grade based on the average
char determineGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}