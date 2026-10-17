
#include <iostream>
using namespace std;

const int SIZE = 100;

class Queue {
    int a[SIZE], front, rear, count;
public:
    Queue() : front(0), rear(-1), count(0) {}
    bool empty() { return count == 0; }

    bool enqueue(int x) {
        if (count == SIZE) return false;
        rear = (rear + 1) % SIZE;
        a[rear] = x;
        count++;
        return true;
    }

    int dequeue() {
        if (empty()) return -1;
        int x = a[front];
        front = (front + 1) % SIZE;
        count--;
        return x;
    }
};

class Stack {
    Queue q1, q2;
public:
    void push(int x) {
        if (!q2.enqueue(x)) {
            cout << "Stack full\n";
            return;
        }

        while (!q1.empty())
            q2.enqueue(q1.dequeue());

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (q1.empty()) cout << "Stack empty\n";
        else cout << "Removed: " << q1.dequeue() << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.pop();
    s.pop();
    return 0;
}

