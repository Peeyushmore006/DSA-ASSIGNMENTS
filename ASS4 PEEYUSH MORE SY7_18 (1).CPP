#include <iostream>
using namespace std;

// Structure to represent a node of the binary tree
struct Node {
    int data;       // Stores the value of the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to create a binary tree recursively
Node* createTree() {
    int value;

    // Take input from the user
    cout << "Enter value (-1 for no node): ";
    cin >> value;

    // If user enters -1, there is no node
    if (value == -1) {
        return nullptr;
    }

    // Create a new node
    Node* root = new Node(value);

    // Create the left subtree
    cout << "Enter left child of " << value << endl;
    root->left = createTree();

    // Create the right subtree
    cout << "Enter right child of " << value << endl;
    root->right = createTree();

    // Return the created node
    return root;
}

// Function for Inorder Traversal
// Order: Left -> Root -> Right
void inorder(Node* root) {

    // Base condition: if tree is empty
    if (root == nullptr) {
        return;
    }

    // Visit left subtree
    inorder(root->left);

    // Visit root node
    cout << root->data << " ";

    // Visit right subtree
    inorder(root->right);
}

// Function for Preorder Traversal
// Order: Root -> Left -> Right
void preorder(Node* root) {

    // Base condition: if tree is empty
    if (root == nullptr) {
        return;
    }

    // Visit root node first
    cout << root->data << " ";

    // Visit left subtree
    preorder(root->left);

    // Visit right subtree
    preorder(root->right);
}

// Function for Postorder Traversal
// Order: Left -> Right -> Root
void postorder(Node* root) {

    // Base condition: if tree is empty
    if (root == nullptr) {
        return;
    }

    // Visit left subtree
    postorder(root->left);

    // Visit right subtree
    postorder(root->right);

    // Visit root node last
    cout << root->data << " ";
}

// Main function
int main() {

    // Create the binary tree
    cout << "===== CREATE BINARY TREE =====" << endl;
    Node* root = createTree();

    // Perform Inorder Traversal
    cout << "\n===== INORDER TRAVERSAL =====" << endl;
    cout << "Left -> Root -> Right" << endl;
    inorder(root);

    // Perform Preorder Traversal
    cout << "\n\n===== PREORDER TRAVERSAL =====" << endl;
    cout << "Root -> Left -> Right" << endl;
    preorder(root);

    // Perform Postorder Traversal
    cout << "\n\n===== POSTORDER TRAVERSAL =====" << endl;
    cout << "Left -> Right -> Root" << endl;
    postorder(root);

    cout << endl;

    return 0;
}


//------------------------------------------------- OUTPUT -------------------------------------------------//
/*peeyushmore@Peeyushs-MacBook DSA CLASSROOM % cd "/Users/peeyushmore/Python.app/DSA CLASSROOM/" && g++ PRACT4.CPP -o PRACT4 && "/Users/peeyushmore/Python.app/DSA CLASSROOM/"P
RACT4
===== CREATE BINARY TREE =====
Enter value (-1 for no node): 1
Enter left child of 1
Enter value (-1 for no node): 2
Enter left child of 2
Enter value (-1 for no node): 4
Enter left child of 4
Enter value (-1 for no node): 5
Enter left child of 5
Enter value (-1 for no node): 3
Enter left child of 3
Enter value (-1 for no node): 
*/