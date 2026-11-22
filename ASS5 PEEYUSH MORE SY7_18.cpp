#include <iostream>
using namespace std;


// Structure for one node of the Binary Search Tree
struct Node
{
    int data;           // Stores student roll number
    Node* left;         // Pointer to left child
    Node* right;        // Pointer to right child
};


// Maximum size of stack
#define MAX 100


// Stack implementation using array
Node* stack[MAX];
int top = -1;


// Function to push a node into the stack
void push(Node* node)
{
    // Check if stack is full
    if (top == MAX - 1)
    {
        cout << "Stack Overflow!" << endl;
        return;
    }

    top++;              // Move top to next position

    stack[top] = node;  // Store node in stack
}


// Function to pop a node from the stack
Node* pop()
{
    // Check if stack is empty
    if (top == -1)
    {
        return NULL;
    }

    Node* node = stack[top];    // Store top node

    top--;                      // Remove top node

    return node;
}


// Function to create a new BST node
Node* createNode(int value)
{
    Node* newNode = new Node;

    newNode->data = value;      // Store roll number

    newNode->left = NULL;       // Initially no left child

    newNode->right = NULL;      // Initially no right child

    return newNode;
}


// Function to insert a roll number into BST
Node* insert(Node* root, int value)
{
    // If tree is empty, create a new node
    if (root == NULL)
    {
        return createNode(value);
    }


    // If value is smaller, insert into left subtree
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }


    // If value is greater, insert into right subtree
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }


    // Return the root of the tree
    return root;
}


// Non-recursive Inorder Traversal
// Order: LEFT -> ROOT -> RIGHT
void inorder(Node* root)
{
    Node* current = root;

    // Continue while there is a node to process
    while (current != NULL || top != -1)
    {
        // Go to the leftmost node
        while (current != NULL)
        {
            push(current);          // Store node in stack

            current = current->left; // Move to left child
        }


        // Take the top node from stack
        current = pop();

        // Display the node
        cout << current->data << " ";


        // Move to right subtree
        current = current->right;
    }
}


// Non-recursive Preorder Traversal
// Order: ROOT -> LEFT -> RIGHT
void preorder(Node* root)
{
    // If tree is empty
    if (root == NULL)
    {
        return;
    }


    // Push root node into stack
    push(root);


    // Continue until stack becomes empty
    while (top != -1)
    {
        // Remove node from stack
        Node* current = pop();


        // Display the node
        cout << current->data << " ";


        // Push right child first
        // because left child must be processed first
        if (current->right != NULL)
        {
            push(current->right);
        }


        // Push left child
        if (current->left != NULL)
        {
            push(current->left);
        }
    }
}


// Main function
int main()
{
    Node* root = NULL;      // Initially BST is empty

    int n, value;


    // Ask number of students
    cout << "Enter number of students: ";
    cin >> n;


    // Insert student roll numbers
    cout << "Enter student roll numbers:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        root = insert(root, value);
    }


    // Inorder Traversal
    cout << "\nInorder Traversal: ";
    
    // Reset stack before traversal
    top = -1;

    inorder(root);


    // Preorder Traversal
    cout << "\nPreorder Traversal: ";

    // Reset stack before traversal
    top = -1;

    preorder(root);


    cout << endl;

    return 0;
}


//  -----------------------------OUTPUT------------------------------------------------------------------- //


//   Enter number of students: 3
Enter student roll numbers:
2
3
4

Inorder Traversal: 2 3 4 
Preorder Traversal: 2 3 4 

     //