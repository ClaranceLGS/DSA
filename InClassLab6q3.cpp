#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Node {
    public:
        int data;
        Node* next;
};

class LinkedList {
    private:
        Node* top;

    public:
        LinkedList() {
            top = NULL;
        }

        bool push(int value) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = top;
            top = newNode;
            return true;
        }

        int pop() {
            if (top == NULL) {
                cout << "Stack Underflow" << endl;
                return 0;
            }
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return value;
        }

        void display() {
            if (top == NULL) {
                cout << "Stack is Empty" << endl;
                return;
            }
            cout << "Stack: ";
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

class Array {
    private:
        int* arr;
        int top;
        int size;

    public:
        Array(int s) {
            arr = new int[s];
            size = s;
            top = -1;
        }

        bool push(int value) {
            if (top == size - 1) {
                cout << "Stack Overflow" << endl;
                return false;
            }
            top++;
            arr[top] = value;
            return true;
        }

        int pop() {
            if (top == -1) {
                cout << "Stack Underflow" << endl;
                return 0;
            }
            int value = arr[top];
            top--;
            return value;
        }

        void display() {
            if (top == -1) {
                cout << "Stack is Empty" << endl;
                return;
            }
            cout << "Stack: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    // Using LinkedList
    LinkedList s1;
    auto start = high_resolution_clock::now();
    s1.push(8);
    s1.push(10);
    s1.push(5);
    s1.push(11);
    s1.push(15);
    s1.push(23);
    s1.push(6);
    s1.push(18);
    s1.push(20);
    s1.push(17);
    s1.display();

    for (int i = 0; i < 5; i++) {
        s1.pop();
    }
    s1.display();

    s1.push(4);
    s1.push(30);
    s1.push(3);
    s1.push(1);
    s1.display();
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop - start);
    cout << "Execution time using LinkedList: " << duration1.count() << " microseconds" << endl;

    // Using Array
    Array s2(10);
    start = high_resolution_clock::now();
    s2.push(8);
    s2.push(10);
    s2.push(5);
    s2.push(11);
    s2.push(15);
    s2.push(23);
    s2.push(6);
    s2.push(18);
    s2.push(20);
    s2.push(17);
    s2.display();

    for (int i = 0; i < 5; i++) {
        s2.pop();
    }
    s2.display();

    s2.push(4);
    s2.push(30);
    s2.push(3);
    s2.push(1);
    s2.display();
    stop = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop - start);
    cout << "Execution time using Array: " << duration2.count() << " microseconds" << endl;

    return 0;
}