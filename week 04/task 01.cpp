#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteEvenNodes(Node*& head) {
    // Delete even-valued nodes from beginning
    while (head != NULL && head->data % 2 == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->next->data % 2 == 0) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
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
    head->next = new Node{15, NULL};
    head->next->next = new Node{20, NULL};
    head->next->next->next = new Node{25, NULL};
    head->next->next->next->next = new Node{30, NULL};

    cout << "Before deletion: ";
    display(head);

    deleteEvenNodes(head);

    cout << "\nAfter deleting even nodes: ";
    display(head);

    return 0;
}
