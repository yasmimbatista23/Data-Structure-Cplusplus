#include <iostream>

using namespace std;

int main()
{
    //variables
    int budget, rent, groceries, entertainment, sum;
    //initializing variable budget
    budget = 1000;
    
    cout << "Welcome to the Monthly Expense Tracker!" <<endl;
    
    //prompt user for rent 
    cout << "\nEnter your rent expense: " << endl;
    cin >> rent;
    
    //prompt user for groceries
    cout << "Enter your groceries expense: " << endl;
    cin >> groceries;
    
    //prompt user for entertainment
    cout << "Enter your entertainment expense: " <<endl;
    cin >> entertainment;
    
    //math to find out how much was spent 
    sum = budget - rent - groceries - entertainment;
    
    //method to show the right message to user 
    if (sum > 0){
        cout << "\nYou have $" << sum << " dollars left.";
    } else if (sum == 0) {
        cout << "\nYou've used up your budget!";
    } else { 
        //I dont know how to make the negative sign don't show up here
        cout << "\nOops! You overspent by $" << sum;
    }
    
    
}