#include <iostream>
using namespace std;

struct Node {
    int reading;
    Node* next;
    Node(int r) { reading = r; next = NULL; }
};

// Floyd's cycle detection (slow and fast pointers).
bool hasLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;            // 1 step
        fast = fast->next->next;      // 2 steps
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    a->next = b; b->next = c; c->next = d; d->next = e;

    cout << "Buffer 1 (no cycle): " << (hasLoop(a) ? "Loop found" : "No loop") << endl;

    e->next = c;   // faulty pointer: last node points back to 30
    cout << "Buffer 2 (faulty)  : " << (hasLoop(a) ? "Loop found" : "No loop") << endl;
    return 0;
}
