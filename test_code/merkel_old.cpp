#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "../src/utils/md5.h"
#include "../src/components.h"

using namespace std;

/**
 * Template for merkel tree.
 * Child nodes can either be a merkel node or a leaf.
 * When it's a Merkel node, its children are other nodes, when it's a leaf
 * there are no children but instead an instance of an object. Either shelf or box
 */
template <class T, class S>
class MerkelNode
{
    T leftNode;
    S rightNode;
    string hash;
    bool isLeaf;

    MerkelNode()
    {
        isLeaf = false;
    }

    MerkelNode(T leftNode, S rightNode)
    {
        this->leftNode = leftNode;
        this->rightNode = rightNode;
        this->hash = makeHash(leftNode, rightNode);
        isLeaf = false;
    }

    string makeHash(T leftNode, S rightNode)
    {
        string concatedHashes = "";
        concatedHashes.append(leftNode.hash);
        concatedHashes.append(rightNode.hash);
        return md5(concatedHashes);
    }
};

template <class T>
class MerkelLeaf
{
    T content;
    string hash;
    bool isLeaf;

    MerkelLeaf(T content, string hash) {
        this->content = content;
        this->hash = hash;
    }
};

class MerkelTree
{
    MerkelNode root;
    string hash;

    MerkelTree(vector<int> numbers) {
        T res =  makeMerkelTree(numbers);
        this->root = res;
        this->hash = res.hash;
    }

    T makeMerkelRoot(vector<int> numbers)
    {
        int numIter = numbers.size();
        int depth = ceil(log2(numbers.size()));
        cout << "depth is " << depth << endl;
        vector<T> children;
        for (auto num : numbers) {
            MerkelLeaf m(num, md5(to_string(num)));
            
            children.append(m);
        }
        for (int i = 0; i < depth; i++)
        {
            vector<T> newChildren;
            for (int j = 0; j < numIter; j+=2)
            {
                if (j + 1 == numIter) {
                    MerkelNode m(children[j], children[j]);
                    newChildren.append(m);
                }
                MerkelNode m(children[j], children[j+1]);
                newChildren.append(m);
            }
            for (auto child : children) {
                if (child != nullptr) {
                    free(child);
                }
            }
            children.clear();
            children = newChildren;
            numIter = numIter / 2 + (numIter > 1 ? numIter % 2 : 0);
        }
        cout << children.size() << endl;
        return children[0];
    }
};

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5};
    MerkelTree tree(numbers);
    
}