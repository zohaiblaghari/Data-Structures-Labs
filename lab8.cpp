#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front; 
    Node* rear;  

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(); 
        newNode->data = value;     
        newNode->next = nullptr;   

        if (rear == nullptr) { 
            front = rear = newNode; 
        } else {
            rear->next = newNode; 
            rear = newNode;       
        }
        cout << value << " Inserted in the Queue.\n";
    }

    void dequeue() {
        if (front == nullptr) { 
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;    
        front = front->next;  
        cout << temp->data << " Delelted from the Queue.\n";
        delete temp;           

        if (front == nullptr) { 
            rear = nullptr;    
        }
    }

    void display() {
        if (front == nullptr) { 
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;
        cout << "Complete Queue is: ";
        while (temp != nullptr) { 
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    Queue q;


    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);


    q.display();


    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    return 0;
}