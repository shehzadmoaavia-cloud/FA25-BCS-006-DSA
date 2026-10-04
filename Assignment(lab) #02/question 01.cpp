#include <iostream>
#include <string>
using namespace std;

struct Node {
    string log;
    Node* next;
    Node(string l) { log = l; next = NULL; }
};

void append(Node*& head, string l) {
    Node* n = new Node(l);
    if (head == NULL) { head = n; return; }
    Node* t = head;
    while (t->next != NULL) t = t->next;
    t->next = n;
}

// Recursion: go to the end first, print while coming back.
void displayReverse(Node* head) {
    if (head == NULL) return;
    displayReverse(head->next);
    cout << head->log << endl;
}

int main() {
    Node* head = NULL;
    append(head, "10:00 Server started");
    append(head, "10:05 User logged in");
    append(head, "10:10 File uploaded");
    append(head, "10:15 Error: timeout");

    cout << "Logs (latest first):" << endl;
    displayReverse(head);
    return 0;
}
