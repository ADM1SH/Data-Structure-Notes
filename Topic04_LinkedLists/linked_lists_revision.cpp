#include <iostream>
using namespace std;

/* 
   TOPIC 4: LINKED LISTS
   ---------------------
   A linked list is a collection of nodes where each node points to the next.
   Unlike arrays, they are not contiguous in memory.
*/

struct node {
    int data;
    node* next;
};

// --- EXAM SNIPPET: TOTALING EVEN NUMBERS (Feb 2025 Q2ii) ---
void sumEvenNumbers(node* head) {
    node* temp = head;
    int sum = 0;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            sum += temp->data;
        }
        temp = temp->next;
    }
    cout << "Sum of even numbers: " << sum << endl;
}

// --- EXAM SNIPPET: SWAP FIRST AND LAST DATA (Feb 2025 Q2iii) ---
// Note: This swaps the VALUES, not the nodes themselves.
void swapFirstLast(node* head) {
    if (head == NULL || head->next == NULL) return;

    node* temp = head;
    // 1. Find the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // 2. Swap data
    int val = head->data;
    head->data = temp->data;
    temp->data = val;
}

// --- EXAM SNIPPET: INSERTING IN MIDDLE (July 2025 Q2ci) ---
// "Add new node with data 15 between nodes with data 10 and 20"
void insertBetween(node* head) {
    node* temp = head;
    // Find node with data 10
    while (temp != NULL && temp->data != 10) {
        temp = temp->next;
    }
    
    if (temp != NULL) {
        node* newNode = new node;
        newNode->data = 15;
        newNode->next = temp->next; // link new node to 20
        temp->next = newNode;       // link 10 to new node
    }
}

// --- EXAM SNIPPET: DELETING A SPECIFIC NODE (July 2025 Q2cii) ---
// "Delete node with data 10"
void deleteNode10(node* &head) {
    if (head == NULL) return;
    
    // If head is 10
    if (head->data == 10) {
        node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    
    node* temp = head;
    while (temp->next != NULL && temp->next->data != 10) {
        temp = temp->next;
    }
    
    if (temp->next != NULL) {
        node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

// --- ARRAY IMPLEMENTATION OF LINKED LIST (July 2025 Q2a) ---
/*
   Sometimes exams ask about representing a list in an array table.
   Index | Data | Link
   0     | 23   | 2
   1     | 45   | 3
   2     | 12   | 99 (End)
   3     | 65   | 1
   Logic: Head(0) -> 23 -> Link(2) -> 12 -> Link(99)
   Wait, sorting logic: 23, 65, 45, 12
   Head(0) -> 23 -> Link(3) -> 65 -> Link(1) -> 45 -> Link(2) -> 12 -> Link(99)
*/

int main() {
    // Setup a small list: 10 -> 20 -> 30
    node* head = new node{10, new node{20, new node{30, NULL}}};
    
    cout << "Original List: 10 20 30" << endl;
    sumEvenNumbers(head);
    
    insertBetween(head);
    cout << "After inserting 15 between 10 and 20..." << endl;
    
    swapFirstLast(head);
    cout << "After swapping first and last data..." << endl;

    return 0;
}
