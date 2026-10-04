#include <iostream>
using namespace std;

struct Node {
    int box;
    Node* next;
    Node(int b) { box = b; next = NULL; }
};

void append(Node*& head, int b) {
    Node* n = new Node(b);
    if (head == NULL) { head = n; return; }
    Node* t = head;
    while (t->next != NULL) t = t->next;
    t->next = n;
}

void display(Node* head) {
    if (head == NULL) { cout << "NULL" << endl; return; }
    for (Node* t = head; t != NULL; t = t->next) cout << t->box << " -> ";
    cout << "NULL" << endl;
}

// Reverses k nodes starting at 'head'. 'rest' gets the node after them.
Node* reverseK(Node* head, int k, Node*& rest) {
    Node* prev = NULL;
    Node* cur = head;
    while (k > 0 && cur != NULL) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
        k--;
    }
    rest = cur;
    return prev;
}

Node* reverseHalves(Node* head) {
    int n = 0;
    for (Node* t = head; t != NULL; t = t->next) n++;
    if (n < 2) return head;

    int firstHalf = n / 2;
    Node* rest = NULL;
    Node* newHead = reverseK(head, firstHalf, rest);   // head becomes tail of 1st half
    Node* dummy = NULL;
    head->next = reverseK(rest, n - firstHalf, dummy); // join 2nd reversed half
    return newHead;
}

int main() {
    Node* head = NULL;
    for (int i = 1; i <= 8; i++) append(head, i);
    cout << "Before: "; display(head);
    head = reverseHalves(head);
    cout << "After : "; display(head);

    Node* odd = NULL;
    for (int i = 1; i <= 7; i++) append(odd, i);
    cout << "Before (7 boxes): "; display(odd);
    odd = reverseHalves(odd);
    cout << "After  (7 boxes): "; display(odd);
    return 0;
}
