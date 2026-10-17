
#include <iostream>
using namespace std;

const int SIZE = 100;

class Stack {
    int a[SIZE], top;
public:
    Stack() : top(-1) {}
    bool empty() { return top == -1; }
    int size() { return top + 1; }

    void push(int x) {
        if (top < SIZE - 1) a[++top] = x;
    }

    int pop() {
        if (empty()) return -1;
        return a[top--];
    }

    void display() {
        for (int i = top; i >= 0; i--) cout << a[i] << " ";
        cout << endl;
    }
};

void insertionSort(Stack& s) {
    int n = s.size(), a[SIZE];

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

