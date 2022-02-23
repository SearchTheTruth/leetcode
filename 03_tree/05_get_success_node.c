#include <iostream>


//Node left, right, value, parent

Node *getMostLeft(Node *head)
{
	if (head->left == nullptr)
		return head;
	return getMostLeft(head->left);
}

Node *getSuccessNode(Node *head)
{
	if (head->right != null) {
		return getMostLeft(head);
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
