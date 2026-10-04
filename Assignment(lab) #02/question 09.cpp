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
    for (Node* t = head; t != NULL; t = t->next) cout << t->id << " -> ";
    cout << "NULL" << endl;
}

Node* deleteAll(Node* head, int key) {
    // Case 1: key is at the beginning (may repeat)
    while (head != NULL && head->id == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    // Case 2 and 3: key in the middle or at the end
    Node* cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->id == key) {
            Node* temp = cur->next;
            cur->next = temp->next;
            delete temp;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

int main() {
    Node* head = NULL;
    int a[] = {7, 7, 3, 7, 9, 5, 7, 2, 7};
    for (int i = 0; i < 9; i++) append(head, a[i]);

    cout << "Catalog      : "; display(head);
    head = deleteAll(head, 7);
    cout << "After delete 7: "; display(head);
    head = deleteAll(head, 100);
    cout << "Delete 100 (not present): "; display(head);
    return 0;
}
