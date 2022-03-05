#include <iostream>
#include <unordered_map>

using namespace std;


class PathNode {
friend void deleteAllSubNode(PathNode *node);
public:
    PathNode() = default;
    PathNode(int initPass, int initEnd) : passCnt(initPass), endCnt(initEnd) {};
    void insertString(const string &str);
    bool deleteString(const string &str);
    bool search(const string &sub);
    int  getOccurTimes(const string &sub);

private:
    int passCnt = 0;
    int endCnt = 0;
    unordered_map<char, PathNode *> nexts;
};

void PathNode::insertString(const string &str)
{
    if (str.empty())
        return;

    PathNode *cur = this;
    cur->passCnt++;                                        //root node passcnt++, 表示在该root node下的单词总数
    for (int i = 0; i < str.size(); ++i) {
        auto &ch = str[i];
        if (cur->nexts.find(ch) == cur->nexts.end()) {     //path is not exist
            PathNode *next = new PathNode(1, 0);
            cur->nexts.insert({ch, next});
            cur = next;
        } else {
            cur = cur->nexts[ch];                        //path exist, passcnt++, 继续向下处理下一个字母
            cur->passCnt++;
        }
    }
    cur->endCnt++;
}

void deleteAllSubNode(PathNode *node)
{
    if (node->nexts.empty())
        return;

    for (auto it = node->nexts.begin(); it != node->nexts.end(); ++it) {
        deleteAllSubNode((*it).second);
        delete (*it).second;
    }

    delete node;

    return;
}

bool PathNode::deleteString(const string &str)
{
    if (!search(str)) {
        cout << str << " was not exist, can't delete it!" << endl;
        return false;
    }

    PathNode *cur = this;
    cur->passCnt--;                                        //root node passcnt--, 表示在该root node下的单词总数
    for (int i = 0; i < str.size(); ++i) {
        auto &ch = str[i];
        PathNode *lastCur = cur;
        cur = cur->nexts[ch];                              //path exist, passcnt--, 继续向下处理下一个字母
        cur->passCnt--;
        if (!cur->passCnt) {                                 //passcnt = 0,路径被截断不必再处理后续node了,直接删除即可,同时删除在map中的记录
            deleteAllSubNode(cur);
            lastCur->nexts.erase(ch);                       
            return true;
        }
    }
    cur->endCnt--;
    return true;
}

bool PathNode::search(const string &sub)
{
    if (sub.empty())
        return false;
    
    PathNode *cur = this;
    for (int i = 0; i < sub.size(); ++i) {
        auto &ch = sub[i];
        if (cur->nexts.find(ch) == cur->nexts.end())     //path is not exist
            return false;
        else
            cur = cur->nexts[ch];                        //path exist, passcnt++, 进入下一层继续查下一个字母
    }
    if (!cur->endCnt)                                    //虽然路径存在，但没在此终结，所以不存在这个单词
        return false;
    else
        return true;
}

int  PathNode::getOccurTimes(const string &sub)
{
    if (sub.empty())
        return 0;
    
    PathNode *cur = this;
    for (int i = 0; i < sub.size(); ++i) {
        auto &ch = sub[i];
        if (cur->nexts.find(ch) == cur->nexts.end())     //path is not exist
            return 0;
        else
            cur = cur->nexts[ch];                        //path exist, passcnt++, 进入下一层继续查下一个字母
    }

    return cur->passCnt;
}


int main()
{
    PathNode root;

    root.insertString("abcde");
    root.insertString("abcd");
    root.insertString("abc");

    cout << "\"abc\" as prefix was occur " << root.getOccurTimes("abc") << " times" << endl;

    cout << "\"ef\" exist:" << root.search("ef") << endl;


    cout << "\"abc\" exist:" << root.search("abc") << endl;
    cout << "\"abcd\" exist:" << root.search("abcd") << endl;
    cout << "\"abcde\" exist:" << root.search("abcde") << endl;

    root.deleteString("abc");
    cout << "\"abc\" exist:" << root.search("abc") << endl;
    cout << "\"abc\" as prefix was occur " << root.getOccurTimes("abc") << " times" << endl;

    return 0;
}