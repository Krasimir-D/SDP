// bst.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int _key) : key(_key), left(nullptr), right(nullptr) {}
};

Node* find(Node* root, int key)
{
    if (!root)
    {
        return nullptr;
    }
    if (root->key>key)
    {
        return find(root->left, key);
    }
    if (root->key < key)
    {
        return find(root->right, key);
    }
    return root;
}

Node* insert(Node* root, int key)
{
    if (!root)
    {
        return new Node(key);
    }
    if (root->key > key)
    {
        root->left = insert(root->left, key);
    }
    if (root->key < key)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* getMax(Node* root)
{
    if (!root)
    {
        return nullptr;
    }
    if (!root->right)
    {
        return root;
    }
    return getMax(root->right);
}

Node* getMin(Node* root)
{
    if (!root)
    {
        return nullptr;
    }
    if (!root->left)
    {
        return root;
    }
    return getMin(root->left);
}

Node* remove(Node* root, int key)
{
    if (!root)
    {
        return nullptr;
    }
    if (root->key > key)
    {
        root->left = remove(root->left, key);
    }
    if (root->key < key)
    {
        root->right = remove(root->right, key);
    }
    else if (!root->left && !root->right)
    {
        delete root;
        return nullptr;
    }
    else if (!root->right)    
    {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    else if (!root->left) 
    {
        Node* temp = root->right;
        delete root;
        return temp;
    }
}

Node* section(const Node*, const Node*);
bool areCousins(const Node*, int, int);
int LCA(const Node*, int, int);

int main()
{
    std::cout << "Hello World!\n";
}


