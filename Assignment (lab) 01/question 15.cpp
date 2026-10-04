#include <iostream>
using namespace std;

struct Node {
    int pos;
    Node* next;
    Node(int p) { pos = p; next = NULL; }
};

int josephus(int n, int m) {
    // build the circle 1..n
    Node* head = new Node(1);
    Node* tail = head;
    for (int i = 2; i <= n; i++) {
        tail->next = new Node(i);
        tail = tail->next;
    }
    tail->next = head;             // make it circular

    Node* prev = tail;
    Node* cur = head;
    while (cur->next != cur) {     // until one person is left
        for (int i = 1; i < m; i++) {   // skip m-1 persons
            prev = cur;
            cur = cur->next;
        }
        cout << "Killed: " << cur->pos << endl;
        prev->next = cur->next;
        delete cur;
        cur = prev->next;
    }
    int survivor = cur->pos;
    delete cur;
    return survivor;
}

int main() {
    int n, m;
    cout << "Enter N (persons) and M: ";
    cin >> n >> m;
    if (n <= 0 || m <= 0) { cout << "Invalid input" << endl; return 0; }
    int safe = josephus(n, m);
    cout << "Safe place to survive = " << safe << endl;
    return 0;
}
