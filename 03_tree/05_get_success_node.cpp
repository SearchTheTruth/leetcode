#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Node {
public:
    Node(int i) : value(i) {};
    Node *left = nullptr;
    Node *right = nullptr;
	Node *parent = nullptr;
    int value = 0;
};

//Node left, right, value, parent

Node *getMostLeft(Node *head)
{
	if (head->left == nullptr)
		return head;
	return getMostLeft(head->left);
}

Node *getSuccessNode(Node *head)
{
	if (head->right != nullptr) {
		return getMostLeft(head->right);
	}

	while (head->parent != nullptr) {
		if (head->parent->left != head) {
			head = head->parent;
		} else {
			return head->parent;
		}
	}
	return nullptr;
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
	head->left->parent = head;
    head->right = createNode(*it++);
	head->right->parent = head;
    head->left->left = createNode(*it++);
	head->left->left->parent = head->left;
    head->left->right = createNode(*it++);
	head->left->right->parent = head->left;
    head->right->left = createNode(*it++);
	head->right->left->parent = head->right;
    head->right->right = createNode(*it++);
	head->right->right->parent = head->right;
    return head;
}

int main()
{
    vector<int> arr = {3, 2, 7, 5, 4, 6, 1, 12, 16, 21, 31, 77, 88, 33, 44};
    Node *root = buildCompleteTree_1(arr, arr.begin());

	Node *succ = getSuccessNode(root);

	cout << root->value << " next is " << succ->value << endl;
}

