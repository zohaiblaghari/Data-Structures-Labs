#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertAtBeginning(Node** head_ref, int new_data) {
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;


    (*head_ref) = new_node;
}


void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {

    Node* head = NULL;


    insertAtBeginning(&head, 50);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    cout << "Created Doubly Linked List: ";
    printList(head);

    return 0;
}




//Q2
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertBefore(Node** head_ref, Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = prev_node;
    new_node->prev = prev_node->prev;

    if (prev_node->prev != NULL)
        prev_node->prev->next = new_node;

    prev_node->prev = new_node;

    if (prev_node == *head_ref)
        (*head_ref) = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    head = second;
    second->data = 10;

    second->next = third;
    third->data = 20;

    third->next = fourth;
    fourth->data = 30;

    fourth->next = fifth;
    fifth->data = 40;

    fifth->next = NULL;

    insertBefore(&head, fourth, 35);

    cout << "Modified Linked List: ";
    printList(head);

    return 0;
}




//Q3
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertAtEnd(Node** head_ref, int new_data) {
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;

    new_node->prev = last;

    return;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    cout << "Created Doubly Linked List: ";
    printList(head);

    return 0;
}




//Q4
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void deleteNode(Node** head_ref, Node* node) {
    if (*head_ref == node) {
        *head_ref = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    if (node->prev != NULL) {
        node->prev->next = node->next;
    }

    free(node);
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    head = second;
    second->data = 10;

    second->next = third;
    third->data = 20;

    third->next = fourth;
    fourth->data = 30;

    fourth->next = fifth;
    fifth->data = 40;

    fifth->next = NULL;

    deleteNode(&head, third);

    cout << "Modified Linked List: ";
    printList(head);

    return 0;
}




//Q5
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void reverseDoublyLinkedList(Node** head_ref) {
    Node* temp = NULL;
    Node* current = *head_ref;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head_ref = temp->prev;
    }
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    head = second;
    second->data = 10;

    second->next = third;
    third->data = 20;

    third->next = fourth;
    fourth->data = 30;

    fourth->next = fifth;
    fifth->data = 40;

    fifth->next = NULL;

    cout << "Original Linked List: ";
    printList(head);

    reverseDoublyLinkedList(&head);

    cout << "\nReversed Linked List: ";
    printList(head);

    return 0;
}