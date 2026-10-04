#include <iostream>
using namespace std;

struct Node {
    int design;
    Node* next;
    Node(int d) { design = d; next = NULL; }
};

void append(Node*& head, int d) {
    Node* n = new Node(d);
    if (head == NULL) { head = n; return; }
    Node* t = head;
    while (t->next != NULL) t = t->next;
    t->next = n;
}

void display(Node* head) {
    if (head == NULL) { cout << "NULL" << endl; return; }
    for (Node* t = head; t != NULL; t = t->next) cout << t->design << " -> ";
    cout << "NULL" << endl;
}

// For every stamp, look at all stamps after it and delete the same design.
void removeDuplicateStamps(Node* head) {
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        Node** link = &cur->next;          // address of the pointer that points to 'run'
        while (*link != NULL) {
            if ((*link)->design == cur->design) {
                Node* dup = *link;
                *link = dup->next;         // skip the duplicate
                delete dup;
            } else {
                link = &(*link)->next;
            }
        }
    }
}

int main() {
    Node* head = NULL;
    int d[] = {101, 205, 101, 307, 205, 410, 307, 101};
    for (int i = 0; i < 8; i++) append(head, d[i]);

    cout << "Before: "; display(head);
    removeDuplicateStamps(head);
    cout << "After : "; display(head);
    return 0;
}
