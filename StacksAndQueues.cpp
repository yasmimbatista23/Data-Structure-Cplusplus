#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;


int main() {
    stack<string> undoStack;  // Stores words typed
    stack<string> redoStack;  // Stores words that were undone
    string word;
    
    cout << "Start typing your story one word at a time." << endl;
    cout << "Type 'xUndo' to undo the last word, 'xRedo' to redo it, and 'xQuit' to finish." << endl;
    
    while (true){
        cout << ">";
        cin >> word;
        
        if(word == "xUndo"){ //undo/remove the last word 
            if (!undoStack.empty()){
                redoStack.push(undoStack.top());
                undoStack.pop();
                cout << "[Undo] Last word removed." << endl;
            } else {
                cout << "[Undo] Nothing to undo." << endl;
            } 
        } else if (word == "xRedo"){ // redo the last removed word 
                if (!redoStack.empty()){
                    undoStack.push(redoStack.top());
                    redoStack.pop();
                    cout << "[Redo] Last undone word re-added." << endl;
                } else {
                    cout << "[Redo] Nothing to redo." << endl;
                }
        } else if (word == "xQuit"){ //exit the loop
            break;
        } else {
            undoStack.push(word);
            //clear stack 
            while (!redoStack.empty()){
                redoStack.pop(); 
            }
        }
    }
    
    stack<string> tempStack; //temp stack to reverse undoStack
    queue<string> storyQueue; 
    
    while (!undoStack.empty()){ //move word from undoStack to tempStack to change order 
        tempStack.push(undoStack.top());
        undoStack.pop();
    }
    
    while (!tempStack.empty()){ // move words from tempStack to storyQueue to put in order 
        storyQueue.push(tempStack.top());
        tempStack.pop();
    }
    //print final story on the same line 
    cout << "Your final story: ";
    while (!storyQueue.empty()){
        cout << storyQueue.front();
        storyQueue.pop();
        if (!storyQueue.empty()){
            cout << " ";
        }
    }
    cout << endl;
}










