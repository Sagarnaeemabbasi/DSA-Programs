#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

struct Vertex
{
    int data;
    struct Edge *edgeList;
    bool visited;
} *startVertex = nullptr;

struct Edge
{
    Vertex *toVertex;
    Edge *next;
};

Vertex *insertVertex(int data)
{
    Vertex *temp = new Vertex;
    temp->data = data;
    temp->edgeList = nullptr;
    temp->visited = false;
    if (startVertex == nullptr)
    {
        startVertex = temp;
    }
    return temp;
}

void enqueue(queue<Vertex *> &q, Vertex *tm)
{
    q.push(tm);
}
Vertex *dequeue(queue<Vertex *> &q)
{
    Vertex *temp = q.front();
    q.pop();
    return temp;
}

Vertex *searchNode(int data)
{
    Vertex *temp = startVertex;
    if (temp->data == data)
        return temp;
    while (temp->edgeList->next != nullptr)
    {
        temp = temp->edgeList->toVertex;
    }
    return temp;
}
void BFSTraversal(Vertex *sVertex)
{
    cout << "BFS starts from " << sVertex->data << " :";
    queue<Vertex *> q;
    sVertex->visited = true;
    enqueue(q, sVertex);
    while (!q.empty())
    {
        Vertex *currentVertex = dequeue(q);
        cout << currentVertex->data << " ";
        Edge *temp = currentVertex->edgeList;
        while (temp != nullptr)
        {
            Vertex *neighbour = temp->toVertex;
            if (!neighbour->visited)
            {
                neighbour->visited = true;
                enqueue(q, neighbour);
            }
            temp = temp->next;
        }
    }
}

void insertEdge(Vertex *from, Vertex *to)
{
    Edge *newEdge = new Edge;
    newEdge->toVertex = to;
    newEdge->next = nullptr;
    if (from->edgeList == nullptr)
    {
        from->edgeList = newEdge;
    }
    else
    {
        Edge *temp = from->edgeList;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newEdge;
    }
}

int main()
{
    Vertex *v1 = insertVertex(1);
    Vertex *v2 = insertVertex(2);
    Vertex *v3 = insertVertex(3);
    Vertex *v4 = insertVertex(4);
    Vertex *v5 = insertVertex(5);
    Vertex *v6 = insertVertex(6);
    Vertex *v7 = insertVertex(7);

    insertEdge(v1, v2);
    insertEdge(v1, v3);
    insertEdge(v2, v3);
    insertEdge(v2, v4);
    insertEdge(v3, v4);
    insertEdge(v4, v5);
    insertEdge(v4, v6);
    insertEdge(v3, v7);

    BFSTraversal(v1);
    return 0;
}