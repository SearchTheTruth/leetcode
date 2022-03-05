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

    return head_1;
}

void printkAddr(vector<shared_ptr<int>> &a)
{
    if (a.empty())
        cout << "empty" << endl;
    else
        cout << a.back() << endl;
}

using NodeSet = vector<Node *>;
map<Node *, shared_ptr<NodeSet>> combindSet;     //用int的内存地址来表示集合，地址相同则Node处于同一集合中

void merge(Node *to, Node *from)
{   
    auto &toSetPtr = combindSet[to];
    auto &fromSetPtr = combindSet[from];
    if (!toSetPtr) {
        toSetPtr = make_shared<NodeSet>();
        toSetPtr->push_back(to);
    }
    if (!fromSetPtr) {
        fromSetPtr = make_shared<NodeSet>();
        fromSetPtr->push_back(from);
    }

    toSetPtr->insert(toSetPtr->end(), fromSetPtr->begin(), fromSetPtr->end());
    for(auto &it : *fromSetPtr) {
        combindSet[it] = toSetPtr;
    }
}

bool inSameSet(Node *to, Node *from)
{
    auto &toSetPtr = combindSet[to];
    auto &fromSetPtr = combindSet[from];

    if (!toSetPtr || !fromSetPtr)
        return false;
    return toSetPtr == fromSetPtr;
}



set<Edge> *kruskalMst(set<Edge> &edgeSet)
{
    set<Edge> *mst = new set<Edge>();

    for (auto edge = edgeSet.begin(); edge != edgeSet.end(); ++edge) {
        if (inSameSet(edge->to, edge->from))
            continue;
        merge(edge->to, edge->from);
        mst->insert(*edge);
    }
    return mst;
}

int main()
{
    //set<Edge, greater<Edge>> edgSet;     降序排列
    set<Edge> edgSet;                   //升序排列
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
