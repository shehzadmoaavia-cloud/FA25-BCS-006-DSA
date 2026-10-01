#include <iostream>                         // Includes the input/output library.

using namespace std;                        // Allows us to use cout, cin, and endl directly.

// Node class represents one node of the doubly linked list.
class Node
{
public:                                    // Makes data and pointers accessible.

    int data;                              // Stores the value of the node.

    Node* next;                            // Points to the next node.

    Node* prev;                            // Points to the previous node.

    Node(int value)                        // Constructor that receives a value.
    {
        data = value;                      // Stores the given value in data.

        next = NULL;                       // Initially, next points to nothing.

        prev = NULL;                       // Initially, prev points to nothing.
    }                                      // End of Node constructor.
};                                         // End of Node class.

// DoublyLinkedList class manages the complete linked list.
class DoublyLinkedList
{
private:                                   // Private members can only be used inside the class.

    Node* head;                             // Points to the first node of the list.

public:                                    // Functions below can be called from main().

    DoublyLinkedList()                     // Constructor of DoublyLinkedList.
    {
        head = NULL;                       // Initially, the list is empty.
    }                                      // End of constructor.

    void insert(int value)                 // Function to insert a node at the end.
    {
        Node* newNode = new Node(value);   // Creates a new node dynamically.

        if (head == NULL)                  // Checks if the list is empty.
        {
            head = newNode;                // Makes the new node the first node.
            return;                        // Stops the function.
        }                                   // End of if.

        Node* temp = head;                 // Starts temp from the first node.

        while (temp->next != NULL)         // Finds the last node.
        {
            temp = temp->next;             // Moves temp to the next node.
        }                                  // End of while.

        temp->next = newNode;              // Connects the last node to the new node.

        newNode->prev = temp;              // Connects the new node back to the last node.
    }                                      // End of insert function.

    void display()                         // Function to display the linked list.
    {
        Node* temp = head;                 // Starts from the first node.

        while (temp != NULL)               // Continues until the end of the list.
        {
            cout << temp->data << " ";     // Prints the current node's data.

            temp = temp->next;             // Moves to the next node.
        }                                  // End of while.

        cout << endl;                      // Moves to the next line.
    }                                      // End of display function.

    void swapNodes(int value1, int value2) // Function to swap two nodes.
    {
        Node* node1 = NULL;                // Pointer for the first node.

        Node* node2 = NULL;                // Pointer for the second node.

        Node* temp = head;                 // Starts searching from the first node.

        while (temp != NULL)               // Searches until the end of the list.
        {
            if (temp->data == value1)      // Checks if current node contains value1.
            {
                node1 = temp;              // Stores the address of the first node.
            }                              // End of first if.

            if (temp->data == value2)      // Checks if current node contains value2.
            {
                node2 = temp;              // Stores the address of the second node.
            }                              // End of second if.

            temp = temp->next;             // Moves to the next node.
        }                                  // End of while loop.

        if (node1 == NULL || node2 == NULL) // Checks if either value was not found.
        {
            cout << "Both values were not found." << endl; // Displays an error message.
            return;                        // Stops the function.
        }                                  // End of if.

        if (node1 == node2)                // Checks if both values refer to the same node.
        {
            cout << "Both values are the same." << endl; // Displays a message.
            return;                        // Stops the function.
        }                                  // End of if.

        // CASE 1: node1 is immediately before node2.
        if (node1->next == node2)          // Checks if node1 and node2 are adjacent.
        {
            Node* before = node1->prev;    // Stores the node before node1.

            Node* after = node2->next;     // Stores the node after node2.

            if (before != NULL)            // Checks if node1 is not the first node.
                before->next = node2;      // Connects the previous node to node2.
            else                           // Executes when node1 is the first node.
                head = node2;              // Makes node2 the new head.

            if (after != NULL)             // Checks if node2 is not the last node.
                after->prev = node1;       // Connects the next node back to node1.

            node2->prev = before;          // Sets node2's previous pointer.

            node2->next = node1;           // Makes node2 point to node1.

            node1->prev = node2;           // Makes node1 point back to node2.

            node1->next = after;           // Connects node1 to the node after node2.
        }

        // CASE 2: node2 is immediately before node1.
        else if (node2->next == node1)     // Checks if node2 and node1 are adjacent.
        {
            Node* before = node2->prev;    // Stores the node before node2.

            Node* after = node1->next;     // Stores the node after node1.

            if (before != NULL)            // Checks if node2 is not the first node.
                before->next = node1;      // Connects the previous node to node1.
            else                           // Executes when node2 is the first node.
                head = node1;              // Makes node1 the new head.

            if (after != NULL)             // Checks if node1 is not the last node.
                after->prev = node2;       // Connects the next node back to node2.

            node1->prev = before;          // Sets node1's previous pointer.

            node1->next = node2;           // Makes node1 point to node2.

            node2->prev = node1;           // Makes node2 point back to node1.

            node2->next = after;           // Connects node2 to the node after node1.
        }

        // CASE 3: node1 and node2 are not next to each other.
        else
        {
            Node* node1Prev = node1->prev; // Saves node1's previous node.

            Node* node1Next = node1->next; // Saves node1's next node.

            Node* node2Prev = node2->prev; // Saves node2's previous node.

            Node* node2Next = node2->next; // Saves node2's next node.

            if (node1Prev != NULL)         // Checks if node1 is not the first node.
                node1Prev->next = node2;   // Connects node1's previous node to node2.
            else                           // Executes if node1 is the first node.
                head = node2;              // Makes node2 the new head.

            if (node1Next != NULL)         // Checks if node1 is not the last node.
                node1Next->prev = node2;   // Connects node1's next node back to node2.

            if (node2Prev != NULL)         // Checks if node2 is not the first node.
                node2Prev->next = node1;   // Connects node2's previous node to node1.
            else                           // Executes if node2 is the first node.
                head = node1;              // Makes node1 the new head.

            if (node2Next != NULL)         // Checks if node2 is not the last node.
                node2Next->prev = node1;   // Connects node2's next node back to node1.

            node1->prev = node2Prev;       // Gives node1 node2's old previous node.

            node1->next = node2Next;       // Gives node1 node2's old next node.

            node2->prev = node1Prev;       // Gives node2 node1's old previous node.

            node2->next = node1Next;       // Gives node2 node1's old next node.
        }                                  // End of CASE 3.

        cout << "Nodes swapped successfully." << endl; // Displays success message.
    }                                      // End of swapNodes function.
};                                         // End of DoublyLinkedList class.

int main()                                 // Main function where execution starts.
{
    DoublyLinkedList list;                 // Creates a doubly linked list object.

    list.insert(10);                       // Inserts 10 into the list.

    list.insert(20);                       // Inserts 20 into the list.

    list.insert(30);                       // Inserts 30 into the list.

    list.insert(40);                       // Inserts 40 into the list.

    list.insert(50);                       // Inserts 50 into the list.

    cout << "Original List: ";              // Displays the original list message.

    list.display();                        // Displays 10 20 30 40 50.

    int value1, value2;                    // Declares two integer variables.

    cout << "Enter first value: ";         // Asks the user for the first value.

    cin >> value1;                         // Takes the first value from the user.

    cout << "Enter second value: ";        // Asks the user for the second value.

    cin >> value2;                         // Takes the second value from the user.

    list.swapNodes(value1, value2);        // Calls the function to swap the two nodes.

    cout << "List after swapping nodes: "; // Displays the result message.

    list.display();                        // Displays the list after swapping.

    return 0;                              // Ends the program successfully.
}                                         // End of main function.
