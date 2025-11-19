#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    float m1, m2, m3, m4, m5;
    float total, percent;
    char grade;
};

char calcGrade(float percent) {
    if (percent >= 90) return 'A';
    else if (percent >= 75) return 'B';
    else if (percent >= 60) return 'C';
    else if (percent >= 40) return 'D';
    return 'F';
}

int main() {
    Student s[50];
    int count = 0;
    int choice;

    do {
        cout << "\n==== Student Grade Management ====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid input! Please enter numbers only.\n";
            continue;
        }

        if (choice == 1) {
            cout << "\nEnter Roll No: ";
            cin >> s[count].roll;

            cout << "Enter Name: ";
            cin >> s[count].name;

            cout << "Enter Marks of 5 Subjects: ";
            cin >> s[count].m1 >> s[count].m2 >> s[count].m3
                >> s[count].m4 >> s[count].m5;

            s[count].total = s[count].m1 + s[count].m2 + s[count].m3 +
                             s[count].m4 + s[count].m5;

            s[count].percent = s[count].total / 5.0;
            s[count].grade = calcGrade(s[count].percent);

            count++;
            cout << "\nStudent Added Successfully!\n";
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "\nNo records available!\n";
            } else {
                cout << "\n---- Student Records ----\n";
                for (int i = 0; i < count; i++) {
                    cout << "Roll: " << s[i].roll
                         << ", Name: " << s[i].name
                         << ", Total: " << s[i].total
                         << ", %: " << s[i].percent
                         << ", Grade: " << s[i].grade << endl;
                }
            }
        }

        else if (choice == 3) {
            int r;
            cout << "Enter Roll No to Search: ";
            cin >> r;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (s[i].roll == r) {
                    cout << "\nStudent Found:\n";
                    cout << "Roll: " << s[i].roll << endl;
                    cout << "Name: " << s[i].name << endl;
                    cout << "Total Marks: " << s[i].total << endl;
                    cout << "Percentage: " << s[i].percent << endl;
                    cout << "Grade: " << s[i].grade << endl;

                    found = true;
                }
            }
            if (!found)
                cout << "Student Not Found.\n";
        }

        else if (choice != 4) {
            cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 4);

    cout << "\nExiting Program... Goodbye!\n";
    return 0;
}
