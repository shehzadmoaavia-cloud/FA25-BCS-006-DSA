#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int josephus(int n, int k) {
    Node* head = new Node{1, NULL};
    Node* last = head;

    for (int i = 2; i <= n; i++) {
        last->next = new Node{i, NULL};
        last = last->next;
    }

    // Make the list circular
    last->next = head;

    Node* current = head;
    Node* previous = last;

    while (current->next != current) {

        // Move k-1 positions
        for (int count = 1; count < k; count++) {
            previous = current;
            current = current->next;
        }

        // Delete current node
        previous->next = current->next;
        delete current;

        current = previous->next;
    }

    int survivor = current->data;
    delete current;

    return survivor;
}

int main() {
    int n, k;

    cout << "Enter number of people: ";
    cin >> n;

    cout << "Enter counting number: ";
    cin >> k;

    cout << "Survivor: " << josephus(n, k);

    return 0;
}
