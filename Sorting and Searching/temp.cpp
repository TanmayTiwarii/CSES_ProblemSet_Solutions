#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to append a new node at the end
Node* appendToTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

// Function to subtract two linked lists
Node* subtractLists(Node* l1, Node* l2) {
    Node* result = nullptr;
    Node *p1 = l1, *p2 = l2;
    int borrow = 0;

    while (p1 || p2) {
        int num1 = (p1) ? p1->data : 0;
        int num2 = (p2) ? p2->data : 0;

        // Subtract digits and handle borrow
        int diff = num1 - num2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result = appendToTail(result, diff);

        // Move to the next digits
        if (p1) p1 = p1->next;
        if (p2) p2 = p2->next;
    }

    // Remove leading zeros
    while (result && result->data == 0) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return result ? result : new Node(0); // Return 0 if result is empty
}

// Function to create a linked list from user input
Node* createListFromInput() {
    Node* head = nullptr;
    cout << "Enter digits one by one (enter -1 to stop):" << endl;
    while (true) {
        int digit;
        cin >> digit;
        if (digit == -1) break;
        if (digit < 0 || digit > 9) {
            cout << "Please enter a valid digit (0-9):" << endl;
            continue;
        }
        head = appendToTail(head, digit);
    }
    return head;
}

// Main function
int main() {
    cout << "Enter first number as linked list:" << endl;
    Node* l1 = createListFromInput();

    cout << "Enter second number as linked list:" << endl;
    Node* l2 = createListFromInput();

    Node* result = subtractLists(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}