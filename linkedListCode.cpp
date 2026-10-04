//COMSC-210 | Lab 17 | Eric-Giulio Hedes
#include <iostream>
using namespace std;

//Declare the global SIZE constant
const int SIZE = 7;  

//Initialize the node
struct Node {
    float value;
    Node *next;
};

//Function prototypes
void addNodeFront(Node *&, int);
void addNodeTail(Node *&, int);
void deleteNode(Node *&);
void insertNode(Node *&);
void deleteList(Node *&);
void output(Node *);

//Start of main()
int main() {
    //Random number seed generator
    srand(time(0));
    Node *head = nullptr;

    //Create a linked list that includes random numbers, with its length being based on SIZE
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        addNodeFront(head, tmp_val); //Adds a node to the front
    }
    //Also output it
    output(head);

    //Start the choice loop
    int choice = 1, val;
    //Use a while(true) loop to 
    while(true)
    {
        while(true)
        {
            //Ask the user to enter a number
            //Each number represents a function, with the last one being the exit option
            if (choice >= 1 && choice <= 6)
            {
                cout << "Select your function: " << endl;
                cout << "[1] Add node to the head" << endl;
                cout << "[2] Add node to the tail" << endl;
                cout << "[3] Delete a node" << endl;
                cout << "[4] Insert a node" << endl;
                cout << "[5] Delete the entire list" << endl;
                cout << "[6] Exit" << endl;
            }
            //If the choice is not between 1-6, output an error message
            else cout << "Invalid choice; please pick a number between 1-6." << endl;
            cout << "Choice --> ";
            cin >> choice; //Enter the choice
            cin.ignore(1000, 10);
            //If the choice is between 1-6, break out of the first loop
            if (choice >= 1 && choice <= 6) break;
        }

        //A combination of 1) Add node to head & 2) Add node to tail
        if (choice >= 1 && choice <= 2) //This message applies to both functions
        {
            cout << "Select what value you want to add: " << endl;
            cin >> val;
            cin.ignore(1000, 10);
        }
        if (choice == 1) addNodeFront(head, val); //1) Add node to head
        if (choice == 2) addNodeTail(head, val); //2) Add node to tail
        if (choice == 3) deleteNode(head); //3) Delete node
        if (choice == 4) insertNode(head); //4) Insert node
        if (choice == 5) //5) Delete the list
        {
            cout << endl << "Deleting the list..." << endl;
            deleteList(head);
        }
        if (choice == 6) //6) Exit the program
        {
            cout << endl << "Thanks for using this linked list program! Hope you had fun with it!" << endl;
            break;
        }

        //Output the linked list
        output(head);
    }

    return 0;
}
//End of main()

//Define addNodeFront()
void addNodeFront(Node *&head, int val)
{
    //Create a newVal node
    Node *newVal = new Node;
    //If head isn't defined, automatically set the value as its head & tail
    if (!head) {
        head = newVal;
        newVal->next = nullptr;
        newVal->value = val;
    }
    //Otherwise add the new node and set it as the head
    else {
        newVal->next = head;
        newVal->value = val;
        head = newVal;
    }
}

//Define addNodeTail()
void addNodeTail(Node *&head, int val)
{
    //Create a newVal node & a current node (which copies the parameter head)
    Node *newVal = new Node;
    Node *current = head;
    //If head isn't defined, automatically set the value as its head & tail
    if (!head) {
        head = newVal;
        newVal->next = nullptr;
        newVal->value = val;
    }
    //Otherwise add the new node and set it as its tail
    else {
        //Search for the last element that doesn't have a nullptr
        while(current->next != nullptr)
            current = current->next;
        //If the last element exists, set the new node to that spot
        if (current)
        {
            current->next = newVal;
            newVal->next = nullptr;
            newVal->value = val;
        }
    }
}

//Define deleteNode()
void deleteNode(Node *&n)
{
    //Ask the user which node to delete
    cout << "Which node to delete? " << endl;
    output(n); //Also output the list
    int entry, size = 1;
    cout << "Choice --> ";
    cin >> entry;

    //Traverse this many times in order to delete the node
    Node *current = n;
    Node *prev = nullptr;  //In order to detect head, prev must be set to nullptr

    //Initiate a loop where prev and current are being scanned to find the selected value 
    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    //At this point, delete the selected node.
    if (current) {
        if (prev == nullptr) {
            //Deleting the selected node
            n = current->next;
        } else {
            prev->next = current->next;
        }
        //To ensure safety, call 'delete'
        delete current;
        current = nullptr;
    }
}

//Define insertNode()
void insertNode(Node *&n)
{
    int val, entry;
    cout << "What do you want to insert? " << endl;
    cin >> val;
    cin.ignore(1000, 10);

    cout << endl << "After which node to insert " << val << "? " << endl;
    //Traverse this many times in order to delete the node
    Node *current = n;
    Node *prev = nullptr;  //In order to detect head, prev must be set to nullptr
    //Print the entire list
    output(current);

    cout << "Choice --> ";
    cin >> entry;

    //Initiate a loop where prev and current are being scanned to find the selected value 
    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    //At this point, insert the selected node.
    Node *newnode = new Node;
    newnode->value = val;
    newnode->next = current;

    if (prev == nullptr) {
        //Inserting before the head node
        n = newnode;
    } else {
        prev->next = newnode;
    }
}

//Define deleteList()
void deleteList(Node *& n)
{
    //Use a current list
    Node *current = n;
    //Do a while() loop to scan and delete all elements
    while (current) {
        n = current->next;
        delete current;
        current = n;
    }
    //Set the empty list to nullptr
    n = nullptr;
}

//define output()
void output(Node *hd)
{
    //If there are no elements in the list, print "Empty list."
    if (!hd) {
        cout << "Empty list.\n" << endl;
        return;
    }
    //Otherwise print as intended
    int count = 1;
    Node *current = hd;
    //Do a while() loop to print all elements
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}