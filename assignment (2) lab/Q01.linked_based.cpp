
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Stack {
    Node* topNode;
public:
    Stack() : topNode(NULL) {}
    bool empty() { return topNode == NULL; }

    void push(int x) {
        Node* n = new Node(x);
        n->next = topNode;
        topNode = n;
    }

    int pop() {
        if (empty()) return -1;
        Node* t = topNode;
        int x = t->data;
        topNode = topNode->next;
        delete t;
        return x;
    }

    ~Stack() {
        while (!empty()) pop();
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

