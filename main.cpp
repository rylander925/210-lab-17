/*
COMSC-210 | Lab 17 | Rylan Der
IDE Used: Visual Studio Code
*/

#include <iostream>
using namespace std;

const int SIZE = 7; 
const int STREAM_IGNORE_CHARS = 100; 

struct Node {
    float value;
    Node* next;
};

void output(Node* );

void deleteNode(Node* &head, int entry);

void insertNode(Node* &head, int entry, int value);

void deleteList(Node* &head);

void push_front(Node* &head, int value);

void fillList(Node* &head, int size, int min = 0, int max = 99);

int main() {
    Node* head = nullptr;
    Node* current = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    fillList(head, SIZE, 0, 99);
    output(head);

    // deleting a node
    int entry = 1;
    do {
        cout << "Which node to delete? " << endl;
        output(head);
        cout << "Choice --> ";
        cin >> entry;
        cout << endl;
        //Validate for valid integer
        if (cin.fail()) {
            cout << "Enter an integer" << endl;
            cin.clear();
            cin.ignore();
        }
        //Only ensure for greater than 0. 
        //Since size is not updated with the list, does not attempt to check for a max range
        //Instead, delete function will delete the last element if greater
        if (entry < 1) {
            cout << "Node must be greater than 1" << endl;
        }
    } while (entry < 1);
    
    deleteNode(head, entry);
    output(head);

    // insert a node
    do {
        current = head;
        cout << "After which node to insert 10000? " << endl;
        count = 1;
        while (current) {
            cout << "[" << count++ << "] " << current->value << endl;
            current = current->next;
        }
        cout << "Choice --> ";
        cin >> entry;
        cout << endl;
        //Validate for a valid integer
        if (cin.fail()) {
            cout << "Enter an integer" << endl;
            cin.clear();
            cin.ignore();
        }
        //Only ensure greater than 0. 
        //Since size is not updated with the list, does not attempt to check for a max range
        //Instead, insert function will insert after last element if greater
        if (entry < 1) {
            cout << "Node must be greater than 1" << endl;
        }
    } while (entry < 1);
    insertNode(head, entry, 10000);
    output(head);

    // delete list
    deleteList(head);
    output(head);

    return 0;
}

/**
 * Output contents of linked list
 * @param hd Head node of the linked list
 */
void output(Node* hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node* current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

/**
 * Deletes a given node from a linked list
 * @param head Head node of the linked list
 * @param entry The number of the node to delete
 */
void deleteNode(Node* &head, int entry) {
    Node* current = head;
    Node* prev = head;

    // traverse [entry] many times and delete that node
    // stop at current->next to prevent seg. faults and properly delete last element
    // if an invalid entry is given 
    for (int i = 0; i < (entry-1) && current->next; i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current == head) {
        head = current->next;
        delete current;
        current = nullptr;
    } else if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }

}

/**
 * Inserts a node after a specified position in a linked list
 * If specified position is greater than the number of elements, inserts node before the last node
 * @param head Head node of the linked list
 * @param entry Number of the node to insert at
 * @param value Value assigned to the new node
 */
void insertNode(Node* &head, int entry, int value) {
    Node* current = head;
    Node* prev = head;
    //Stops when current is a nullptr to prevent invalid range access
    for (int i = 0; i < (entry) && current; i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node* newnode = new Node;
    newnode->value = value;
    newnode->next = current;
    prev->next = newnode;
}

/**
 * Deletes all the nodes of a linked list
 * @param head Head node of the linked list to delete
 */
void deleteList(Node* &head) {
    Node* current = head;
    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}

/**
 * Prepends a node to a linked list
 * @param head Head node of the linked list
 * @param value Value assigned to the new node
 */
void push_front(Node* &head, int value) {
    Node* newVal = new Node;
    // adds node at head
    if (!head) { // if this is the first node, it's the new head
        head = newVal;
        newVal->next = nullptr;
        newVal->value = value;
    }
    else { // its a second or subsequent node; place at the head
        newVal->next = head;
        newVal->value = value;
        head = newVal;
    }
}

/**
 * Fills a linked list with random integers
 * @param head Head node of the linked list to fill
 * @param size Number of nodes to add
 * @param min Minimum range of integer values
 * @param max Maximum range of integer values
 */
void fillList(Node* &head, int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        push_front(head, min + rand() % (max + 1));
    }
}