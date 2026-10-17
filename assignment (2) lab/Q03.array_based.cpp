
#include <iostream>
using namespace std;

const int SIZE = 100;

class Queue {
    int a[SIZE], f, r, count;
public:
    Queue() : f(0), r(-1), count(0) {}
    bool empty() { return count == 0; }
    int size() { return count; }

    void enqueue(int x) {
        if (count == SIZE) return;
        r = (r + 1) % SIZE;
        a[r] = x;
        count++;
    }

    int dequeue() {
        if (empty()) return -1;
        int x = a[f];
        f = (f + 1) % SIZE;
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
};

void bubbleSort(Queue& q) {
    int n = q.size(), a[SIZE];

    for (int i = 0; i < n; i++) a[i] = q.dequeue();

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }

    for (int i = 0; i < n; i++) q.enqueue(a[i]);
}

int main() {
    Queue q;
    q.enqueue(40);
    q.enqueue(10);
    q.enqueue(30);
    q.enqueue(20);

    bubbleSort(q);
    q.display();
    return 0;
}

