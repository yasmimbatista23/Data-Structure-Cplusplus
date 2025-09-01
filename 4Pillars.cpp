#include <iostream>
using namespace std;

//abstract class 
class AbstractPerson {
    virtual void getRole() = 0;
};

//parent class inheriting asbtract class 
class Person : public AbstractPerson {
protected:
    string Name;
    int Age;
    
public:
    //constructor
    Person (string name, int age){
        Name = name;
        Age = age;
    }
    //setters and getters
    void setName(string name){
        Name = name;
    }
    
    string getName (){
        return Name;
    }
    
    void setAge (int age){
        Age = age;
    }
    
    int getAge() {
        return Age;
    }
};

//child class inheriting Person class 
class Student : public Person {
private:
    int Grade;

public:
    //constructor
    Student (string name, int age, int grade) : Person (name, age) {
        Grade = grade; //I did not see why would need setters and getters for this one, I tried but didnt work
    }
    void displayInfoStudent(){
        cout << Name << " is a Student, Age: " << Age << ", Grade Level: " << Grade << endl;
    }
    
    //overriden method from abstract class for students 
    void getRole() override {
        cout << "Enter student details: " << Name << ", " << Age << ", Grade " << Grade << endl;
    }
};

//child class inheriting Person class 
class Teacher : public Person {
private:
    string Subject;

public:
    //constructor
    Teacher (string name, int age, string subject) : Person (name, age) {
        Subject = subject; //I did not see why we would need setters and getters here either
    }

    void displayInfoTeacher(){
        cout << Name << " is a Teacher, Age: " << Age << ", Subject: " << Subject << endl;
    }
    
    //overriden method from abstract class for teachers
    void getRole() override{
        cout << "Enter teacher details: " << Name << ", " << Age << ", " << Subject << endl;
    }
};

int main()
{
    Student student1("John", 16, 10); //object to input the info 
    student1.getRole(); //call method
    Teacher teacher1("Mrs. Smith", 40, "Mathematics");
    teacher1.getRole();
    
    cout << "\nSchool members: " << endl;
    
    //I am not sure if this block is right but it works lol 
    Student *s1 = &student1;
    s1 -> displayInfoStudent();
    Teacher *t1 = &teacher1;
    t1 -> displayInfoTeacher();
}
