#ifndef MERKLE_H
#define MERKLE_H
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <map>
#include "../src/utils/md5.h"

using namespace std;

/*
 * Node class decleration, using templating we can use any component class that has a getHash
 * function.
*/

template <class T>
class Node
{
public:
    virtual string getHash() { return this->hash; }
    string makeHash(Node<T> *leftNode, Node<T> *rightNode)
    {
        string concatedHashes = "";
        concatedHashes.append(leftNode->hash);
        concatedHashes.append(rightNode->hash);
        return md5(concatedHashes);
    }

    string makeHash(T* content)
    {
        return md5(to_string(content->getHash()));
    }

    ~Node() {}

    string hash;
    bool isLeaf;
    Node<T> *parentNode;
};

/*
 * Derived class of Node, this one sits at the top and middle of the tree 
*/

template <class T>
class MerkleNode : public Node<T>
{
    
public:
    Node<T> *leftNode;
    Node<T> *rightNode;  
    MerkleNode(Node<T> *leftNode, Node<T> *rightNode, Node<T> *parentNode)
    {
        this->leftNode = leftNode;
        this->rightNode = rightNode;
        this->parentNode = parentNode;
        this->hash = this->makeHash(leftNode, rightNode);
        this->isLeaf = false;
    }

    ~MerkleNode() {}
};

/**
 * LeafNode class that derives from Node class, this represents the leaf of the tree where the components rest.
*/

template <class T>
class MerkleLeaf : public Node<T>
{
public:
    T* content;

    MerkleLeaf(T *content, Node<T> *parentNode)
    {
        this->content = content;
        this->hash = content->getHash();
        this->isLeaf = true;
        this->parentNode = parentNode;
    }

    ~MerkleLeaf() {}

    void updateTree() {
        if (this->hash == content->getHash()) {
            cout << "No changes detected" << endl;
            return;
        }
        updateTree(this);
    }

private:
    void updateTree(Node<T> *node) {
        if (node == nullptr) {
            return;
        }
        if (node->isLeaf) {
            MerkleLeaf<T> *leaf = dynamic_cast<MerkleLeaf<T>*>(node);
            node->hash = leaf->content->getHash();
        } else {
            MerkleNode<T> *node_ptr = dynamic_cast<MerkleNode<T>*>(node);
            node->hash = node->makeHash(node_ptr->leftNode, node_ptr->rightNode);
        }
        updateTree(node->parentNode);
    }
};

/**
 * Merkle Tree definition. 
*/
template <class T>
class MerkleTree
{
    

    Node<T> *makeMerkleRoot(vector<T*> numbers)
    {
        int numIter = numbers.size();
        int depth = ceil(log2(numbers.size()));
        vector<Node<T>*> children;
        for (auto num : numbers)
        {
            MerkleLeaf<T>* m = new MerkleLeaf<T>(num, nullptr);
            this->leafMap.insert_or_assign(m->hash, m);
            children.insert(children.end(), m);
        }
        for (int i = 0; i < depth; i++)
        {
            vector<Node<T>*> newChildren;
            for (int j = 0; j < numIter; j += 2)
            {
                if (j + 1 == numIter)
                {
                    MerkleNode<T> *m = new MerkleNode<T>(children[j], children[j], nullptr);
                    children[j]->parentNode = m;
                    newChildren.insert(newChildren.end(), m);
                    break;
                }
                MerkleNode<T> *m = new MerkleNode<T>(children[j], children[j+1], nullptr);
                children[j]->parentNode = m;
                children[j+1]->parentNode = m;
                newChildren.insert(newChildren.end(), m);
            }
            children.clear();
            children = newChildren;
            numIter = numIter / 2 + (numIter > 1 ? numIter % 2 : 0);
        }
        return children[0];
    }

    void preOrderPrint(Node<T> *node)
    {

        if (node->isLeaf)
        {
            MerkleLeaf<T> *leaf = dynamic_cast<MerkleLeaf<T>*>(node);
            cout << "leaf content: " << leaf->content->getString() << endl;
            return;
        }
        cout << node->getHash() << endl;
        MerkleNode<T> *node_ptr = dynamic_cast<MerkleNode<T>*>(node);
        preOrderPrint(node_ptr->leftNode);
        preOrderPrint(node_ptr->rightNode);
    }

    void clearTree(Node<T>* node) {
        if (!node->isLeaf) {
            MerkleNode<T> *node_ptr = dynamic_cast<MerkleNode<T>*>(node);
            if (node_ptr->leftNode != node_ptr->rightNode) {
                clearTree(node_ptr->leftNode);
                clearTree(node_ptr->rightNode);
            } else {
                clearTree(node_ptr->leftNode);
            }
            delete(node_ptr);
        } else {
            MerkleLeaf<T> *leaf = dynamic_cast<MerkleLeaf<T>*>(node);
            delete(leaf);
        }
    }

public:

    Node<T> *root;
    string hash;

    map<string, MerkleLeaf<T>*> leafMap;

    MerkleTree(vector<T*> numbers)
    {
        Node<T> *root = makeMerkleRoot(numbers);
        this->root = root;
        this->hash = root->getHash();
    }

    string getHash()
    {
        return this->hash;
    }

    void preOrderPrint()
    {
        preOrderPrint(this->root);
    }
 
    void clearTree() {
        clearTree(this->root);
    }

    void updateHash() {
        this->hash = this->root->getHash();
    }

};

#endif