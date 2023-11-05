#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

void enqueue(queue<int> &q, int data)
{
    q.push(data);
}
int dequeue(queue<int> &q)
{
    int data = q.front();
    q.pop();
    return data;
}

void qTraversal(queue<int> &q)
{
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
}
int main()
{
    queue<int> q;
    enqueue(q, 25);
    enqueue(q, 23);
    enqueue(q, 24);
    enqueue(q, 26);
    cout << q.size() << endl; // Gives size of the queue (4)
    int data = dequeue(q);
    cout << data << endl;     // Gives first element of the queue
    cout << q.back() << endl; // Gives last element of the queue
    cout << q.size() << endl; // Gives size of the queue (3)
    // qTraversal(q);

    return 0;
}