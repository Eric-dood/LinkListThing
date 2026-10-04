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
            else cout << "Invalid choice; please pick a number between 1-6." << endl;
            cout << "Choice --> ";
            cin >> choice;
            cin.ignore(1000, 10);
            if (choice >= 1 && choice <= 6) break;
        }

        if (choice >= 1 && choice <= 2)
        {
            cout << "Select what value you want to add: " << endl;
            cin >> val;
            cin.ignore(1000, 10);
        }
        if (choice == 1) addNodeFront(head, val);
        if (choice == 2) addNodeTail(head, val);
        if (choice == 3) deleteNode(head);
        if (choice == 4) insertNode(head);
        if (choice == 5)
        {
            cout << endl << "Deleting the list..." << endl;
            deleteList(head);
        }
        if (choice == 6)
        {
            cout << endl << "Thanks for using this linked list program! Hope you had fun with it!" << endl;
            break;
        }

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
    if (!head) {
        head = newVal;
        newVal->next = nullptr;
        newVal->value = val;
    }
    else {
        newVal->next = head;
        newVal->value = val;
        head = newVal;
    }
}

//Define addNodeTail()
void addNodeTail(Node *&head, int val)
{
    Node *newVal = new Node;
    Node *current = head;

    if (!head) {
        head = newVal;
        newVal->next = nullptr;
        newVal->value = val;
    }
    else {
        while(current->next != nullptr)
            current = current->next;
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
    cout << "Which node to delete? " << endl;
    output(n);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = n;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            n = current->next;
        } else {
            prev->next = current->next;
        }
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
    //int count = 1;
    
    // traverse that many times and delete that node
    Node *current = n;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion
    output(current);

    cout << "Choice --> ";
    cin >> entry;

    current = n;
    prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = val;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        n = newnode;
    } else {
        prev->next = newnode;
    }
}

//Define deleteList()
void deleteList(Node *& n)
{
    Node *current = n;
    while (current) {
        n = current->next;
        delete current;
        current = n;
    }
    n = nullptr;
}

//define output()
void output(Node *hd)
{
    if (!hd) {
        cout << "Empty list.\n" << endl;
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}