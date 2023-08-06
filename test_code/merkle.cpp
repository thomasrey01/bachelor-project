#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "../src/utils/md5.h"
#include "../src/components.h"

using namespace std;

template <class T>
class Node
{
public:
    virtual string getHash() { return this->hash; }
    string makeHash(Node<T> leftNode, Node<T> rightNode)
    {
        string concatedHashes = "";
        concatedHashes.append(leftNode.hash);
        concatedHashes.append(rightNode.hash);
        return md5(concatedHashes);
    }

    string makeHash(T content)
    {
        return md5(to_string(content));
    }

    string hash;
    bool isLeaf;
    Node<T> *parentNode;
};

template <class T>
class MerkleNode : public Node<T>
{
    
public:
    Node<T> leftNode;
    Node<T> rightNode;  
    MerkleNode(Node<T> leftNode, Node<T> rightNode, Node<T> *parentNode)
    {
        this->leftNode = leftNode;
        this->rightNode = rightNode;
        this->parentNode = parentNode;
        this->hash = this->makeHash(leftNode, rightNode);
        this->isLeaf = false;
    }
};

template <class T>
class MerkleLeaf : public Node<T>
{
public:
    T content;

public:
    MerkleLeaf(T content, Node<T> *parentNode)
    {
        this->content = content;
        this->hash = md5(to_string(content));
        this->isLeaf = true;
        this->parentNode = parentNode;
    }
};

template <class T>
class MerkleTree
{
    Node<T> root;
    string hash;

    Node<T> makeMerkleRoot(vector<T> numbers)
    {
        int numIter = numbers.size();
        int depth = ceil(log2(numbers.size()));
        vector<Node<T>> children;
        for (auto num : numbers)
        {
            MerkleLeaf<T> m(num, nullptr);

            children.insert(children.end(), m);
        }
        for (int i = 0; i < depth; i++)
        {
            vector<Node<T>> newChildren;
            for (int j = 0; j < numIter; j += 2)
            {
                if (j + 1 == numIter)
                {
                    MerkleNode<T> m(children[j], children[j], nullptr);
                    children[i].parentNode = &m;
                    newChildren.insert(newChildren.end(), m);
                }
                MerkleNode<T> m(children[j], children[j + 1], nullptr);
                children[j].parentNode = &m;
                children[j+1].parentNode = &m;
                newChildren.insert(newChildren.end(), m);
            }
            children.clear();
            children = newChildren;
            numIter = numIter / 2 + (numIter > 1 ? numIter % 2 : 0);
        }
        return children[0];
    }

public:
    MerkleTree(vector<T> numbers)
    {
        Node<T> root = makeMerkleRoot(numbers);
        this->root = root;
        this->hash = root.getHash();
    }

    string getHash()
    {
        return this->hash;
    }

    void preOrderPrint(Node<T> node)
    {
        /*
         * This function doesn't work since dynamic casting always returns null.
         * This is likely because I am casting them to the wrong class.
         * TODO: Review and fix this stuff.
        */

        if (node.isLeaf)
        {
            MerkleLeaf<T> *leaf = dynamic_cast<MerkleLeaf<T>*>(&node);
            cout << "leaf content: " << leaf->content << endl;
            return;
        }
        cout << node.getHash() << endl;
        MerkleNode<T> *node_ptr = dynamic_cast<MerkleNode<T>*>(&node);
        preOrderPrint(node_ptr->leftNode);
        preOrderPrint(node_ptr->rightNode);
    }

    void preOrderPrint()
    {
        preOrderPrint(this->root);
    }
};

int main()
{
    vector<int> numbers = {1};
    MerkleTree tree(numbers);
    cout << tree.getHash() << endl;
    tree.preOrderPrint();
}