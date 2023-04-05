#include <iostream>
using namespace std;

const int MAX = 5;

class Stack { 
private:
    int top;
    int stack[MAX]; //array used to store the stack elements

public:
    Stack() {
        top = -1; //indicating an empty stack
    }

    bool isEmpty() {
        return (top == -1); //indicating whether the stack is empty or not
    }

    bool isFull() {
        return (top == MAX - 1); //indicating whether the stack is full or not
    }

    void push(int item) {
        if (isFull()) {
            cout << "Error: Stack Overflow\n";
        }
        else {
            top++;
            stack[top] = item;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack Underflow\n";
            return -1;
        }
        else {
            int item = stack[top];
            top--;
            return item;
        }
    }

    int StackTop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty\n";
            return -1;
        }
        else {
            return stack[top];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
        }
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Stack myStack; //creating a new stack object stack

    myStack.push(8);
    myStack.push(10);
    myStack.push(5);
    myStack.push(11);
    myStack.push(15);

    myStack.display(); 

    cout << "Stack top: " << myStack.StackTop() << "\n"; 

    myStack.pop();

    myStack.display(); 

    cout << "Stack top: " << myStack.StackTop() << "\n"; 

    return 0;
}