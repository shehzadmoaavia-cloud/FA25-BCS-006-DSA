#include <iostream>                         // Includes input/output library.

using namespace std;                        // Allows us to use cout and endl directly.

// Node for Singly Linked List.
class SNode
{
public:                                    // Makes members accessible outside the class.

    int data;                              // Stores data of the node.

    SNode* next;                           // Points to the next node.

    SNode(int value)                       // Constructor for SNode.
    {
        data = value;                      // Stores the given value.

        next = NULL;                       // Initially, next points to nothing.
    }                                      // End of SNode constructor.
};                                         // End of SNode class.

// Singly Linked List.
class SinglyLinkedList
{
public:                                    // Makes members accessible outside the class.

    SNode* head;                           // Points to the first node.

    SinglyLinkedList()                     // Constructor of singly linked list.
    {
        head = NULL;                       // Initially, the list is empty.
    }                                      // End of constructor.

    void insert(int value)                 // Function to insert a node.
    {
        SNode* newNode = new SNode(value); // Creates a new node with the given value.

        if (head == NULL)                  // Checks if the list is empty.
        {
            head = newNode;                // Makes new node the first node.
            return;                        // Stops the function.
        }                                  // End of if.

        SNode* temp = head;                // Starts temp from the first node.

        while (temp->next != NULL)         // Finds the last node.
        {
            temp = temp->next;             // Moves temp to the next node.
        }                                  // End of while.

        temp->next = newNode;              // Connects the last node to the new node.
    }                                      // End of insert function.

    void display()                        // Function to display the list.
    {
        SNode* temp = head;                // Starts temp from the first node.

        while (temp != NULL)               // Continues until the end of the list.
        {
            cout << temp->data << " ";     // Prints the current node's data.

            temp = temp->next;             // Moves to the next node.
        }                                  // End of while.

        cout << endl;                      // Moves to the next line.
    }                                      // End of display function.
};                                         // End of SinglyLinkedList class.

// Node for Doubly Linked List.
class DNode
{
public:                                    // Makes members accessible outside the class.

    int data;                              // Stores data of the node.

    DNode* next;                           // Points to the next node.

    DNode* prev;                           // Points to the previous node.

    DNode(int value)                       // Constructor for DNode.
    {
        data = value;                      // Stores the given value.

        next = NULL;                       // Initially, next points to nothing.

        prev = NULL;                       // Initially, prev points to nothing.
    }                                      // End of DNode constructor.
};                                         // End of DNode class.

// Doubly Linked List.
class DoublyLinkedList
{
public:                                    // Makes members accessible outside the class.

    DNode* head;                           // Points to the first node.

    DoublyLinkedList()                     // Constructor of doubly linked list.
    {
        head = NULL;                       // Initially, the list is empty.
    }                                      // End of constructor.

    void insert(int value)                 // Function to insert a node.
    {
        DNode* newNode = new DNode(value); // Creates a new doubly linked node.

        if (head == NULL)                  // Checks if the list is empty.
        {
            head = newNode;                // Makes new node the first node.
            return;                        // Stops the function.
        }                                  // End of if.

        DNode* temp = head;                // Starts temp from the first node.

        while (temp->next != NULL)         // Finds the last node.
        {
            temp = temp->next;             // Moves temp to the next node.
        }                                  // End of while.

        temp->next = newNode;              // Connects the last node to the new node.

        newNode->prev = temp;              // Connects the new node back to the previous node.
    }                                      // End of insert function.

    void display()                         // Function to display the doubly linked list.
    {
        DNode* temp = head;                // Starts temp from the first node.

        while (temp != NULL)               // Continues until the end of the list.
        {
            cout << temp->data << " ";     // Prints the current node's data.

            temp = temp->next;             // Moves to the next node.
        }                                  // End of while.

        cout << endl;                      // Moves to the next line.
    }                                      // End of display function.
};                                         // End of DoublyLinkedList class.

// Function to convert singly linked list to doubly linked list.
DoublyLinkedList convertToDoubly(SinglyLinkedList& singlyList)
{
    DoublyLinkedList doublyList;           // Creates an empty doubly linked list.

    SNode* temp = singlyList.head;         // Starts temp from the first node of singly list.

    while (temp != NULL)                   // Traverses the complete singly linked list.
    {
        doublyList.insert(temp->data);     // Inserts each value into the doubly linked list.

        temp = temp->next;                 // Moves to the next singly linked node.
    }                                      // End of while.

    return doublyList;                     // Returns the converted doubly linked list.
}                                          // End of convertToDoubly function.

int main()                                 // Main function where program execution starts.
{
    SinglyLinkedList singlyList;           // Creates a singly linked list object.

    singlyList.insert(10);                 // Inserts 10 into singly list.

    singlyList.insert(20);                 // Inserts 20 into singly list.

    singlyList.insert(30);                 // Inserts 30 into singly list.

    singlyList.insert(40);                 // Inserts 40 into singly list.

    singlyList.insert(50);                 // Inserts 50 into singly list.

    cout << "Singly Linked List: ";        // Displays message for singly list.

    singlyList.display();                  // Displays 10 20 30 40 50.

    DoublyLinkedList doublyList =          // Creates a doubly list.
        convertToDoubly(singlyList);       // Converts singly list into doubly list.

    cout << "Doubly Linked List: ";        // Displays message for doubly list.

    doublyList.display();                  // Displays 10 20 30 40 50.

    return 0;                              // Ends the program successfully.
}                                         // End of main function.
