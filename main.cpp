/*
COMSC-210 | Lab 17 | Rylan Der
IDE Used: Visual Studio Code
*/

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);

void deleteNode(Node * head, int entry);

void insertNode(Node * head, int entry, int value);

void deleteList(Node * head);

int main() {
    Node *head = nullptr;
    Node *current = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry);
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000);
    output(head);

    deleteList(head);
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void deleteNode(Node * head, int entry) {
    Node * current = head;
    Node * prev = head;

    // traverse entry many times and delete that node
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }

}

void insertNode(Node * head, int entry, int value) {
    Node * current = head;
    Node * prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = value;
    newnode->next = current;
    prev->next = newnode;
}

void deleteList(Node * head) {
    Node * current = head;
    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}