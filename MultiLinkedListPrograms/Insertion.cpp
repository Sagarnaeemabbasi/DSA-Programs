#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include <limits>
using namespace std;
struct Course
{
    int courseNo;
    Course *nextCourse;
    struct Student *fisrtStudent;
};
struct Student
{
    int studentId;
    string studentName;
    Student *nextStud;
    int courseNo;
    Course *linkedCourse;
};

Course *InsertNewCourse(Course *head, int courseNo)
{
    if (head == nullptr)
    {
        Course *ptr = new Course;
        ptr->courseNo = courseNo;
        ptr->nextCourse = nullptr;
        ptr->fisrtStudent = nullptr;
        return ptr;
    }
    head->nextCourse = InsertNewCourse(head->nextCourse, courseNo);
    return head;
};
Course *FindCourseByCourseNumber(Course *firstCourse, int courseNo)
{
    if (firstCourse == nullptr)
    {
        return nullptr;
    };
    if (firstCourse->courseNo == courseNo)
    {
        return firstCourse;
    }
    return FindCourseByCourseNumber(firstCourse->nextCourse, courseNo);
};
Student *InsertStudentInAPartCourse(Student *firstStudent, int courseNo, int studId, string studName)
{
    if (firstStudent == nullptr)
    {
        Student *newStd = new Student;
        newStd->courseNo = courseNo;
        newStd->studentName = studName;
        newStd->studentId = studId;
        newStd->nextStud = nullptr;
        return newStd;
    };
    firstStudent->nextStud = InsertStudentInAPartCourse(firstStudent->nextStud, courseNo, studId, studName);
    return firstStudent;
}

bool InsertNewStudent(Course *firstCourse, int courseNo, int studId, string studName)
{
    Course *course = FindCourseByCourseNumber(firstCourse, courseNo);
    if (course == nullptr)
    {
        return false;
    };
    struct Student *fisrtStu = InsertStudentInAPartCourse(course->fisrtStudent, courseNo, studId, studName);
    course->fisrtStudent = fisrtStu;
    return true;
}

void StudentsInaCourse(Student *studentCourse)
{
    Student *firstStu = studentCourse;
    while (firstStu != nullptr)
    {
        cout << "       The Students Admitted in Course are " << firstStu->studentName << endl;
        firstStu = firstStu->nextStud;
    }
}

int AvailableCourses(Course *head)
{
    int numberOfCourses = 0;
    while (head != nullptr)
    {
        cout << "The Available Courses are " << head->courseNo << endl;
        StudentsInaCourse(head->fisrtStudent);
        head = head->nextCourse;
        numberOfCourses++;
    }
    return numberOfCourses;
}

int main()
{
    int course;
    int option;
    int takenCourse;
    string studentName;
    int noOfCourses;
    int studentId = 1;
    bool takeOptionAgain = true;
    Course *head = nullptr;
    while (takeOptionAgain)
    {
        cout << "Choose The Option \n 1) Add Course \n 2) Add the Student want to Add in a course \n 3) Output the Courses \n 4) For Exit :\n";
        cin >> option;
        if (cin.fail())
        {
            cout << "Invalid Input type, please try again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Continue the loop to re-enter the option.
        }
        switch (option)
        {
        case 1:
            cout << "Enter the Course No \n";
            cin >> course;

            head = InsertNewCourse(head, course);

            break;
        case 2:
            noOfCourses = AvailableCourses(head);
            if (noOfCourses < 1)
            {
                cout << "No courses available, First Add the course \n";
            }
            else
            {
                cout << "Enter the Course No \n";
                cin >> takenCourse;
                cout << "Enter the Student Name : \t";
                cin >> studentName;
                bool stdAdded = InsertNewStudent(head, takenCourse, studentId, studentName);
                if (stdAdded)
                {
                    cout << "Student Added Successfully \n";
                    studentId++;
                }
                else
                {
                    cout << "The course is not available \n";
                }
            }
            break;
        case 3:
            noOfCourses = AvailableCourses(head);
            break;
        case 4:
            cout << "Thanks for using our LMS";
            takeOptionAgain = false;
            break;
        default:
            cout << "Invalid Option please Try Again \n";
            break;
        }
    }

    return 0;
}
