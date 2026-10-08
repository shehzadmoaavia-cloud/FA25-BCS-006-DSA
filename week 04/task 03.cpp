#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteEvenPositionNodes(Node*& head) {
    Node* current = head;

    while (current != NULL && current->next != NULL) {

        // current->next is at an even position
        Node* temp = current->next;

        current->next = current->next->next;

        delete temp;

        current = current->next;
    }
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};
    head->next->next->next = new Node{40, NULL};
    head->next->next->next->next = new Node{50, NULL};
    head->next->next->next->next->next = new Node{60, NULL};

    cout << "Before deletion: ";
    display(head);

    deleteEvenPositionNodes(head);

    cout << "\nAfter deleting even positions: ";
    display(head);

    return 0;
}
