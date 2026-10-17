
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

// Preorder: Node, Right, Left (NRL)
void preOrderNRL(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrderNRL(root->right);
    preOrderNRL(root->left);
}

// Postorder: Right, Left, Node (RLN)
void postOrderRLN(Node* root) {
    if (root == NULL)
        return;

    postOrderRLN(root->right);
    postOrderRLN(root->left);
    cout << root->data << " ";
}

// Inorder: Right, Node, Left (RNL)
void inOrderRNL(Node* root) {
    if (root == NULL)
        return;

    inOrderRNL(root->right);
    cout << root->data << " ";
    inOrderRNL(root->left);
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

    cout << "Preorder (NRL): ";
    preOrderNRL(root);

    cout << "\nPostorder (RLN): ";
    postOrderRLN(root);

    cout << "\nInorder (RNL): ";
    inOrderRNL(root);

    return 0;
}

