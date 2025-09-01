#include <iostream> //input and output library

using namespace std; //shortcut for not needing std::

// Function prototypes
void merge(int arr[], int left, int mid, int right); //function to merge arrays
void sort(int arr[], int left, int right); //function for recursive sort 

int main() //main method 
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10}; //declare and initiliaze array 
    int arr_size = sizeof(arr) / sizeof(arr[0]); //calculate the number of elements in the array 

    cout << "Given array is \n"; //display/print the original array 
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " "; //print each element 
    }
    cout << endl; //end line or flush buffer

    sort(arr, 0, arr_size - 1); //call the merge sort function

    cout << "\nSorted array is \n"; //display/print sorted array 
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " "; //print each element 
    }
    cout << endl; //end line or flush buffer 

    return 0; //end the program
}

void merge(int arr[], int left, int mid, int right) //function to merge arrays
{
    int n1 = mid - left + 1; //size of the left array
    int n2 = right - mid; //size of the right array 

    int* Left = new int[n1]; //temporary array for the left half
    int* Right = new int[n2]; //temporary array for the right half 
    
    //copy info into the temporary array 
    for (int i = 0; i < n1; i++) { //loop while i is less than n1 (size of left array)
        Left[i] = arr[left + i]; //fill left array with elements from arr 
    }
    for (int j = 0; j < n2; j++) { //loop while j is less than n2 (size of right array)
        Right[j] = arr[mid + 1 + j]; //fill right array with elements from arr 
    }

    int i = 0, j = 0; //indexes for left and right 
    int k = left; //index for merged array 
    
    //merge the temporary arrays 
    while (i < n1 && j < n2) { //loop while arrays left and right still have elements
        if (Left[i] <= Right[j]) { //if current left element is smaller or equal
            arr[k++] = Left[i++]; //copy the smaller element and increment
        } else {
            arr[k++] = Right[j++]; //copy the smaller element and increment
        }
    }
    
    //copy remaining elements of left array
    while (i < n1) {
        arr[k++] = Left[i++]; //copy and move to the next left element 
    }
    //copy remaining elements of right array
    while (j < n2) {
        arr[k++] = Right[j++]; //copy and move to the next right element 
    }

    delete[] Left; //free memory
    delete[] Right; //free memory
}

void sort(int arr[], int left, int right) //function for recursive sort 
{
    if (left < right) { //base case
        int mid = left + (right - left) / 2; //find middle point

        sort(arr, left, mid); //sort the left half
        sort(arr, mid + 1, right); //sort the right half

        merge(arr, left, mid, right); //merge the halves
    }
}

//Sources: Below, include what sources you used to comment on this code
//Source 1: https://codesignal.com/learn/courses/sorting-and-searching-algorithms-in-cpp/lessons/exploring-merge-sort-in-cpp
//Source 2: programs we wrote in class
//Source 3: programs/comments I did in Java's class (we were actually studying the same stuff at the same time in C++ and Java for the last couple weeks)
