#include <iostream>
#include <string>
using namespace std;

//I WILL JUST LEAVE IT OPEN AND HOPE I WILL BE ABLE TO SAVE IT OR SUBMIT IT LATER WITHOUT HAVING TO TYPE EVERYTHING AGAIN 

//Structs
struct Student{
    int id;
    string name;
    float gpa;
};

struct Node{
    Student data;
    Node* next;
};

//Function Prototypes (samples included, you may change naming structures)
void addStudent(Node*& head, int id, const string& name, float gpa);
bool removeStudent(Node*& head, int id);
Student* searchStudent(Node* head, int id);
void printStudents(Node* head);
void freeList(Node*& head);
void printMenu();        
Student getStudentInput();

int main() {
    Node* head = nullptr;
    bool running = true;
    int choice, id;
    
    while(running){ //loop keeps running until the user choose to exit 
        printMenu();
        cin >> choice;
        
        switch (choice){
            //add a new student by getting user input and calling addStudent
            case 1: { 
                Student newStudent = getStudentInput();
                addStudent(head, newStudent.id, newStudent.name, newStudent.gpa);
                break;
            }
            //remove student by id 
            case 2:
                cout << "\nEnter ID to remove: ";
                cin >> id;
                if(removeStudent(head, id)){
                    cout << "Student removed successfully!\n" << endl;
                } else {
                    cout << "Student not found.\n" << endl;
                }
                break;
            //search for student by id 
            case 3:
                cout << "\nEnter ID to search: ";
                cin >> id;
                if (Student* found = searchStudent(head, id)){
                    cout << "\nFound: " << found -> name << ", GPA: " << found -> gpa << endl;
                } else {
                    cout << "Student not found.\n" << endl;
                }
                break;
            //print all students 
            case 4:
                printStudents(head);
                break;
            //exit the program 
            case 0: 
                running = false;
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Try again.\n" << endl;
        }
    }
    freeList(head); // clean up memory
}

//add a student to the linked list 
void addStudent(Node*& head, int id, const string& name, float gpa){
    Node* newNode = new Node{{id, name, gpa}, nullptr};
    
    if(!head){
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while(temp->next){
        temp = temp -> next;
    }
    
    temp -> next = newNode;
}

//remove a student by id 
bool removeStudent(Node*& head, int id){
    Node* current = head;
    Node* previous = nullptr;
    
    while(current){
        if (current -> data.id == id){
            if (previous){
                previous -> next = current -> next;
            } else {
                head = current -> next;
            }
            delete current;
            return true;
        }
        previous = current;
        current = current -> next;
    }
    
    return false;
}

//search for student by id 
Student* searchStudent(Node* head, int id){
    while (head != nullptr){
        if(head -> data.id == id){
            return &(head -> data);
        }
            head = head -> next;
    }
    return nullptr;
}

//print all students 
void printStudents(Node* head){
    if (!head){
        cout << "No students found.\n" << endl;
        return;
    }
    
    while (head){
        cout << "\nID: " << head -> data.id << ", Name: " << head -> data.name << ", GPA: " << head -> data.gpa << endl;
        head = head -> next;
    }
}

//free all nodes in the list to prevent memory leak
void freeList(Node*& head){
    Node* temp;
    while (head){
        temp = head;
        head = head -> next;
        delete temp;
    }
}

//print menu 
void printMenu(){
    cout << "\nStudent Record Manager\n";
    cout << "1. Add Student\n";
    cout << "2. Remove Student\n";
    cout << "3. Search Student\n";
    cout << "4. Print All Students\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

//get student info from user
Student getStudentInput(){
    Student s;
    
    cout << "\nEnter ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, s.name);
    cout << "Enter GPA: ";
    cin >> s.gpa;
    return s;
}
