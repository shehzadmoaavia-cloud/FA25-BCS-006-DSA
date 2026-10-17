
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Stack {
    Node* topNode;
    int count;
public:
    Stack() : topNode(NULL), count(0) {}
    bool empty() { return topNode == NULL; }
    int size() { return count; }

    void push(int x) {
        Node* n = new Node(x);
        n->next = topNode;
        topNode = n;
        count++;
    }

    int pop() {
        if (empty()) return -1;
        Node* t = topNode;
        int x = t->data;
        topNode = topNode->next;
        delete t;
        count--;
        return x;
    }

    void display() {
        Node* t = topNode;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (!empty()) pop();
    }
};

void insertionSort(Stack& s) {
    int n = s.size();
    int* a = new int[n];

    for (int i = 0; i < n; i++) a[i] = s.pop();

    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    for (int i = n - 1; i >= 0; i--) s.push(a[i]);
    delete[] a;
}

int main() {
    Stack s;
    s.push(40);
    s.push(10);
    s.push(30);
    s.push(20);

    insertionSort(s);
    s.display();
    return 0;
}

