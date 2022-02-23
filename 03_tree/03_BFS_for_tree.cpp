#include <iostream>
#include <queue>
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

int bfs(Node *head)
{
	queue<Node *> que;
	que.push(head);

	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		cout << cur->value << endl;
		if(cur->left != nullptr)
			que.push(cur->left);
		if(cur->right!= nullptr)
			que.push(cur->right);
	}

	return 0;
}

int main()
{
    vector<int> arr = {3, 2, 7, 5, 4, 6, 1, 12, 16, 21, 31, 77, 88, 33, 44};
    Node *root = buildCompleteTree_1(arr, arr.begin());

	bfs(root);
	return 0;
}