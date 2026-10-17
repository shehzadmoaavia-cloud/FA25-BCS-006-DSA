
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void insertFront(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = front;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            front->prev = newNode;
            front = newNode;
        }

        cout << value << " inserted at front.\n";
    }

    void insertRear(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = rear;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " inserted at rear.\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }

        Node* temp = front;
        cout << "Deleted from front: " << temp->data << endl;

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        } else {
            front->prev = NULL;
        }

        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }

        Node* temp = rear;
        cout << "Deleted from rear: " << temp->data << endl;

        rear = rear->prev;

        if (rear == NULL) {
            front = NULL;
        } else {
            rear->next = NULL;
        }

        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }

        Node* temp = front;
        cout << "Deque: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~Deque() {
        while (!isEmpty()) {
            deleteFront();
        }
    }
};

int main() {
    Deque d;
    int choice, value;

    do {
        cout << "\n--- DEQUE USING LINKED LIST ---\n";
        cout << "1. Insert Front\n";
        cout << "2. Insert Rear\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                d.insertFront(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                d.insertRear(value);
                break;

            case 3:
                d.deleteFront();
                break;

            case 4:
                d.deleteRear();
                break;

            case 5:
                d.display();
                break;

            case 6:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

