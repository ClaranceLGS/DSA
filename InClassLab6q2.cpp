#include <iostream>
using namespace std;

struct Node {  // defining a node of the linked list
    int data;
    Node* next; //pointer to the next node
};

struct Stack {
    Node* head; //pointer to the first node 
    Node* top; //pointer to the last node
};

void push(Stack& S, int n) {
    Node* new_node = new Node{ n, nullptr }; //creating a new node dynamically
    if (S.head == nullptr) {
        S.head = new_node;
        S.top = new_node;
    }
    else {
        S.top->next = new_node;
        S.top = new_node;
    }
}

int pop(Stack& S) {
    if (S.top == nullptr) {
        cout << "Stack is empty\n";
        return -1; 
    }
    else {
        int x = S.top->data;
        if (S.top == S.head) {
            S.top = nullptr;
            S.head = nullptr;
        }
        else {
            Node* tmp = S.head;
            while (tmp->next != S.top) { //finding the node before the top node
                tmp = tmp->next;
            }
            tmp->next = nullptr;
            S.top = tmp;
        }
        return x;
    }
}

bool isEmpty(Stack& S) {
    return (S.top == nullptr);
}

bool isFull(Stack& S) {
    return false; // linked list-based stack does not have a fixed maximum size
}

int StackTop(Stack& S) {
    if (S.top == nullptr) {
        cout << "Stack is empty\n";
        return -1;
    }
    else {
        return S.top->data;
    }
}

void display(Stack& S) {
    if (S.top == nullptr) {
        cout << "Stack is empty\n";
    }
    else {
        Node* current = S.head;
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    Stack S{ nullptr, nullptr }; //creating a new stack object
    push(S, 8);
    push(S, 10);
    push(S, 5);
    push(S, 11);
    push(S, 15);
    display(S);
    cout << "Stack top: " << StackTop(S) << endl;
    cout << "Popped element: " << pop(S) << endl;
    display(S);
    return 0;
}