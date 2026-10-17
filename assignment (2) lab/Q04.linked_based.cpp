
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Queue {
    Node *f, *r;
    int count;
public:
    Queue() : f(NULL), r(NULL), count(0) {}
    bool empty() { return f == NULL; }
    int size() { return count; }

    void enqueue(int x) {
        Node* n = new Node(x);
        if (empty()) f = r = n;
        else { r->next = n; r = n; }
        count++;
    }

    int dequeue() {
        if (empty()) return -1;
        Node* t = f;
        int x = t->data;
        f = f->next;
        if (!f) r = NULL;
        delete t;
        count--;
        return x;
    }

    void display() {
        int n = count;
        while (n--) {
            int x = dequeue();
            cout << x << " ";
            enqueue(x);
        }
        cout << endl;
    }

    ~Queue() {
        while (!empty()) dequeue();
    }
};

void selectionSort(Queue& q) {
    int n = q.size();
    int* a = new int[n];

    for (int i = 0; i < n; i++) a[i] = q.dequeue();

    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[m]) m = j;

        int t = a[i];
        a[i] = a[m];
        a[m] = t;
    }

    for (int i = 0; i < n; i++) q.enqueue(a[i]);
    delete[] a;
}

int main() {
    Queue q;
    q.enqueue(50);
    q.enqueue(20);
    q.enqueue(40);
    q.enqueue(10);
    q.enqueue(30);

    selectionSort(q);
    q.display();
    return 0;
}

