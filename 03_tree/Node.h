#ifndef _NODE_H
#define _NODE_H
class Node {
public:
    Node(int i) : value(i) {};
    Node *left = nullptr;
    Node *right = nullptr;
    int value = 0;
};
#endif
