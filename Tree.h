#pragma once

#include "Node.h"  // Include Node definition
#include <string>  // Include string for the tree to handle strings
#include  "Users.h"
using namespace std;
class Tree {
private:
    Node< string>* Root;  // Pointer to the root node of the tree
public:
    // Helper methods
    int Height(Node< string>* P);
    int BalanceFactor(Node< string>* P);
    Node< string>* RightRotate(Node< string>* y);
    Node< string>* LeftRotate(Node< string>* x);
    Node< string>* InsertRecursive(Node< string>* current, const  string& str);
    void DeleteTree(Node< string>* node);
    void PreOrder(Node< string>* P) const;
    bool Search(Node<string>* P, string key);
    Tree();
    ~Tree();
    Node< string>* GetRoot() const;
    void Insert(const  string& str);
};
