#ifndef _GRAPHIC_H
#define _GRAPHIC_H

#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <set>

class Node {
public:
	Node() = default;
	Node(int n) : value(n) {};
	void linkto(Node *nxt) {
		++in;
		++out;
		++nxt->in;
		++nxt->out;
		nexts.push_back(nxt);
		nxt->nexts.push_back(this);
	}

	int value = 0;
	int in = 0;
	int out = 0;
	std::vector<Node *> nexts;
};

#endif
