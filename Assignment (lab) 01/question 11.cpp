#include <iostream>
#include <string>
using namespace std;

struct Desk {
    string name;
    Desk* prev;
    Desk* next;
    Desk(string n) { name = n; prev = NULL; next = NULL; }
};

void append(Desk*& head, Desk*& tail, string n) {
    Desk* d = new Desk(n);
    if (head == NULL) { head = tail = d; return; }
    tail->next = d;
    d->prev = tail;
    tail = d;
}

void display(Desk* head) {
    for (Desk* t = head; t != NULL; t = t->next) {
        cout << t->name;
        if (t->next != NULL) cout << ", ";
    }
    cout << endl;
}

// Swap 1st with last, 2nd with 2nd-last ... until the pointers meet or cross.
void swapDesks(Desk* head, Desk* tail) {
    Desk* left = head;
    Desk* right = tail;
    while (left != right && left->prev != right) {
        string temp = left->name;     // swap the contents, nodes stay in place
        left->name = right->name;
        right->name = temp;
        left = left->next;
        right = right->prev;
    }
}

int main() {
    Desk* head = NULL;
    Desk* tail = NULL;
    string names[] = {"Alice", "Bob", "Charlie", "Dana", "Eva", "Frank"};
    for (int i = 0; i < 6; i++) append(head, tail, names[i]);

    cout << "Before: "; display(head);
    swapDesks(head, tail);
    cout << "After : "; display(head);
    return 0;
}
