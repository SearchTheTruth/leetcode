#include <string>
#include <cstdlib>

using namespace std;

string gStr;

string preSerlzTraversal(Node *head)
{
	if (head == nullptr) {
		gStr += string("#");
		return gStr;
	}
	char buf[10] = {0};
	itoa(head->value, buf, 10);
	gStr += string(buf) + string("_");
	preSerlzTraversal(head->left);
	preSerlzTraversal(head->right);
	return gStr;
}

string serialize(Node *head)
{
	return preTraversal(head);
}

Node *preUnserlzTraversal(string &str, string::iterator it)
{
	if(it == str.end())
		return nullptr;
	//parse from it, num or null
	//if num, make node(num)

	//head == null; return null
	//get left, right
	//link head with left and right
	preUnserlzTraversal(left);
	preUnserlzTraversal(right);
	return head;
}

Node *head unserialize(string &str)
{
	return preUnserlzTraversal(&str, str.begin());
}
