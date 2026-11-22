#include <iostream>
using namespace std;

// Node structure representing a single book ID in the list
struct Node {
    int data;      // Stores the value (Book ID)
    Node* next;    // Pointer to next node
};

class LinkedList {
private:
    Node* head;    // head pointer, initially list is empty

public:
    // Constructor - initializes an empty list
    LinkedList() {
        head = NULL;
    }

    // 1. Insert a new book ID at the BEGINNING of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();   // create a new node
        newNode->data = value;        // set its data
        newNode->next = head;         // link it to the current head
        head = newNode;               // make the new node the head
        cout << "Book ID " << value << " inserted at beginning.\n";
    }

    // 2. Insert a new book ID at the END of the list
    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;         // last node points to NULL

        if (head == NULL) {              // if list is empty, new node becomes head
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) { // traverse to the last node
                temp = temp->next;
            }
            temp->next = newNode;        // link last node to new node
        }
        cout << "Book ID " << value << " inserted at end.\n";
    }

    // 3. Delete the book ID from the BEGINNING of the list
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "\nLinked List is Empty. Nothing to delete.\n";
            return;
        }
        Node* temp = head;            // temp holds the node to be deleted
        head = head->next;            // move head to the next node
        cout << "Book ID " << temp->data << " deleted from beginning.\n";
        delete temp;                  // free the memory
    }

    // 4. Display all book IDs in the list
    void display() {
        if (head == NULL) {
            cout << "\nLinked List is Empty.\n";
        } else {
            Node* temp = head;
            cout << "\nLinked List : ";
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

// Main function to test the operations using a menu
int main() {
    LinkedList list;
    int choice, id;

    do {
        cout << "\n----- Library Book ID List -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                list.insertAtBeginning(id);
                break;
            case 2:
                cout << "Enter Book ID: ";
                cin >> id;
                list.insertEnd(id);
                break;
            case 3:
                list.deleteFromBeginning();
                break;
            case 4:
                list.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}