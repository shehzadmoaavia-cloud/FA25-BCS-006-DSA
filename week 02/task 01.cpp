#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert node at the end
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Display linked list normally
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Display reverse using loop
    void displayReverseUsingLoop() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        // Count number of nodes
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Print nodes from last to first
        for (int i = count; i >= 1; i--) {
            temp = head;

            for (int j = 1; j < i; j++) {
                temp = temp->next;
            }

            cout << temp->data << " ";
        }

        cout << endl;
    }

    // Recursive function
    void reverseRecursive(Node* temp) {
        if (temp == NULL) {
            return;
        }

        reverseRecursive(temp->next);

        cout << temp->data << " ";
    }

    // Display reverse using recursion
    void displayReverseUsingRecursion() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        reverseRecursive(head);
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Insert values
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    // Display original list
    cout << "Original Linked List: ";
    list.display();

    // Reverse using loop
    cout << "Reverse using Loop: ";
    list.displayReverseUsingLoop();

    // Reverse using recursion
    cout << "Reverse using Recursion: ";
    list.displayReverseUsingRecursion();

    return 0;
}
