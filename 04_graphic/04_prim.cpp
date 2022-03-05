#include "graphic.h"

using namespace std;

Node *buildTemplateGraphic(set<Edge> &edgSet)
{
    Node *head_1 = new Node(1);   //a
    Node *head_2 = new Node(2);   //b
    Node *head_3 = new Node(3);   //c
    Node *head_4 = new Node(4);   //d
    Node *head_5 = new Node(5);   //e
    Node *head_6 = new Node(6);   //f
    Node *head_7 = new Node(7);   //g

    edgSet.insert(*linkto(2, head_1, head_2));
    edgSet.insert(*linkto(4, head_1, head_3));
    edgSet.insert(*linkto(6, head_2, head_5));
    edgSet.insert(*linkto(10, head_2, head_4));
    edgSet.insert(*linkto(7, head_3, head_4));
    edgSet.insert(*linkto(8, head_3, head_6));
    edgSet.insert(*linkto(1, head_4, head_6));
    edgSet.insert(*linkto(9, head_4, head_7));

    return head_1;
}
void dumpEdge(const Edge &edge)
{
    cout << edge.to->value << " -- " << edge.from->value << " : " << edge.weight << endl;
}

using PriorityQueue = priority_queue<Edge, vector<Edge>, greater<Edge>>;   //升序排列
//using PriorityQueue = priority_queue<Edge>;

void fillNodeEdgeIntoPriQue(Node *head, PriorityQueue &priQue, unordered_set<Edge *> &edgeSet)
{
    //已经记录的边不重复放入队列中
    for(auto &edgePtr : head->edges) {
        cout << "process head is " << head->value << endl; 
        dumpEdge(*edgePtr);

        if (edgeSet.find(edgePtr) != edgeSet.end()) {               //这条边之前已经被加入到了优先队列，处理下一条
            cout << "This edge was in pri que, skip it!" << endl;
            continue;
        }

        cout << "add this edge in the que" << endl;
        edgeSet.insert(edgePtr);
        priQue.push(*edgePtr);
    }
}

bool isHasRing(Node *head, unordered_set<Node *> &nodeSet)
{
    return nodeSet.find(head) != nodeSet.end();
}

void dumpNodeSet(unordered_set<Node *> node)
{
    cout << "==nodeset is ==== " << endl;
    for (auto beg = node.begin(); beg != node.end(); beg++)
        cout << (*beg)->value << endl;
}

void dumpResult(set<Edge> result)
{
    cout << "Note: result is" << endl;
    for (auto it : result)
        dumpEdge(it);
}

set<Edge> primMst(Node *head)
{
    unordered_set<Node *> nodeSet;
    unordered_set<Edge *> edgeSet;
    set<Edge> result;
    PriorityQueue priQue;
    fillNodeEdgeIntoPriQue(head, priQue, edgeSet);
    nodeSet.insert(head);

    while (!priQue.empty()) {
        const Edge edge = priQue.top();
        priQue.pop();
        if (isHasRing(edge.to, nodeSet) && isHasRing(edge.from, nodeSet))   //to或from都会构成环，所以这条边不能使用
            continue;
        fillNodeEdgeIntoPriQue(edge.to, priQue, edgeSet);      //将新增点的边加入到优先队列
        fillNodeEdgeIntoPriQue(edge.from, priQue, edgeSet);
        nodeSet.insert(edge.to);
        nodeSet.insert(edge.from);
        result.insert(edge);
    }
    return result;
}


int main()
{
    set<Edge> edgSet;                   //升序排列
    Node *head = buildTemplateGraphic(edgSet);

    for(auto &it : edgSet) {
        dumpEdge(it);
    }

    cout << "=============" << endl;

    set<Edge> mst = primMst(head);

    for(auto &it : mst) {
        dumpEdge(it);
    }
}
