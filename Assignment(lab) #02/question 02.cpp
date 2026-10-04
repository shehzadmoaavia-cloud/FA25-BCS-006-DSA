#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* next;
    Node(string s) { song = s; next = NULL; }
};

void append(Node*& head, string s) {
    Node* n = new Node(s);
    if (head == NULL) { head = n; return; }
    Node* t = head;
    while (t->next != NULL) t = t->next;
    t->next = n;
}

void display(Node* head) {
    if (head == NULL) { cout << "NULL" << endl; return; }
    for (Node* t = head; t != NULL; t = t->next) cout << t->song << " -> ";
    cout << "NULL" << endl;
}

// Only the next links are changed. No node is created or moved.
Node* reversePlaylist(Node* head) {
    Node* prev = NULL;
    Node* cur = head;
    while (cur != NULL) {
        Node* nxt = cur->next;   // save next
        cur->next = prev;        // reverse the link
        prev = cur;              // move prev
        cur = nxt;               // move cur
    }
    return prev;                 // new head (old last song)
}

int main() {
    Node* head = NULL;
    append(head, "Song A");
    append(head, "Song B");
    append(head, "Song C");
    append(head, "Song D");

    cout << "Original : "; display(head);
    head = reversePlaylist(head);
    cout << "Reversed : "; display(head);
    return 0;
}
