#include <iostream>
#include <string>
#include <algorithm> //need this to use the reverse method
using namespace std;

const std::string colors[] = { //code for colors 
    "\033[31m", //red 
    "\033[33m", //yellow
    "\033[32m", //green
    "\033[36m", //cyan
    "\033[34m", //blue
    "\033[35m" //magenta
};

const int colorCount = sizeof(colors) / sizeof(colors[0]); //lost this class so Im not sure why this!!

int main() {
    string userMessage, reversed, reversedCase; //strings variable
    
    cout << "Please enter a string: ";
    getline(cin, userMessage); //get user input for strings
    
    reversed = userMessage; //reassigning the userMessage
    reverse(reversed.begin(), reversed.end()); //reverse the message 
    
    reversedCase = userMessage; //reassigning the userMessage
    for (size_t i=0; i < reversedCase.size(); i++) { //method to convert the string to upper and lower case 
        if (islower(reversedCase[i])) {
            reversedCase[i] = toupper(reversedCase[i]);
        } else if (isupper(reversedCase[i])) {
            reversedCase[i] = tolower(reversedCase[i]);
        }
    }
    
    //print the results using colors
    cout << "\nThe reverse of your string is: \033[31m\n" << reversed << "\033[0m" << endl;
    cout << "\nYour string with reversed cases: \033[36m\n" << reversedCase << "\033[0m"<< endl;
    
}
