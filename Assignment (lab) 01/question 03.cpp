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

void display(Node* head) {
    if (head == NULL) { cout << "NULL" << endl; return; }
    for (Node* t = head; t != NULL; t = t->next) cout << t->name << " -> ";
    cout << "NULL" << endl;
}

// Keeps the first occurrence of every contact, deletes the later ones.
void removeDuplicates(Node* head) {
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        Node* prev = cur;
        Node* run = cur->next;
        while (run != NULL) {
            if (run->name == cur->name) {
                prev->next = run->next;   // unlink duplicate
                delete run;
                run = prev->next;
            } else {
                prev = run;
                run = run->next;
            }
        }
    }
}

int main() {
    Node* head = NULL;
    append(head, "Ali");
    append(head, "Sara");
    append(head, "Ali");
    append(head, "Bilal");
    append(head, "Sara");
    append(head, "Ali");
    append(head, "Hina");

    cout << "Before: "; display(head);
    removeDuplicates(head);
    cout << "After : "; display(head);
    return 0;
}
