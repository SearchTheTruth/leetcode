#include "graphic.h"

using namespace std;

void dumpEdge(const Edge &edge)
{
    cout << edge.to->value << " -- " << edge.from->value << " : " << edge.weight << endl;
}

Node *buildTemplateGraphic(set<Edge, greater<Edge>> &edgSet)
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
    edgSet.insert(*linkto(2, head_4, head_5));

    return head_1;
}


void merge(vector<void *> &a, vector<void *> &b)
{
    if (a.empty())
        a.push_back(&a);
    if (b.empty())
        b.push_back(&b);
    
    b.clear();
    b.push_back(a.back());
}

bool inSameSet(vector<void *> &a, vector<void *> &b)
{
    if (a.empty() || b.empty())
        return false;
    return a.back() == b.back();
}

set<Edge> *kruskalMst(set<Edge, greater<Edge>> &edgeSet)
{
    set<Edge> *mst = new set<Edge>();
    map<Node *, vector<void *>> combindSet;     //用vector<void *>的地址来表示集合，地址相同则Node处于同一集合中

    for (auto edge = edgeSet.begin(); edge != edgeSet.end(); ++edge) {
        auto &toSet = combindSet[edge->to];
        auto &fromSet = combindSet[edge->from];
        if (inSameSet(toSet, fromSet))
            continue;
        merge(toSet, fromSet);
        mst->insert(*edge);
    }
    return mst;
}

int main()
{
    set<Edge, greater<Edge>> edgSet;
    Node *head = buildTemplateGraphic(edgSet);

    for(auto &it : edgSet) {
        dumpEdge(it);
    }

    cout << "=============" << endl;

    set<Edge> *mst = kruskalMst(edgSet);

    for(auto &it : *mst) {
        dumpEdge(it);
    }
    return 0;
}