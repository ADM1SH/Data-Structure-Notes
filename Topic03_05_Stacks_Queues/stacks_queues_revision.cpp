#include <iostream>
using namespace std;

/* 
   TOPIC 3 & 5: STACKS & QUEUES
   ---------------------------
   Stack: LIFO (Last In First Out) - push, pop
   Queue: FIFO (First In First Out) - append/enqueue, serve/dequeue
*/

// --- 1. ARRAY STACK (Exam Style) ---
class ArrayStack {
private:
    char stack[5];
    int top;
public:
    ArrayStack() { top = -1; }
    bool empty() { return top == -1; }
    bool full() { return top == 4; }

    void push(char val) {
        if (!full()) {
            top++;
            stack[top] = val;
        }
    }

    // EXAM QUESTION: Complete the pop function (Feb 2025 Figure 4)
    char pop() {
        char grade;
        if (!empty()) {
            // (I) and (II) from the exam:
            grade = stack[top];
            top--;
            return grade;
        } else {
            cout << "Stack is empty." << endl;
            return '\0';
        }
    }
};

// --- 2. ARRAY QUEUE (Circular style often used in exams) ---
class ArrayQueue {
private:
    int items[5];
    int front, back, count;
public:
    ArrayQueue() { front = 0; back = -1; count = 0; }
    
    void append(int x) {
        if (count < 5) {
            back = (back + 1) % 5;
            items[back] = x;
            count++;
        }
    }
    
    int serve() {
        if (count > 0) {
            int val = items[front];
            front = (front + 1) % 5;
            count--;
            return val;
        }
        return -1;
    }
};

// --- 3. LINKED STACK (Topic 5) ---
struct Node {
    int data;
    Node* next;
};

class LinkedStack {
private:
    Node* top;
public:
    LinkedStack() { top = NULL; }
    
    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }
    
    int pop() {
        if (top != NULL) {
            Node* temp = top;
            int val = temp->data;
            top = top->next;
            delete temp;
            return val;
        }
        return -1;
    }
};

// --- EXAM SNIPPET: STACK & QUEUE TRACING (Feb 2025 Question 1c) ---
/*
   Initial:
   Stack S: [20, 10] (Top is 20)
   Queue Q: [2, 4] (Front is 2)
   X = 3, Y = 5
*/
void exam_tracing_stacks_queues() {
    cout << "--- Exam Tracing: Stacks & Queues ---" << endl;
    
    // Manual trace simulation
    int S[] = {10, 20}; int top = 1; // Stack S
    int Q[] = {2, 4, 0, 0, 0}; int front = 0, back = 1; // Queue Q
    int X = 3, Y = 5;

    // i. Q.append(++X + S.pop());
    // ++X -> X becomes 4
    // S.pop() -> returns 20, top becomes 0
    // Q.append(4 + 20) -> Q.append(24)
    // Results: X=4, S=[10], Q=[2, 4, 24]
    
    // ii. if(Q.serve() + 2 < Y) S.push((X+Y)%2);
    // Q.serve() -> returns 2, Q is now [4, 24]
    // 2 + 2 < 5? (4 < 5) -> TRUE
    // S.push((4+5)%2) -> S.push(9%2) -> S.push(1)
    // Results: S=[10, 1], Q=[4, 24]
    
    cout << "After operation (i) and (ii):" << endl;
    cout << "X: " << X << ", Y: " << Y << endl;
    cout << "Queue Front: " << Q[front+1] << " (since 2 was served)" << endl;
}

int main() {
    exam_tracing_stacks_queues();
    return 0;
}
