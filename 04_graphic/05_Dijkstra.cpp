#include "graphic.h"

using namespace std;

void dumpEdge(const Edge &edge)
{
    cout << edge.to->value << " -- " << edge.from->value << " : " << edge.weight << endl;
}

Node *buildTemplateGraphic(set<Edge, greater<Edge>> &edgSet)
{
    Node *head_1 = new Node(1);
    Node *head_2 = new Node(2);
    Node *head_3 = new Node(3);
    Node *head_4 = new Node(4);
    Node *head_5 = new Node(5);


    edgSet.insert(*linkto(2, head_1, head_4));
    edgSet.insert(*linkto(100, head_1, head_2));
    edgSet.insert(*linkto(6, head_1, head_5));

    edgSet.insert(*linkto(7, head_2, head_4));
    edgSet.insert(*linkto(1, head_2, head_3));
    edgSet.insert(*linkto(5, head_2, head_5));

    edgSet.insert(*linkto(5, head_3, head_4));
    edgSet.insert(*linkto(20, head_3, head_5));

    return head_1;
}

Node *getMinUnlockNode(unordered_map<Node *, int> &distanceMap, unordered_set<Node *> lockNode)
{
    Node *minNode = nullptr;
    int min = INT32_MAX;
    for (auto it = distanceMap.begin(); it != distanceMap.end(); ++it) {
        if (lockNode.find((*it).first) != lockNode.end())          //if node was be locked, skip it
            continue;
        if ((*it).second < min) {
            min = ((*it).second);
            minNode = ((*it).first);
        }
    }

    return minNode;
}

unordered_map<Node *, int> dijkstra(Node *head)
{
    unordered_map<Node *, int> distanceMap;
    unordered_set<Node *> lockNode;
    Node *minNode;

    distanceMap.insert({head, 0});
    minNode = getMinUnlockNode(distanceMap, lockNode);
    while (minNode != nullptr) {
        cout << "+++++++minNode " << minNode->value << " +++++++++++++++" << endl;
        int distance = distanceMap[minNode];
        for (auto edgePtr : minNode->edges) {
            Node *nextNode = (edgePtr->to == minNode ? edgePtr->from : edgePtr->to);
            cout << "nextNode " << nextNode->value << endl;
            if (distanceMap.find(nextNode) == distanceMap.end()) {                //next node it not in distanceMap, add it
                distanceMap[nextNode] = distance + edgePtr->weight;
            } else {
                cout << "distanceMap[nextNode] = " << distanceMap[nextNode];
                cout << "  distance = " << distance;
                cout << "  edgePtr->weight = " << edgePtr->weight << endl; 
                int mini = min(distanceMap[nextNode], distance + edgePtr->weight);
                distanceMap[nextNode] = mini;
                cout << "distanceMap[nextNode] = " << distanceMap[nextNode] << endl;
            }
        }
        lockNode.insert(minNode);                                                //lock this minNode
        minNode = getMinUnlockNode(distanceMap, lockNode);
    }
    return distanceMap;
}

int main()
{
    set<Edge, greater<Edge>> edgSet;
    unordered_map<Node *, int> distanceMap;
    Node *head = buildTemplateGraphic(edgSet);

    distanceMap = dijkstra(head);

    for (auto it = distanceMap.begin(); it != distanceMap.end(); it++) {
        cout << "1 to " << it->first->value << " dis: " << it->second << endl;
    }

    return 0;
}