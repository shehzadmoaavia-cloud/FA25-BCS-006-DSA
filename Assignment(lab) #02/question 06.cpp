#include <iostream>
using namespace std;

struct Node {
    int price;
    Node* next;
    Node(int p) { price = p; next = NULL; }
};

void append(Node*& head, int p) {
    Node* n = new Node(p);
    if (head == NULL) { head = n; return; }
    Node* t = head;
    while (t->next != NULL) t = t->next;
    t->next = n;
}

void display(Node* head) {
    if (head == NULL) { cout << "NULL" << endl; return; }
    for (Node* t = head; t != NULL; t = t->next) cout << t->price << " -> ";
    cout << "NULL" << endl;
}

// Existing nodes are re-linked into two lines. No new node is created.
void splitEvenOdd(Node* head, Node*& evenHead, Node*& oddHead) {
    Node* evenTail = NULL;
    Node* oddTail = NULL;
    evenHead = NULL;
    oddHead = NULL;
    while (head != NULL) {
        Node* nxt = head->next;
        head->next = NULL;
        if (head->price % 2 == 0) {
            if (evenHead == NULL) evenHead = head; else evenTail->next = head;
            evenTail = head;
        } else {
            if (oddHead == NULL) oddHead = head; else oddTail->next = head;
            oddTail = head;
        }
        head = nxt;
    }
}

int main() {
    Node* head = NULL;
    int prices[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    for (int i = 0; i < 10; i++) append(head, prices[i]);

    cout << "Original  : "; display(head);
    Node* evenHead; Node* oddHead;
    splitEvenOdd(head, evenHead, oddHead);
    cout << "Even line : "; display(evenHead);
    cout << "Odd line  : "; display(oddHead);
    return 0;
}
