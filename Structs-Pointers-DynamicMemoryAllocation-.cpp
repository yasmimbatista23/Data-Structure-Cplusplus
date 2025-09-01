#include <iostream>
using namespace std;

//struct 
struct employee {
    string name;
    int id;
    float salary;
};

//function prototypes
employee* employeeArray(int numEmployees);
void displayEmployeeInfo(employee* arr, int numEmployees);

int main()
{
    int numEmployees;
    
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    
    employee *arr = employeeArray(numEmployees); //allocate memory on the heap
    
    //loop for input details on each employee 
    for (int i = 0; i < numEmployees; i++){
        cout << "\nEnter details for Employee " << i+1 << ": ";
        cout << "\nID: ";
        cin >> arr[i].id;
        cin.ignore(); //clear buffer 
        cout << "Name: ";
        getline(cin, arr[i].name);
        cout << "Salary: ";
        cin >> arr[i].salary;
    }
    
    displayEmployeeInfo(arr, numEmployees); //call function to display employee details 
    
    delete[] arr; //free memory
}

//functions defintions
employee* employeeArray(int numEmployees) //function to allocate memory for employee array 
{
    return new employee[numEmployees];
}


void displayEmployeeInfo(employee* arr, int numEmployees) //function to display employees infos 
{
    cout << "\nEmployee Details: " << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < numEmployees; i++){
        cout << "Employee " << i + 1 << ": \n";
        cout << "ID: " << arr[i].id << endl;
        cout << "Name: " << arr[i].name << endl;
        cout << "Salary: $" << arr[i].salary << endl;
        cout << "------------------------" << endl;
    }
}




