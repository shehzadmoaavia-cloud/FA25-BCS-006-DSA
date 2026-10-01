#include <iostream>
using namespace std;

class ArrayList
{
private:
    int arr[100];
    int size;

public:
    ArrayList()
    {
        size = 0;
    }

    // Insert value at end
    void insertAtEnd(int value)
    {
        if (size == 100)
        {
            cout << "List is full!" << endl;
            return;
        }

        arr[size] = value;
        size++;
    }

    // Display Array List
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

    // Linear Search using while loop
    void linearSearch(int value)
    {
        int i = 0;
        bool found = false;

        while (i < size)
        {
            if (arr[i] == value)
            {
                cout << "Value " << value
                     << " found at position " << i + 1 << endl;

                found = true;
                break;
            }

            i++;
        }

        if (found == false)
        {
            cout << "Value " << value << " not found!" << endl;
        }
    }
};

int main()
{
    ArrayList list;
    int n, value, searchValue;

    cout << "How many values do you want to insert? ";
    cin >> n;

    // Insert values
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;

        list.insertAtEnd(value);
    }

    // Display list
    list.display();

    // Search value
    cout << "Enter value to search: ";
    cin >> searchValue;

    list.linearSearch(searchValue);

    return 0;
}




