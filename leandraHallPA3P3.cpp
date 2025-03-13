/*
Leandra Hall 10/19/2022 SCIS-215-01

This program should open, read, and print out contents from a file specified in the Command Line by utilizing the variables
argc and argv. Additionally, the program evaluates whether or not the characters in a sentence from each line are legal or not
through the method isBalanced.

*/

//Include statements necessary to accomplish task
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Class declaration for Linked List Nodes
class CharNode {
    private:
        char elem;
        CharNode* next;

    friend class CharLinkedList;
};

//Friend class that has access to Linked List Nodes. Contains methods to manipulate Linked List
class CharLinkedList {
    public:
        CharLinkedList();
        ~CharLinkedList();
        bool empty() const;
        const char& front() const;
        void addFront(const char& character);
        void removeFront();
        void printList();
        void isBalanced(string sentence);
    private:
        CharNode* head;
};

//Linked list constructor that sets the head of the linked list to null
CharLinkedList::CharLinkedList()
: head(NULL) { }

//Linked list destructor that removes from the front of the linked list 
CharLinkedList::~CharLinkedList()
{ while (!empty()) removeFront();}

//Linked List Method #1: empty() - Evaluates if linked list is empty or not
bool CharLinkedList::empty() const
{ return head == NULL; }

//Linked List Method #2: front() - Returns the value at the head of the Linked List
const char& CharLinkedList::front() const
{ return head->elem; }

//Linked List Method #3: addFront(const char& character) - Adds elements to the front of the Linked List
void CharLinkedList::addFront(const char& character){
    CharNode* ch = new CharNode;
    ch->elem = character;
    ch->next = head;
    head = ch;
}

//Linked List Method #4: removeFront() - Removes elements from the front of the linked List
void CharLinkedList::removeFront(){
    CharNode* old = head;
    head = old ->next;
    delete old;
}

//Linked List Method #5: printList() - Prints each element in the Linked List 
void CharLinkedList::printList(){
    CharNode *Temp = head;
    cout << "The Linked List is:" << endl;
    while(Temp != NULL){
        cout << Temp -> elem << endl;
        Temp = Temp -> next;
    }
}

//Linked List Method #6: isBalanced(string sentence) - Evaluates whether or not the inputted string is legal
void CharLinkedList::isBalanced(string sentence){
    //For loop that iterates through each character in the inputted sentence
    for (int i = 0; i < (sentence.length()); i++){
        //Series of conditional statements 

        //Conditional Statement #1 - If character in sentence is '(' or '[', add character to front of Linked List
        if (sentence[i] == '(' || sentence[i] == '['){
            addFront(sentence[i]);
            /*Nested Conditional Statement #1 - If each character of the sentence has been iterated through and the list
            is not empty, "Error: Stack Not Empty" is printed */
            if (i == (sentence.length()-1) && empty() == false){
                cout << "Error: Stack Not Empty" << endl;
            }

        }

        /*Conditional Statement #2 - If the first character in sentence is ')' or ']' and the list is empty, 
        "Error: List Empty" is printed */
        else if((sentence[i] == ')' || sentence[i] == ']') && empty() == true){
            cout << "Error: List Empty" << endl;

        }

        /*Conditional Statement #3 - If the character in the sentence is ')' or ']' and has its corresponding opening character
        at the head of the linked list, remove the opening character from the list*/
        else if ((sentence[i] == ')' && head->elem == '(') || (sentence[i] == ']' && head->elem == '[')){
            removeFront();
            /*Nested Conditional #1 - If all the characters in the sentence have been iterated through and the linked list is 
            empty, then the sequence of characters anaylzed are legal so "Legal" is printed*/
            if ( i == (sentence.length()-1) && empty() == true){
                cout << "Legal" << endl;
            }
            /*Nested Conditional Statement #2 - If each character of the sentence has been iterated through and the list
            is not empty, "Error: Stack Not Empty" is printed */
            else if (i == (sentence.length()-1) && empty() == false){
                cout << "Error: Stack Not Empty" << endl;
            }
        }
        /*Conditional Statement #4 - If character in the sentence is ')' or ']' and the head of the linked list is not its
        corresponding opening character, then "Error: Symbols Do Not Match" is printed and the loop no longer iterates through
        sentence*/
        else if ((sentence[i] == ')' && head->elem == '[') || (sentence[i] == ']' && head->elem == '(')){
           cout << "Error: Symbols Do Not Match" << endl;
           break;

        }
    }

    /*Conditional Statement #5 - When the loop ends after iterating through the characters in the sentence, it removes any
    remaining the elements in the linked list before starting a new sentence evaluate */
    if (empty() == false){
        while(empty() == false){
            removeFront();
        }
    }
}

//Declaration of argc and argv for file input
int main(int argc, char** argv){

    //variable declarations necessary to open and read inputted file 
    CharLinkedList charList;
    string line;
    ifstream inFile;
    
    inFile.open(argv[1]);

    //if statement that runs if 2 arguments are properly provided
    if (argc == 2){
        cout << "You have entered " << argc << " arguments:" << "\n" << argv[0] << " and " << argv[1] << endl;
    
        cout << "The contents in your file are as follows: "<< endl;
        
        //while loop that iterates through the file line by line and prints out line
        while(getline(inFile, line)){
            cout << line << endl;
            //Method that evaluates each inputted line to determine whether it is legal or not
            charList.isBalanced(line);
        } 

        cout << "\n";
    }
    //closes inputted file
    inFile.close();

    return 0;
}
