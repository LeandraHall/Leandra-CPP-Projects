/*
Leandra Hall 10/19/2022 SCIS-215-01

This program should open, read, and print out contents from a file specified in the Command Line by utilizing the variables
argc and argv. Additionally, the program adds each character from the file into a linked list, prints out the list's contents,
and removes each character from the linked list using methods such as addFront, removeFront, and printList

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

//Linked List Method #3: addFront - Adds elements to the front of the Linked List
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

//Linked List Method #1: printList() - Prints each element in the Linked List 
void CharLinkedList::printList(){
    CharNode *Temp = head;
    cout << "The Linked List is:" << endl;
    while(Temp != NULL){
        cout << Temp -> elem << endl;
        Temp = Temp -> next;
    }
}

void CharLinkedList::isBalanced(string sentence){
    cout << "sentence length " << sentence.length() << endl;
    for (int i = 0; i < sentence.length(); i++){
        cout << i << endl;
        if (sentence[i] == '(' || sentence[i] == '['){
            cout << "Test1" << endl;
            CharNode* ch = new CharNode;
            ch->elem = sentence[i];
            ch->next = head;
            head = ch;
        }
        if((sentence[i] == ')' || sentence[i] == ']') && head->elem == '\0'){
            cout << "Test2" << endl;
            cout << "Error: List Empty" << endl;
        }
        if ((sentence[i] == ')' && head->elem == '(') || (sentence[i] == ']' && head->elem == '[')){
            cout << "Test3" << endl;
            CharNode* old = head;
            head = old ->next;
            delete old;
        }
        if ((sentence[i] == ')' && head->elem == '[') || (sentence[i] == ']' && head->elem == '(')){
            cout << "Test4" << endl;
           cout << "Error: Symbols Do Not Match" << endl;
        }
        if(i == sentence.length() && !(head->elem == '\0')){
            cout << "Test5" << endl;
            cout << "Error: Stack Not Empty" << endl;
        }
        if(i == sentence.length() && head->elem == '\0'){
            cout << "Test6" << endl;
            cout << "Legal" << endl;
        }

    }
}

//Declaration of argc and argv for file input
int main(int argc, char** argv){

    //variable declarations necessary to open and read inputted file 
    CharLinkedList charList;
    CharLinkedList charListTest;
    string line;
    ifstream inFile;
    
    inFile.open(argv[1]);

    //if statement that runs if 2 arguments are properly provided
    if (argc == 2){
        cout << "You have entered " << argc << " arguments:" << "\n" << argv[0] << " and " << argv[1] << endl;
    
        cout << "The contents in your file are as follows: "<< endl;
        
        //while loop that iterates through the file line by line and prints out line
        while(getline(inFile, line)){
            cout << line << "\n";
            //for loop that iterates through each character in the line and adds them to the Linked List
            for (int i = 0; i < line.length(); i++){
                charList.addFront(line[i]);
                cout << "This loop works" << endl;
            }
        } 

        cout << "\n";

        //Prints out contents in Linked List
        charList.printList();

        cout << "\n";

        //While loop that iterates through linked list, removes element from the front, and prints out updated linked list
        while(charList.empty() != true){
            charList.removeFront();
            charList.printList();
            cout << "\n";
        }

    }

    //closes inputted file
    inFile.close();

    return 0;
}