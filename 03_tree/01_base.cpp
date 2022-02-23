#include <iostream>
#include <list>
#include <vector>
#include "Node.h"

using namespace std;

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

#if 0
Node *buildCompleteTree(vector<int> &arr, vector<int>::iterator it)
{
    if (it == arr.end())
        return NULL;
    
    //insert curr value
    Node *p = new Node();
    //insert next value
}
#endif

//遍历序
int traversal(Node *head)
{
    if (head == nullptr)
        return 0;
    cout << head->value << endl;
    traversal(head->left);
    cout << head->value << endl;
    traversal(head->right);
    cout << head->value << endl;
}

//先序 头左右
int firstTrav(Node *head)
{
    if (head == nullptr)
        return 0;
    cout << head->value << endl;
    firstTrav(head->left);
    firstTrav(head->right);
}

//中序 左头右
int midTrav(Node *head)
{
    if (head == nullptr)
        return 0;
    midTrav(head->left);
    cout << head->value << endl;
    midTrav(head->right);
}

//后序 左右头
int afterTrav(Node *head)
{
    if (head == nullptr)
        return 0;
    afterTrav(head->left);
    afterTrav(head->right);
    cout << head->value << endl;
}

int main ()
{
    vector<int> arr = {3, 2, 7, 5, 4, 6, 1, 12, 16, 21, 31, 77, 88, 33, 44};
    Node *root = buildCompleteTree_1(arr, arr.begin());
    cout << "===all===" << endl;
    traversal(root);
    cout << "===first===" << endl;
    firstTrav(root);
    cout << "===mid===" << endl;
    midTrav(root);
    cout << "===after===" << endl;
    afterTrav(root);
    
    return 0;
}