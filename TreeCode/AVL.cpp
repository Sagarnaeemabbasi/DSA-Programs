#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct AVLNode
{
    int data;
    int height;
    AVLNode *left;
    AVLNode *right;

} *root = nullptr;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(AVLNode *rt)
{
    if (rt == nullptr)
        return 0;
    return rt->height;
}

AVLNode *NewNode(int data)
{
    AVLNode *temp = new AVLNode;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->height = 1;
    return temp;
}
int getBalancedFactor(AVLNode *node)
{
    if (node == nullptr)
        return 0;
    return (getHeight(node->left) - getHeight(node->right));
}

AVLNode *LeftRotation(AVLNode *rt)
{
    AVLNode *rightNode = rt->right;
    AVLNode *leftNode = rightNode->left;

    rightNode->left = rt;
    rt->right = leftNode;

    rt->height = 1 + max(getHeight(rt->left), getHeight(rt->right));
    rightNode->height = 1 + max(getHeight(rightNode->left), getHeight(rightNode->right));

    return rightNode;
}
AVLNode *RightRotation(AVLNode *rt)
{

    AVLNode *leftTemp = rt->left;
    AVLNode *rightTemp = leftTemp->right;

    leftTemp->right = rt;
    rt->left = rightTemp;

    rt->height = 1 + max(getHeight(rt->left), getHeight(rt->right));
    leftTemp->height = 1 + max(getHeight(leftTemp->left), getHeight(leftTemp->right));

    return leftTemp;
}

AVLNode *InsertIntoAVL(AVLNode *rt, int data)
{
    if (rt == nullptr)
        return (NewNode(data));
    if (rt->data > data)
        rt->left = InsertIntoAVL(rt->left, data);

    else if (rt->data < data)
        rt->right = InsertIntoAVL(rt->right, data);
    else
        return rt;

    rt->height = 1 + max(getHeight(rt->left), getHeight(rt->right));
    int balanced = getBalancedFactor(rt);
    if (balanced < -1 && rt->right->data < data) // LL
    {
        rt = LeftRotation(rt);
    }
    else if (balanced < -1 && rt->right->data > data) // LR
    {
        rt->right = RightRotation(rt->right);
        rt = LeftRotation(rt);
    }
    if (balanced > 1 && rt->left->data > data) // RR
    {
        rt = RightRotation(rt);
    }
    else if (balanced > 1 && rt->left->data < data) // RL
    {
        rt->left = LeftRotation(rt->left);
        rt = RightRotation(rt);
    }
    return rt;
}

AVLNode *SearchANode(AVLNode *rt, int data)
{
    if (rt == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (rt->data == data)
        {
            return rt;
        }
        if (rt->data > data)
        {
            cout << "Search into left" << endl;
            rt = SearchANode(rt->left, data);
        }
        else if (rt->data < data)
        {
            cout << "Search into right" << endl;
            rt = SearchANode(rt->right, data);
        }
    }
}
void PreOrder(AVLNode *rt)
{
    if (rt != nullptr)
    {
        cout << "Data is " << rt->data << endl;
        PreOrder(rt->left);
        PreOrder(rt->right);
    }
}
AVLNode *getSmallestInRight(AVLNode *rt)
{
    AVLNode *temp = rt;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}

AVLNode *DeleteANode(AVLNode *rt, int data)
{
    if (rt == nullptr)
    {
        return nullptr;
    }
    AVLNode *temp = rt;
    if (rt->data > data)
    {
        rt->left = DeleteANode(rt->left, data);
    }
    else if (rt->data < data)
    {
        rt->right = DeleteANode(rt->right, data);
    }
    else
    {
        if (rt->data == data)
        {
            if (rt->right == nullptr)
            {
                /// Handle for one child
                temp = rt->left;
                cout << "ASt this ++>" << rt->data << endl;
                free(rt);
                return temp;
            }
            else if (rt->left == nullptr)
            {
                // Handle for one child
                temp = rt->right;
                free(rt);
                return temp;
            }
            else
        {
                temp = getSmallestInRight(rt->right);
                rt->data = temp->data;
                rt->right = DeleteANode(rt->right, temp->data);
                return rt;
            }
        }

        rt->height = 1 + max(getHeight(rt->left), getHeight(rt->right));

        int balanced = getBalancedFactor(rt);
        if (balanced < -1 && rt->right->data < data) // LL
        {
            rt = LeftRotation(rt);
        }
        else if (balanced < -1 && rt->right->data > data) // LR
        {
            rt->right = RightRotation(rt->right);
            rt = LeftRotation(rt);
        }
        if (balanced > 1 && rt->left->data > data) // RR
        {
            rt = RightRotation(rt);
        }
        else if (balanced > 1 && rt->left->data < data) // RL
        {
            rt->left = LeftRotation(rt->left);
            rt = RightRotation(rt);
        }
        return rt;
    }
    return rt;
}

int main()
{
    root = InsertIntoAVL(root, 155);
    root = InsertIntoAVL(root, 111);
    root = InsertIntoAVL(root, 100);
    root = InsertIntoAVL(root, 125);
    root = InsertIntoAVL(root, 54);
    root = InsertIntoAVL(root, 190);
    root = InsertIntoAVL(root, 200);
    root = InsertIntoAVL(root, 210);
    root = InsertIntoAVL(root, 220);
    PreOrder(root);
    root = DeleteANode(root, 200);
    // root = DeleteANode(root, 220);
    cout << "After" << endl;
    PreOrder(root);

    return 0;
}