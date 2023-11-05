#include <iostream>
using namespace std;
// class 
class Student
{
public:
    int age;
    int id;
    int totalStudents(int);
    Student()
    {
        age = 15;
        id = 0000;
    }
};
// defining a Student class method outside of class
int Student::totalStudents(int no)
{
    return no;
}
int main()
{   
    // making an array using dynamic memory management ie new or malloc
    int size;
    cout << "Enter total students: ";
    cin >> size;
    int *ptr;
    ptr = new int[size];
    //taking inputs for array values using pointer 
    for (int i = 0; i < size; i++)
    {
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> *(ptr + i);
    }
    //printing array values using pointer
    for (int i = 0; i < size; i++)
    {
        cout << "Marks of student " << i + 1 << ": ";
        cout << *(ptr + i) << endl;
    }
    // delete memory allocated to array
    delete[] ptr;
    cout << *(ptr + 1);
    //making a simple object of class student
    Student s1;
    cout << s1.age << endl;
    cout << s1.id << endl;
    cout << s1.totalStudents(2234) << endl;
    //making an object using pointer
    Student *s2 = new Student();
    cout << s2->age << endl;
    cout << s2->id << endl;
    cout << s2->totalStudents(2235) << endl;
    // making an array of student objects in simple way
    Student arrOfStud[5];
    cout << arrOfStud[0].age << endl;
    // making an array of student objects with pointer
    Student *listOfall = new Student[5];
    cout << "pointer array printer" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << (listOfall + i)->age << endl;
    }
    return 0;
}