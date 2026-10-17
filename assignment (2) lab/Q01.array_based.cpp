
#include <iostream>
using namespace std;

const int SIZE = 100;

class Stack {
    int a[SIZE], top;
public:
    Stack() : top(-1) {}
    bool empty() { return top == -1; }

    void push(int x) {
        if (top < SIZE - 1) a[++top] = x;
    }

    int pop() {
        if (empty()) return -1;
        return a[top--];
    }
};

class Queue {
    Stack s1, s2;
public:
    void enqueue(int x) { s1.push(x); }

    void dequeue() {
        if (s2.empty())
            while (!s1.empty()) s2.push(s1.pop());

        if (s2.empty()) cout << "Queue empty\n";
        else cout << "Removed: " << s2.pop() << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}

