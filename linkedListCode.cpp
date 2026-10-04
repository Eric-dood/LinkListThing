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

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        addNodeFront(head, tmp_val); //Adds a node to the front
    }
    output(head);

    // deleting a node
    deleteNode(head);
    output(head);

    // insert a node
    insertNode(head);
    output(head);

    // deleting the linked list
    cout << endl << "Deleting the list..." << endl;
    deleteList(head);
    output(head);

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
void addNodeTail(Node *&tail, int val)
{
    Node *newVal = new Node;
    Node *current = tail;

    if (!tail) {
        tail = newVal;
        newVal->next = nullptr;
        newVal->value = val;
    }
    else {
        while(current->next != nullptr)
            current = current->next;
        if (current)
        {
            current->next = newVal;
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
        cout << "Empty list.\n";
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