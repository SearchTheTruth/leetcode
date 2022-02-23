#include <iostream>
#include <memory>
#include <vector>
#include "Node.h"

using namespace std;

class Info {
public:
    Info(int h, int n) : height(h), nodes(n) {};
    int height = 0;
    int nodes = 0;
};

shared_ptr<Info> process(Node *head)
{
    if (head == nullptr)
        return make_shared<Info>(0, 0);
    auto left = process(head->left);
    auto right = process(head->right);
    int h = max(left->height, right->height) + 1;
    int s = left->nodes + right->nodes + 1;
    return make_shared<Info>(h, s);
}

int isFullTree(Node *root)
{
    auto ret = process(root);
    cout << "height is " << ret->height << " nodes is " << ret->nodes << endl;
    return ret->nodes == (1 << ret->height) - 1;
}

//             3
//      2             7
//  5      4       6    1
//12 16  21 31  77 88 33 44
Node *createNode(int i)
{
    return new Node(i);
}

Node *buildCompleteTree_1(vector<int> &arr, vector<int>::iterator it)
{
    Node *head = createNode(*it++);
    head->left = createNode(*it++);
    head->right = createNode(*it++);
    head->left->left = createNode(*it++);
    head->left->right = createNode(*it++);
    head->right->left = createNode(*it++);
    head->right->right = createNode(*it++);
    return head;
}

int main()
{
    vector<int> arr = {3, 2, 7, 5, 4, 6, 1, 12, 16, 21, 31, 77, 88, 33, 44};
    Node *root = buildCompleteTree_1(arr, arr.begin());

    cout << "FullTree: " << isFullTree(root) << endl;
}