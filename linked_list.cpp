#include <iostream>
using namespace std;

// Node = one box that holds a number and a pointer to next box
class Node {
public:
    int data;       // The number stored in this box
    Node* next;     // Arrow pointing to next box
    
    // When we create a new box, we put a number in it
    Node(int value) {
        data = value;    // Store the number
        next = NULL;     // Arrow points to nothing (NULL means empty)
    }
};

// LinkedList = chain of boxes connected by arrows
class LinkedList {
private:
    Node* head;    // Points to the first box
    Node* tail;    // Points to the last box
    
public:
    // Constructor - creates empty chain
    LinkedList() {
        head = NULL;    // No first box yet
        tail = NULL;    // No last box yet
    }
    
    // Add a new box at the end of the chain
    void insert(int value) {
        // Make a new box with the number
        Node* newNode = new Node(value);
        
        // If chain is empty
        if (head == NULL) {
            head = newNode;    // New box becomes first box
            tail = newNode;    // New box becomes last box
        } 
        // If chain has boxes already
        else {
            tail->next = newNode;    // Last box points to new box
            tail = newNode;          // New box becomes the last box
        }
    }
    
    // Show all numbers in the chain
    void display() {
        // If no boxes in chain
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        
        // Start from first box and go to last box
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;      // Print the number in current box
            
            if (temp->next != NULL) {
                cout << " -> ";       // Print arrow between boxes
            }
            
            temp = temp->next;       // Move to next box
        }
        cout << endl;
    }
    
    // Clean up - delete all boxes when program ends
    ~LinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;    // Remember next box
            delete temp;                // Delete current box
            temp = next;                // Move to next box
        }
    }
};

int main() {
    LinkedList list;    // Create empty chain
    int value;          // Store user input number
    char choice;        // Store user's yes/no choice
    
    cout << "Enter elements for linked list:\n";
    
    // Keep asking for numbers until user says no
    do {
        cout << "Enter value: ";
        cin >> value;
        list.insert(value);    // Add number to chain
        
        cout << "Add more? (y/n): ";
        cin >> choice;
        
    } while (choice == 'y' || choice == 'Y');    // Continue if user says yes
    
    cout << "\n";
    list.display();    // Show all numbers in chain
    
    return 0;
}