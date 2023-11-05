#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
} *top = nullptr;

bool isEmpty(Node *top)
{
    return top == nullptr ? true : false;
}
bool isFull()
{
    Node *temp = new Node;
    return temp == nullptr ? true : false;
}
Node *push(Node *top, int data)
{
    if (isFull())
    {
        cout << "Stack is overflow";
        return top;
    }
    Node *temp = new Node;
    temp->data = data;
    if (top == nullptr)
    {
        temp->next = nullptr;
    }
    else
    {
        temp->next = top;
    }
    return temp;
}

int popp(Node *tp)
{
    if (isEmpty(tp))
    {
        cout << "Stack is underflow (empty)";
        return 0;
    }
    else
    {
        Node *temp = tp;
        int x = temp->data;
        top = top->next;
        free(temp);
        return x;
    }
}
void LinkedListTraversal(Node *top)
{
    while (top != nullptr)
    {
        cout << "Element is " << top->data << endl;
        top = top->next;
    }
}

int main()
{
    top = push(top, 21);
    top = push(top, 20);
    LinkedListTraversal(top);
    int popped = popp(top);
    popped = popp(top);
    popped = popp(top);
    cout << "popped is  " << popped << endl;
    cout << "After " << endl;
    LinkedListTraversal(top);

    return 0;
}
