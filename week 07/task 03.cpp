
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find the smallest node in a subtree
Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: Only right child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: Only left child
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inOrder(Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Original BST: ";
    inOrder(root);

    int key;
    cout << "\nEnter value to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "BST after deletion: ";
    inOrder(root);

    cout << endl;
    return 0;
}

