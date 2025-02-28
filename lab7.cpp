#include<iostream>
#include<stack>
using namespace std;

struct Node {
    int data;
    Node* next;
};


class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }


    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Can't Perform pop!.." << endl;
            return -1;
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }


    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }


    bool isEmpty() {
        return top == nullptr;
    }


    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

	int y;
    int x;
    int i=0;

    while(i<5){

		cout <<"What Do You Want Do(Push or Pop or Peek) To Enter Numbers(1,2,3) sequentialy to perform operations:\n";
    	cin>>x;


    	if (x==1){
    		cout<<"Enter Number You Wnat to Push:";
    		cin>>y;
    		stack.push(y);
    		stack.display();
		}else if(x==2){
			cout << "Popped element: " << stack.pop() << endl;
			stack.display();
		}else if(x==3){
		    cout << "Top element: " << stack.peek() << endl;
		    stack.display();
		}else{
			cout<<"Wrong Input!!\n";
		}
		i++; 	
	}




    return 0;
}





//Q3
@@ -0,0 +1,67 @@
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); 
        } else if (isOperator(c)) {
            while (!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Changed Into Postfix expression: " << postfix << endl;

    return 0;
}
