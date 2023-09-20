#include <stdio.h>
#include <string.h>

// Define password constants for admin and user
#define ADMIN_PASSWORD "we@123"
#define USER_PASSWORD "user@123"

// Maximum number of students, courses, and students array size
int MAX_STUDENTS = 500;
int MAX_COURSES = 5;
int i = 0;

// Define the studentInfo structure
struct studentInfo
{
    char firstName[100];
    char lastName[100];
    int rollNumber;
    float CGPA;
    int courseId[5];
} st[500];

// Function to authenticate the user
int authenticate(char* password) {
    char enteredPassword[100];
    printf("Enter the password: ");
    scanf("%s", enteredPassword);

    if (strcmp(enteredPassword, password) == 0) {
        return 1; // Authentication successful
    } else {
        return 0; // Authentication failed
    }
}

// Function to add a student
void addStudent() {
    if (i < MAX_STUDENTS) {
        printf("Enter student's first name: ");
        scanf("%s", st[i].firstName);
        printf("Enter student's last name: ");
        scanf("%s", st[i].lastName);
        printf("Enter student's roll number: ");
        scanf("%d", &st[i].rollNumber);
        printf("Enter student's CGPA: ");
        scanf("%f", &st[i].CGPA);

        // Initialize course IDs to -1 (indicating no courses)
        for (int j = 0; j < MAX_COURSES; j++) {
            st[i].courseId[j] = -1;
        }

        printf("Student added successfully!\n");
        i++; // Increment the student count
    } else {
        printf("Maximum number of students reached!\n");
    }
}

// Function to find a student by roll number
void findByRollNumber() {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (int j = 0; j < i; j++) {
        if (st[j].rollNumber == roll) {
            printf("Student found:\n");
            printf("First Name: %s\n", st[j].firstName);
            printf("Last Name: %s\n", st[j].lastName);
            printf("CGPA: %.2f\n", st[j].CGPA);
            return;
        }
    }

    printf("Student with roll number %d not found!\n", roll);
}

// Function to find a student by first name
void findByName() {
    char searchName[100];
    printf("Enter first name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int j = 0; j < i; j++) {
        if (strcmp(st[j].firstName, searchName) == 0) {
            printf("Student found:\n");
            printf("Roll Number: %d\n", st[j].rollNumber);
            printf("Last Name: %s\n", st[j].lastName);
            printf("CGPA: %.2f\n", st[j].CGPA);
            found = 1;
        }
    }

    if (!found) {
        printf("Student with first name %s not found!\n", searchName);
    }
}

// Function to find registered students for a course
void findRegisteredStudent() {
    // Implementation for finding registered students goes here
}

// Function to count the total number of students
void totalCount() {
    printf("Total number of students: %d\n", i);
}

// Function to delete a student
void deleteStudent() {
    // Implementation for deleting a student goes here
}

// Function to update student information
void updateStudent() {
    // Implementation for updating student information goes here
}

int main() {
    int isAdmin = 0; // Flag to determine if the user is an admin or not

    // Authenticate the user as admin or user
    char userChoice;
    printf("Login as (a) admin or (u) user: ");
    scanf(" %c", &userChoice);

    if (userChoice == 'a') {
        if (authenticate(ADMIN_PASSWORD)) {
            isAdmin = 1; // Set the admin flag to true
        } else {
            printf("Admin authentication failed. Exiting the program.\n");
            return 1;
        }
    } else if (userChoice == 'u') {
        if (authenticate(USER_PASSWORD)) {
            // User authentication successful, continue as a user
        } else {
            printf("User authentication failed. Exiting the program.\n");
            return 1;
        }
    } else {
        printf("Invalid choice. Exiting the program.\n");
        return 1;
    }

    // If authentication is successful, continue with the program
    int choice;
    do {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Find by Roll Number\n");
        printf("3. Find by First Name\n");
        printf("4. Find Registered Student by Course ID\n");
        printf("5. Total Student Count\n");
        printf("6. Delete Student by Roll Number\n");
        printf("7. Update Student Information\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                findByRollNumber();
                break;
            case 3:
                findByName();
                break;
            case 4:
                findRegisteredStudent();
                break;
            case 5:
                totalCount();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                updateStudent();
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
