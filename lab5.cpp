#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int getCount(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    Node* head = nullptr;

    head = new Node{10, new Node{15, new Node{20, new Node{25, new Node{30, nullptr}}}}};

    int count = getCount(head);
    cout << "Number of nodes in the linked list: " << count << endl;

    return 0;
} 




//Q2
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node** head_ref, int new_data) {
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout<<"The Value to Insert at Beginning Is:- " << node->data << " ""\n";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtBeginning(&head, 10);

    insertAtBeginning(&head, 20);

    insertAtBeginning(&head, 30);

    printList(head);

    return 0;
}




//Q3
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at a given position in a linked list
void insertAtPosition(Node** head_ref, int position, int new_data) {
    if (position < 0) {
        cout << "Invalid position" << endl;
        return;
    }

    // Create a new node
    Node* new_node = new Node();
    new_node->data = new_data;

    // If position is 0, insert at the beginning
    if (position == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    // Find the node before the position
    Node* prev = *head_ref;
    for (int i = 0; i < position - 1; i++) {
        if (prev == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        prev = prev->next;
    }

    // Insert the new node after the prev node
    new_node->next = prev->next;
    prev->next = new_node;
}

// Function to print linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << "Value To Insert Is: "<< node->data << " ""\n";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert 10, 20, and 30 at the beginning
    insertAtPosition(&head, 0, 10);
    insertAtPosition(&head, 0, 20);
    insertAtPosition(&head, 0, 30);

    // Insert 40 at position 2
    insertAtPosition(&head, 2, 40);

    printList(head);

    return 0;
}



//Q4
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};


int findLastLocation(Node* head) {
    int location = 1;
    Node* current = head;

    while (current != nullptr) {
        location++;
        current = current->next;
    }

    return location - 1; 
}

int main() {
    Node* head = nullptr;

    head = new Node{1, new Node{3, new Node{5, new Node{6, new Node{7, nullptr}}}}};

    int lastLocation = findLastLocation(head);
    cout << "Location of the last node is: " << lastLocation << endl;

    return 0;
}






//Q5
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};


void deleteNode(Node** head_ref, int key) {

    if (*head_ref == nullptr)
        return;


    if ((*head_ref)->data == key) {
        Node* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        delete temp;
        return;
    }


    Node* prev = *head_ref;
    while (prev->next != nullptr && prev->next->data != key)
        prev = prev->next;


    if (prev->next == nullptr)
        return;


    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    head = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, nullptr}}}}};

    cout << "Original Linked List: ";
    printList(head);

    deleteNode(&head, 3);

    cout << "Linked List after deletion of 3: ";
    printList(head);

    return 0;
}