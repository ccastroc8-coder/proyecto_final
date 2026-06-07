#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

struct StackNode {

    string action;
    StackNode* next;

    StackNode(string a) {

        action = a;
        next = nullptr;
    }
};

class Stack {

private:

    StackNode* top;

public:

    Stack() {

        top = nullptr;
    }

    void push(string action) {

        StackNode* newNode = new StackNode(action);

        newNode->next = top;
        top = newNode;
    }

    void display() {

        StackNode* temp = top;

        cout << "\n===== HISTORIAL =====\n";

        while(temp != nullptr) {

            cout << temp->action << endl;
            temp = temp->next;
        }
    }
};

#endif