#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
    Node(int i) { id = i; next = NULL; }
};

void append(Node*& head, int i) {
    Node* n = new Node(i);
    if (head == NULL) { head = n; return; }
    Node* t = head;
    while (t->next != NULL) t = t->next;
    t->next = n;
}

void display(Node* head) {
    if (head == NULL) { cout << "NULL" << endl; return; }
    for (Node* t = head; t != NULL; t = t->next) cout << t->id << "->";
    cout << "NULL" << endl;
}

// Swaps every two consecutive nodes by changing links only.
Node* swapPairs(Node* head) {
    Node** link = &head;   // pointer to the link that points to the current pair
    while (*link != NULL && (*link)->next != NULL) {
        Node* first = *link;
        Node* second = first->next;
        first->next = second->next;   // 1st points to the node after the pair
        second->next = first;         // 2nd points to 1st
        *link = second;               // previous part points to 2nd
        link = &first->next;          // move to the next pair
    }
    return head;
}

int main() {
    Node* head = NULL;
    for (int i = 1; i <= 6; i++) append(head, i);
    cout << "Input : "; display(head);
    head = swapPairs(head);
    cout << "Output: "; display(head);

    Node* odd = NULL;
    for (int i = 1; i <= 5; i++) append(odd, i);
    cout << "Input : "; display(odd);
    odd = swapPairs(odd);
    cout << "Output: "; display(odd);
    return 0;
}
