#include <iostream>
using namespace std;

struct Seat {
    int no;
    Seat* prev;
    Seat* next;
    Seat(int n) { no = n; prev = NULL; next = NULL; }
};

void append(Seat*& head, Seat*& tail, int n) {
    Seat* s = new Seat(n);
    if (head == NULL) { head = tail = s; return; }
    tail->next = s;
    s->prev = tail;
    tail = s;
}

void display(Seat* head) {
    for (Seat* t = head; t != NULL; t = t->next) {
        cout << t->no;
        if (t->next != NULL) cout << "->";
    }
    cout << endl;
}

// Positions 1 and n stay fixed. Swap position 2 with n-1, 4 with n-3, ...
void alternateSwap(Seat* head, Seat* tail) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) return;
    Seat* left = head->next;       // position 2
    Seat* right = tail->prev;      // position n-1
    int i = 2;
    int j = 0;
    for (Seat* t = head; t != NULL; t = t->next) j++;
    j = j - 1;                     // position n-1

    while (i < j) {
        int temp = left->no;       // swap the seat numbers
        left->no = right->no;
        right->no = temp;

        i += 2;
        j -= 2;
        if (i >= j) break;
        left = left->next->next;
        right = right->prev->prev;
    }
}

int main() {
    Seat* head = NULL;
    Seat* tail = NULL;
    for (int i = 1; i <= 9; i++) append(head, tail, i);

    cout << "Before: "; display(head);
    alternateSwap(head, tail);
    cout << "After : "; display(head);
    return 0;
}
