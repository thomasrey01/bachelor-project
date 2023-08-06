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

protected:
    string hash;
    bool isLeaf;
};

template <class T>
class MerkleNode : public Node<T>
{
    Node<T> leftNode;
    Node<T> rightNode;

public:
    MerkleNode(Node<T> leftNode, Node<T> rightNode)
    {
        this->leftNode = leftNode;
        this->rightNode = rightNode;
        this->hash = this->makeHash(leftNode, rightNode);
        this->isLeaf = false;
    }
};

template <class T>
class MerkleLeaf : public Node<T>
{
    T content;

public:
    MerkleLeaf(T content)
    {
        this->content = content;
        this->hash = md5(to_string(content));
        this->isLeaf = true;
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
        cout << "depth is " << depth << endl;
        vector<Node<T>> children;
        for (auto num : numbers)
        {
            MerkleLeaf m(num);

            children.insert(children.end(), m);
        }
        for (int i = 0; i < depth; i++)
        {
            vector<Node<T>> newChildren;
            for (int j = 0; j < numIter; j += 2)
            {
                if (j + 1 == numIter)
                {
                    MerkleNode m(children[j], children[j]);
                    newChildren.insert(newChildren.end(), m);
                }
                MerkleNode m(children[j], children[j + 1]);
                newChildren.insert(newChildren.end(), m);
            }
            children.clear();
            children = newChildren;
            numIter = numIter / 2 + (numIter > 1 ? numIter % 2 : 0);
        }
        cout << children.size() << endl;
        return children[0];
    }

public:
    MerkleTree(vector<T> numbers)
    {
        Node<T> root = makeMerkleRoot(numbers);
        this->root = root;
        this->hash = root.getHash();
    }

    string getHash() {
        return this->hash;
    }
};

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 13};
    MerkleTree tree(numbers);
    cout << tree.getHash() << endl;
}