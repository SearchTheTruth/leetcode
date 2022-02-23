#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
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


string gStr;

//以先序顺序将树序列化
string preSerlzTraversal(Node *head)
{
	if (head == nullptr) {
		gStr += string("#") + string("_");
		return gStr;
	}
	char buf[10] = {0};
	snprintf(buf, 10, "%d", head->value);
	gStr += string(buf) + string("_");
	preSerlzTraversal(head->left);
	preSerlzTraversal(head->right);
	return gStr;
}

string serialize(Node *head)
{
	return preSerlzTraversal(head);
}

//以先序顺序根据序列化字符构建树
Node *preUnserlzTraversal(deque<string> &que)
{
	if (que.empty())
		return nullptr;
	string ch = que.front();
	que.pop_front();

	if (ch == string("#"))
		return nullptr;
	Node *head = new Node(atoi(ch.c_str()));
	head->left = preUnserlzTraversal(que);
	head->right = preUnserlzTraversal(que);
	return head;
}

Node *unserialize(string &str)
{
	deque<string> parse;
	size_t it = 0, s = 0, e = 0;
	while (it < str.size()) {
		s = it;
		e = str.find("_", s);
		it = e + 1;
		string ch(str, s, e - s);
		parse.push_back(ch);
	}
	return preUnserlzTraversal(parse);
}

int firstTrav(Node *head)
{
    if (head == nullptr)
        return 0;
    cout << head->value << endl;
    firstTrav(head->left);
    firstTrav(head->right);
}

int main()
{
    vector<int> arr = {3, 2, 7, 5, 4, 6, 1, 12, 16, 21, 31, 77, 88, 33, 44};
    Node *root = buildCompleteTree_1(arr, arr.begin());
	
	string str = serialize(root);
	cout << str << endl;

	Node *tree = unserialize(str);
	firstTrav(tree);

	return 0;
}	