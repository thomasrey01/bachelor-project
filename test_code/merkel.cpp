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
template <class T>
class MerkelNode {
    T leftNode;
    T rightNode;
    string hash;
    bool isLeaf;

    MerkelNode() {
        isLeaf = false;
    }

    MerkelNode(T leftNode, T rightNode, string hash) {
        this->leftNode = leftNode;
        this->rightNode = rightNode;
        this->hash = makeHash(leftNode, rightNode);
        isLeaf = false;
    }

    string makeHash(T leftNode, T rightNode) {
        string concatedHashes = "";
        concatedHashes.append(leftNode.hash);
        concatedHashes.append(rightNode.hash);
        return md5(concatedHashes);
    }
};

template <class T>
class MerkelLeaf {
    T content;
    string hash;
    bool isLeaf;
};

template <class T>
class MerkelTree {
    T root;
    string hash;

    MerkelTree(T root) {
        this->root = root;
        this->hash = root.hash;       
    }


};

string getMerkelRoot(vector<int> numbers) {
    int numIter = numbers.size();
    int depth = ceil(log2(numbers.size()));
    cout << "depth is " << depth << endl;
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < numIter; j++) {
            // These iterations are correct to build the tree.
            // TODO: Define the tree
        }
        numIter = numIter / 2 + (numIter > 1 ? numIter % 2 : 0);
    }
    return "";
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    // string res = getMerkelRoot(numbers);
    string some = "2";
    cout << md5(some) << endl;
}