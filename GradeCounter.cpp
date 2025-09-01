#include <iostream>
using namespace std;

int main()
{
    //variable for grades
    char grade;
    //variable for counting each grade 
    int countA = 0;
    int countB = 0;
    int countC = 0;
    int countD = 0;
    int countF = 0;
    
    //initializing program asking user for input
    cout << "Enter the letter grades (EOF to end): ";
    
    //loop to keep getting input from user
    while (true) {
        cin >> grade;
        
        //method to exit the program
        if (cin.eof()) {
            cout << "EOF detected. Terminating program." << endl;
            break;
        }
        
        switch (grade){
            case 'A':
            case 'a':
                countA++;
                break;
            case 'B':
            case 'b':
                countB++;
                break;
            case 'C':
            case 'c':
                countC++;
                break;
            case 'D':
            case 'd':
                countD++;
                break;
            case 'F':
            case 'f':
                countF++;
                break;
            case '\n':
            case '\t':
            case ' ':
                break;
            default:
                cout << "Invalid input. Enter A, B, C, D or F." << endl; //ensure the user enter valid input
                break;
        }
    }
    
    //print the final count/sum of grades
    cout << "Grade summary: " << "\nA: " << countA++ << "\nB: " << countB++ << "\nC: " << countC++ << "\nD: " << countD++ << "\nF: " << countF++ << endl;
}
