#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
} *root = nullptr;

BSTNode *InsertIntoBST(BSTNode *rt, int data)
{
    if (rt == nullptr)
    {
        BSTNode *tem = new BSTNode;
        tem->data = data;
        tem->left = nullptr;
        tem->right = nullptr;
        return tem;
    }
    if (rt->data > data)
    {
        cout << "Insert into left" << endl;
        rt->left = InsertIntoBST(rt->left, data);
    }
    else if (rt->data < data)
    {
        cout << "Insert into right" << endl;

        rt->right = InsertIntoBST(rt->right, data);
    }
    return rt;
}

BSTNode *SearchANode(BSTNode *rt, int data)
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
void PreOrder(BSTNode *rt)
{
    if (rt != nullptr)
    {
        cout << "Data is " << rt->data << endl;
        PreOrder(rt->left);
        PreOrder(rt->right);
    }
}
BSTNode *getSmallestInRight(BSTNode *rt)
{
    BSTNode *temp = rt;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}
BSTNode *getGreatestInLeft(BSTNode *rt)
{
    BSTNode *temp = rt;
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp;
}

BSTNode *DeleteANode(BSTNode *rt, int data)
{
    if (rt == nullptr)
    {
        return nullptr;
    }
    BSTNode *temp = rt;
    if (rt->data > data)
    {
        temp = DeleteANode(rt->left, data);
    }
    else if (rt->data < data)
    {
        temp = DeleteANode(rt->right, data);
    }
    else
    {
        if (rt->data == data)
        {
            if (rt->right == nullptr)
            {
                /// Handle for one child
                temp = rt->left;
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
                // temp = getSmallestInRight(rt->right);
                // rt->data = temp->data;
                // rt->right = DeleteANode(rt->right, temp->data);
                temp = getGreatestInLeft(rt->left);
                rt->data = temp->data;
                rt->left = DeleteANode(rt->left, temp->data);
                return temp;
            }
        }
    }
    return rt;
}

int main()
{
    root = InsertIntoBST(root, 112);
    root = InsertIntoBST(root, 37);
    root = InsertIntoBST(root, 198);
    root = InsertIntoBST(root, 22);
    root = InsertIntoBST(root, 49);
    root = InsertIntoBST(root, 198);
    root = InsertIntoBST(root, 175);
    root = InsertIntoBST(root, 199);
    root = InsertIntoBST(root, 168);
    root = InsertIntoBST(root, 215);

    // BSTNode *searchedNode = SearchANode(root, 102);
    // if (searchedNode == nullptr)
    // {
    //     cout << "Not found" << endl;
    // }
    // else
    // {
    //     cout << "Node is found" << searchedNode->data << endl;
    // }
    PreOrder(root);
    // root = DeleteANode(root, 215);
    root = DeleteANode(root, 198);
    // BSTNode *deletedNode = DeleteANode(root, 215);
    // BSTNode *deletedNode = DeleteANode(root, 215);
    cout << "root" << root->data << endl;
    cout << "After" << endl;
    PreOrder(root);

    return 0;
}