#include <iostream>
using namespace std;

//function prototypes
int linearSearch(const int arr[], int size, int key, int &checks);
int binarySearch(const int arr[], int size, int key, int &checks);


int main()
{
    const int SIZE = 100;
    int key;
    int choice;
    int checks = 0;
    
    // Predefined sorted array of 100 integers between 1 and 1000
    int arr[SIZE] = {
         1,  12,  25,  32,  43,  55,  61,  79,  84,  95,
       104, 113, 122, 131, 146, 157, 168, 175, 180, 191,
       201, 214, 221, 231, 241, 251, 266, 271, 281, 291,
       305, 313, 321, 335, 341, 351, 361, 371, 381, 391,
       404, 413, 421, 431, 441, 453, 461, 476, 484, 491,
       503, 516, 521, 531, 547, 551, 561, 571, 581, 591,
       607, 616, 621, 631, 641, 658, 661, 671, 681, 697,
       708, 711, 721, 731, 741, 751, 769, 771, 781, 791,
       808, 815, 821, 834, 841, 851, 861, 878, 881, 891,
       900, 919, 921, 931, 941, 955, 961, 976, 985, 998
    };
    
    //user input 
    cout << "Enter the key value to search for: ";
    cin >> key;
    
    cout << "\nChoose the search algorithm:" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    
    int index = -1; //we have to initialize index at -1 because 0 is a valid index 
    
    if (choice == 1){ //if user choose linear search this will run 
        index = linearSearch(arr, SIZE, key, checks);
        if (index != -1) {
            cout << "\nLinear Search: Key found at index " << index << " after " << checks << " iterations." << endl;
        } else {
            cout << "\nLinear Search: Key not found after " << checks << " iterations" << endl;
        }
    } else if (choice == 2) { //if user choose binary search this will run  
        index = binarySearch(arr, SIZE, key, checks);
        if (index != -1){
            cout << "\nBinary Search: Key found at index " << index << " after " << checks << " iterations." << endl;
        } else {
            cout << "\nBinary Search: Key not found after " << checks << " iterations." << endl;
        }
    } else { //make sure the input is valid 
        cout << "Invalid choice! Please restart thr program and enter 1 or 2." << endl;
    }
}

int linearSearch(const int arr[], int size, int key, int &checks) {
    for (int i = 0; i < size; i++){ //this will check through the array and count each check/iteration 
        checks++;
        if (arr[i] == key){
            return i;
        }
    }
    return -1; //key not found 
}

int binarySearch(const int arr[], int size, int key, int &checks){
    int low = 0;
    int high = size - 1;
    
    while (low <= high){
        checks++;
        int mid = low + (high - low) / 2; //find the middle
        
        if (arr[mid] == key) {
            return mid; //if we find it at mid index
        } else if (arr[mid] < key){
            low = mid + 1; //search in the right half 
        } else {
            high = mid - 1; //search in the left half
        }
    }
    return -1; //key not found 
}


