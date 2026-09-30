
#include <iostream>
using namespace std;

class ArrayList
{
private:
    int arr[100];
    int size;

public:
    // Constructor
    ArrayList()
    {
        size = 0;
    }

    // 1. Insert value at the end
    void insertAtEnd(int value)
    {
        if (size == 100)
        {
            cout << "List is full!" << endl;
            return;
        }

        arr[size] = value;
        size++;

        cout << value << " inserted at end." << endl;
    }

    // 2. Insert value at the start
    void insertAtStart(int value)
    {
        if (size == 100)
        {
            cout << "List is full!" << endl;
            return;
        }

        for (int i = size; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[0] = value;
        size++;

        cout << value << " inserted at start." << endl;
    }

    // 3. Insert value after a specific value
    void insertAfter(int specificValue, int value)
    {
        if (size == 100)
        {
            cout << "List is full!" << endl;
            return;
        }

        int position = -1;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] == specificValue)
            {
                position = i;
                break;
            }
        }

        if (position == -1)
        {
            cout << specificValue << " not found!" << endl;
            return;
        }

        for (int i = size; i > position + 1; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[position + 1] = value;
        size++;

        cout << value << " inserted after " << specificValue << "." << endl;
    }

    // 4. Insert value before a specific value
    void insertBefore(int specificValue, int value)
    {
        if (size == 100)
        {
            cout << "List is full!" << endl;
            return;
        }

        int position = -1;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] == specificValue)
            {
                position = i;
                break;
            }
        }

        if (position == -1)
        {
            cout << specificValue << " not found!" << endl;
            return;
        }

        for (int i = size; i > position; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[position] = value;
        size++;

        cout << value << " inserted before " << specificValue << "." << endl;
    }

    // 5. Display the array list
    void display()
    {
        if (size == 0)
        {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "Array List: ";

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // 6. Delete value from end
    void deleteFromEnd()
    {
        if (size == 0)
        {
            cout << "List is empty!" << endl;
            return;
        }

        cout << arr[size - 1] << " deleted from end." << endl;
        size--;
    }

    // 7. Delete value from start
    void deleteFromStart()
    {
        if (size == 0)
        {
            cout << "List is empty!" << endl;
            return;
        }

        cout << arr[0] << " deleted from start." << endl;

        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    // 8. Delete specific value
    void deleteSpecific(int value)
    {
        int position = -1;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                position = i;
                break;
            }
        }

        if (position == -1)
        {
            cout << value << " not found!" << endl;
            return;
        }

        for (int i = position; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;

        cout << value << " deleted from the list." << endl;
    }
};


int main()
{
    ArrayList list;
    int choice, value, specificValue;

    do
    {
        cout << "\n========== ARRAY LIST ==========\n";
        cout << "1. Insert value at end\n";
        cout << "2. Insert value at start\n";
        cout << "3. Insert value after specific value\n";
        cout << "4. Insert value before specific value\n";
        cout << "5. Display array list\n";
        cout << "6. Delete value from end\n";
        cout << "7. Delete value from start\n";
        cout << "8. Delete specific value\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtStart(value);
            break;

        case 3:
            cout << "Enter specific value: ";
            cin >> specificValue;

            cout << "Enter value to insert: ";
            cin >> value;

            list.insertAfter(specificValue, value);
            break;

        case 4:
            cout << "Enter specific value: ";
            cin >> specificValue;

            cout << "Enter value to insert: ";
            cin >> value;

            list.insertBefore(specificValue, value);
            break;

        case 5:
            list.display();
            break;

        case 6:
            list.deleteFromEnd();
            break;

        case 7:
            list.deleteFromStart();
            break;

        case 8:
            cout << "Enter value to delete: ";
            cin >> value;

            list.deleteSpecific(value);
            break;

        case 9:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 9);

    return 0;
}
