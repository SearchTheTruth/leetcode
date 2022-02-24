#include "graphic.h"

using namespace std;

Node *buildTemplateGraphic()
{
    Node *head_3 = new Node(3);
    Node *head_4 = new Node(4);
    Node *head_5 = new Node(5);
    Node *head_1 = new Node(1);
    Node *head_2 = new Node(2);
    Node *head_6 = new Node(6);
    Node *head_7 = new Node(7);

    head_3->linkto(head_4);
    head_3->linkto(head_5);
    head_3->linkto(head_1);
    head_4->linkto(head_2);
    head_5->linkto(head_6);
    head_6->linkto(head_7);
    head_2->linkto(head_6);
    head_5->linkto(head_1);
    return head_3;
}

int bfs(Node *head)
{
    set<Node *> exist;
    queue<Node *> que;

    que.push(head);
    exist.insert(head);

    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        cout << cur->value << endl;

        for (auto &it : cur->nexts) {
            if (exist.find(it) == exist.end()) {
                que.push(it);
                exist.insert(it);
            }
        }
    }
    return 0;
}

int main()
{
    Node *head = buildTemplateGraphic();
    cout << "bfs =============" << endl;
    bfs(head);
    return 0;
}