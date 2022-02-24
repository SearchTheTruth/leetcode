#include "graphic.h"

using namespace std;

//   3
// 4   5   1
// 2 - 6
//     7

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

int dfs_1(Node *head, set<Node *> &exist)
{
    cout << head->value << endl;
    exist.insert(head);

    for (auto &it : head->nexts) {
        if (exist.find(it) == exist.end()) {  //exist中没有访问过这个元素则继续访问
            dfs_1(it, exist);
        }
    }
    return 0;
}

int dfs_2(Node *head)
{
    stack<Node *> stk;
    set<Node *> exist;

    stk.push(head);
    exist.insert(head);
    cout << head->value << endl;

    while (!stk.empty()) {
        auto cur = stk.top();
        stk.pop();
        for (auto &it : cur->nexts) {
            if (exist.find(it) == exist.end()) {   //该点没有被访问过则继续处理
                stk.push(cur);
                stk.push(it);
                exist.insert(it);
                cout << it->value << endl;
                break;
            }
        }
    }
    return 0;
}

int main()
{
    Node *head = buildTemplateGraphic();
    cout << "dfs_1 =============" << endl;
    set<Node *> record;
    dfs_1(head, record);
    cout << "dfs_2 =============" << endl;
    dfs_2(head);

    return 0;
}