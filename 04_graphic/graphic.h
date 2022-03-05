#ifndef _GRAPHIC_H
#define _GRAPHIC_H

#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

class Node;


class Edge {
public:
	Edge(int w, Node *to, Node *from) : weight(w), to(to), from(from) {};
	int weight = 0;                //边的权值
	Node *to = nullptr;
	Node *from = nullptr;
};

bool operator<(const Edge &l, const Edge &r)
{
	return l.weight < r.weight;
}


bool operator>(const Edge &l, const Edge &r)
{
	return l.weight > r.weight;
}

bool operator>(const Node &l, const Node &r)
{
	return true;
}

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

	int value = 0;            //值
	int in = 0;               //入度
	int out = 0;              //出度
	std::vector<Node *> nexts;   //相邻点
	std::vector<Edge *> edges;   //相邻边
};

Edge *linkto(int weight, Node *a, Node *b)
{
	a->linkto(b);
	Edge *line = new Edge(weight, a, b);
	a->edges.push_back(line);
	b->edges.push_back(line);
	return line;
}

#endif
