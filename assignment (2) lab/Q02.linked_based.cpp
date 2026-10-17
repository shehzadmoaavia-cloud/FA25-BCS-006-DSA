
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Queue {
    Node *frontNode, *rearNode;
public:
    Queue() : frontNode(NULL), rearNode(NULL) {}
    bool empty() { return frontNode == NULL; }

    void enqueue(int x) {
        Node* n = new Node(x);
        if (empty()) frontNode = rearNode = n;
        else {
            rearNode->next = n;
            rearNode = n;
        }
    }

    int dequeue() {
        if (empty()) return -1;
        Node* t = frontNode;
        int x = t->data;
        frontNode = frontNode->next;
        if (!frontNode) rearNode = NULL;
        delete t;
        return x;
    }

    ~Queue() {
        while (!empty()) dequeue();
    }
};

class Stack {
    Queue *q1, *q2;
public:
    Stack() {
        q1 = new Queue;
        q2 = new Queue;
    }

    void push(int x) {
        q2->enqueue(x);
        while (!q1->empty())
            q2->enqueue(q1->dequeue());

        Queue* temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (q1->empty()) cout << "Stack empty\n";
        else cout << "Removed: " << q1->dequeue() << endl;
    }

    ~Stack() {
        delete q1;
        delete q2;
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

