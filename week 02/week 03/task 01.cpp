#include <iostream>                  // Includes the input/output library for cout and cin.

using namespace std;                 // Allows us to use cout, cin, endl without writing std::.

// Defines a class named Node.
class Node
{
public:                              // Makes the following members accessible outside the class.

    int data;                        // Stores the value/data of the node.

    Node* next;                      // Pointer that stores the address of the next node.

    Node* prev;                      // Pointer that stores the address of the previous node.

    Node(int value)                  // Constructor that receives a value when a node is created.
    {
        data = value;                // Stores the given value in the data variable.

        next = NULL;                 // Initially, next does not point to any node.

        prev = NULL;                 // Initially, previous does not point to any node.
    }                                // End of Node constructor.
};                                   // End of Node class.

// Defines a class named DoublyLinkedList.
class DoublyLinkedList
{
private:                             // Private members can only be accessed inside the class.

    Node* head;                       // Pointer that points to the first node of the list.

public:                              // The following functions can be accessed from main().

    DoublyLinkedList()               // Constructor of the DoublyLinkedList class.
    {
        head = NULL;                 // Initially, the list is empty.
    }                                // End of constructor.

    void insert(int value)           // Function to insert a new node at the end.
    {
        Node* newNode = new Node(value); // Creates a new node dynamically with the given value.

        if (head == NULL)             // Checks whether the list is empty.
        {
            head = newNode;           // If empty, the new node becomes the first node.
            return;                   // Stops the function here.
        }                             // End of if statement.

        Node* temp = head;             // Creates a temporary pointer starting from the first node.

        while (temp->next != NULL)     // Moves through the list until the last node is found.
        {
            temp = temp->next;         // Moves temp to the next node.
        }                             // End of while loop.

        temp->next = newNode;          // Connects the last node to the new node.

        newNode->prev = temp;          // Connects the new node back to the previous last node.
    }                                 // End of insert function.

    void display()                    // Function to display all elements of the list.
    {
        Node* temp = head;             // Starts temp from the first node.

        while (temp != NULL)            // Continues until temp reaches the end of the list.
        {
            cout << temp->data << " "; // Prints the data stored in the current node.

            temp = temp->next;          // Moves temp to the next node.
        }                              // End of while loop.

        cout << endl;                  // Moves the cursor to the next line.
    }                                  // End of display function.

    void reverse()                    // Function to reverse the doubly linked list.
    {
        Node* current = head;          // Starts current from the first node.

        Node* temp = NULL;              // Temporary pointer used for swapping prev and next.

        while (current != NULL)         // Continues until all nodes have been processed.
        {
            temp = current->prev;      // Saves the current node's previous pointer.

            current->prev = current->next; // Changes prev to point to the next node.

            current->next = temp;       // Changes next to point to the previous node.

            current = current->prev;    // Moves to the next node in the original list.
        }                              // End of while loop.

        if (temp != NULL)               // Checks whether the list had at least one node.
        {
            head = temp->prev;          // Updates head to the new first node.
        }                              // End of if statement.
    }                                  // End of reverse function.
};                                     // End of DoublyLinkedList class.

int main()                           // Main function where program execution starts.
{
    DoublyLinkedList list;            // Creates an object named list.

    list.insert(10);                  // Inserts 10 into the list.

    list.insert(20);                  // Inserts 20 into the list.

    list.insert(30);                  // Inserts 30 into the list.

    list.insert(40);                  // Inserts 40 into the list.

    list.insert(50);                  // Inserts 50 into the list.

    cout << "Original List: ";         // Prints a message before displaying the original list.

    list.display();                   // Displays the original list: 10 20 30 40 50.

    list.reverse();                   // Reverses the doubly linked list.

    cout << "Reversed List: ";         // Prints a message before displaying the reversed list.

    list.display();                   // Displays the reversed list: 50 40 30 20 10.

    return 0;                         // Ends the main function successfully.
}                                    // End of main function.
