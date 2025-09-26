#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

void displayStudents(string names[], int grades[], int n) {
    cout << "\nStudents List:\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << names[i] << " - " << grades[i] << endl;
    }
}

void searchStudent(string names[], int grades[], int n) {
    string searchName;
    cout << "\nEnter the student name to search: ";
    cin >> searchName;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (names[i] == searchName) {
            cout << "Found " << names[i]
                 << " with grade: " << grades[i] << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "⚠️ Student not found.\n";
}

void showStatistics(int grades[], int n) {
    int maxGrade = grades[0];
    int minGrade = grades[0];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (grades[i] > maxGrade) maxGrade = grades[i];
        if (grades[i] < minGrade) minGrade = grades[i];
        sum += grades[i];
    }

    double avg = (double)sum / n;

    cout << "\n📊 Statistics:\n";
    cout << "Highest grade: " << maxGrade << endl;
    cout << "Lowest grade: " << minGrade << endl;
    cout << "Average: " << avg << endl;
}

void sortByGrades(string names[], int grades[], int n, bool ascending = true) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if ((ascending && grades[i] > grades[j]) ||
                (!ascending && grades[i] < grades[j])) {
                int temp = grades[i];
                grades[i] = grades[j];
                grades[j] = temp;

                string tempName = names[i];
                names[i] = names[j];
                names[j] = tempName;
            }
        }
    }

    if (ascending)
        cout << "\n✅ Students sorted by grades (Ascending).\n";
    else
        cout << "\n✅ Students sorted by grades (Descending).\n";
}

void showPassFail(string names[], int grades[], int n) {
    cout << "\n🎯 Passed:\n";
    for (int i = 0; i < n; i++) {
        if (grades[i] >= 50) {
            cout << names[i] << " - " << grades[i] << endl;
        }
    }

    cout << "\n⚠️ Failed:\n";
    for (int i = 0; i < n; i++) {
        if (grades[i] < 50) {
            cout << names[i] << " - " << grades[i] << endl;
        }
    }
}

int main() {
    string names[MAX];
    int grades[MAX];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Student " << i+1 << " name: ";
        cin >> names[i];
        cout << "Student " << i+1 << " grade: ";
        cin >> grades[i];
    }

    int choice = -1; 
    while (choice != 0) {
        cout << "\n========== Menu ==========\n";
        cout << "1. Show all students\n";
        cout << "2. Search for a student\n";
        cout << "3. Show grade statistics\n";
        cout << "4. Sort students (Ascending)\n";
        cout << "5. Sort students (Descending)\n";
        cout << "6. Show pass/fail\n";
        cout << "0. Exit\n";
        cout << "Choose: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n'); 
            cout << "❌ Invalid input, please enter a number.\n";
            continue;
        }

        switch(choice) {
            case 1: displayStudents(names, grades, n); break;
            case 2: searchStudent(names, grades, n); break;
            case 3: showStatistics(grades, n); break;
            case 4: sortByGrades(names, grades, n, true); break;
            case 5: sortByGrades(names, grades, n, false); break;
            case 6: showPassFail(names, grades, n); break;
            case 0: cout << "👋 Goodbye\n"; break;
            default: cout << "❌ Invalid choice, please try again.\n";
        }
    }

    return 0;
}
