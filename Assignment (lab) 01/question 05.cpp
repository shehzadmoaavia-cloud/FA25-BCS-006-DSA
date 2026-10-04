#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node(string n) { name = n; next = NULL; }
};

void append(Node*& head, string n) {
    Node* x = new Node(n);
    if (head == NULL) { head = x; return; }
    Node* t = head;
    while (t->next != NULL) t = t->next;
    t->next = x;
}

// For an even count, returns the left one of the two middle nodes.
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    Node* odd = NULL;
    append(odd, "Ahmed"); append(odd, "Bilal"); append(odd, "Chand");
    append(odd, "Danish"); append(odd, "Essa");
    cout << "5 friends, middle = " << findMiddle(odd)->name << endl;

    Node* even = NULL;
    append(even, "Ahmed"); append(even, "Bilal"); append(even, "Chand");
    append(even, "Danish"); append(even, "Essa"); append(even, "Faisal");
    cout << "6 friends, middle = " << findMiddle(even)->name << endl;
    return 0;
}
