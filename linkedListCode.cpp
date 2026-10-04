//COMSC-210 | Lab 17 | Eric-Giulio Hedes
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void addNodeFront(Node *&, int);
void addNodeTail(Node *&, int);
void deleteNode(Node *&);
void insertNode(Node *&, int, int);
void deleteList(Node *);
void output(Node *);

int main() {
    //Random number seed generator
    srand(time(0));
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        // adds node at head
        addNodeFront(head, tmp_val);
    }
    output(head);

    // deleting a node
    deleteNode(head);
    output(head);

    // insert a node
    //insertNode(head);
    //output(head);

    // deleting the linked list
    //deleteList(head);
    /*
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;*/
    output(head);

    return 0;
}

void addNodeFront(Node *&head, int val)
{
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

void addNodeTail(Node *&tail, int val)
{
    Node *newVal = new Node;
    if (!tail) {
        tail = newVal;
        newVal->next = nullptr;
        newVal->value = val;
    }
    else {
        newVal->next = tail;
        newVal->value = val;
        tail = newVal;
    }
}

void deleteNode(Node *&n)
{
    cout << "Which node to delete? " << endl;
    output(n);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = n;
        n = n->next;
    }

    // at this point, delete current and reroute pointers
    if (n) {
        if (prev == nullptr) {
            // deleting the head node
            n = n->next;
        } else {
            prev->next = n->next;
        }
        delete n;
        n = nullptr;
    }
}

void output(Node *hd) {
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