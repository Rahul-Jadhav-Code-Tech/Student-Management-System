#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks;

    void input() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\nRoll No : " << rollNo;
        cout << "\nName     : " << name;
        cout << "\nMarks    : " << marks << endl;
    }
};

vector<Student> students;

// Save data to file
void saveToFile() {
    ofstream file("students.txt");

    for (auto s : students) {
        file << s.rollNo << endl;
        file << s.name << endl;
        file << s.marks << endl;
    }

    file.close();
}

// Load data from file
void loadFromFile() {
    ifstream file("students.txt");

    Student s;

    while (file >> s.rollNo) {
        file.ignore();
        getline(file, s.name);
        file >> s.marks;

        students.push_back(s);
    }

    file.close();
}

// Add student
void addStudent() {
    Student s;
    s.input();

    students.push_back(s);

    saveToFile();

    cout << "\nStudent Added Successfully!\n";
}

// Display students
void displayStudents() {

    if (students.empty()) {
        cout << "\nNo Records Found!\n";
        return;
    }

    for (auto s : students) {
        s.display();
        cout << "----------------------";
    }
}

// Search student
int searchStudent(int roll) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].rollNo == roll) {
            return i;
        }
    }

    return -1;
}

// Update student
void updateStudent() {

    int roll;

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;

    int index = searchStudent(roll);

    if (index == -1) {
        cout << "\nStudent Not Found!\n";
        return;
    }

    cout << "\nEnter New Details:\n";

    students[index].input();

    saveToFile();

    cout << "\nStudent Updated Successfully!\n";
}

// Delete student
void deleteStudent() {

    int roll;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    int index = searchStudent(roll);

    if (index == -1) {
        cout << "\nStudent Not Found!\n";
        return;
    }

    students.erase(students.begin() + index);

    saveToFile();

    cout << "\nStudent Deleted Successfully!\n";
}

int main() {

    loadFromFile();

    int choice;

    do {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====\n";

        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Update Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            updateStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}