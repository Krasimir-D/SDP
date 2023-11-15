// tree_exer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data) :
        data(data), left(nullptr), right(nullptr) {}
};

void cleanUp(Node* root)
{
    if (!root)
    {
        return;
    }
    cleanUp(root->left);
    cleanUp(root->right);
    delete root;
}

int countEl(Node* root)
{
    if (!root) 
    {
        return 0;
    }
    return countEl(root->left) + countEl(root->right) + 1;
}

int countLeafs(Node* root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return 1;
    }
    return countLeafs(root->left) + countLeafs(root->right);
}

int sumData(Node* root)
{
    if (!root)
    {
        return 0;
    }
    
    return sumData(root->left) + sumData(root->right) + root->data;
}

int sumAtLevel(Node* root, int level)
{
    if (!root)
    {
        return 0;
    }
    if (level == 0)
    {
        return root->data;
    }

    return sumAtLevel(root->left, level - 1) + sumAtLevel(root->right, level - 1);
}

int getHeight(Node* root)
{
    if (!root)
    {
        return 0;
    }

    int lH = getHeight(root->left);
    int rH = getHeight(root->right);

    return std::max(lH, rH) + 1;
}

bool isMirrorH(Node* l, Node* r)
{
    if (!l && !r)
        return true;

    if (!l && r || (!r &&l))
    {
        return false;
    }
    return ((l->data == r->data) && (isMirrorH(l->left, l->right) && isMirrorH(r->left, r->right)));

}

bool isMirror(Node* root)
{
    if (!root)
    {
        return true;
    }
    return isMirrorH(root->left, root->right);
}

void print(Node* root)
{
    if (!root)
    {
        return;
    }
    print(root->left);
    std::cout << root->data;
    print(root->right);
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(7);
    root->right = new Node(9);
    root->right->right = new Node(27);
}

