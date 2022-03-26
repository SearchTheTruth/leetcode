#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

#if 0   //若Element是内建类型不需要自定义等于运算
template <typename Element>
bool operator==(const Element &a, const Element &b)
{

}
#endif

template<typename Element>
class UnionFindSet {
//friend bool operator==<Element>(const Element &a, const Element &b);
public:
    UnionFindSet(vector<Element> init) {
        for (auto &it : init) {
            elements.insert(it);
            fatherMap.insert({it, it});          //节点最初的父节点就是自己
            sizeMap.insert({it, 1});
        }
    }
    
    int isSameSet(Element a, Element b);
    int unionSet(Element a, Element b);

private:
    Element findEleFather(Element n);
    unordered_set<Element> elements;
    unordered_map<Element, Element> fatherMap;   //child, father 表示父子关系
    unordered_map<Element, int> sizeMap;         //fater, size  表示集合大小
};

template<typename Element>
int UnionFindSet<Element>::isSameSet(Element a, Element b)
{
    if (elements.find(a) == elements.end() || elements.find(b) == elements.end()) {
        cout << "Error: some element was not exist" << endl;
        return false;
    }

    return findEleFather(a) == findEleFather(b);
}

template<typename Element>
int UnionFindSet<Element>::unionSet(Element a, Element b)
{
    if (elements.find(a) == elements.end() || elements.find(b) == elements.end()) {
        cout << "Error: some element was not exist" << endl;
        return false;
    }

    Element aFather = findEleFather(a);
    Element bFather = findEleFather(b);

    int aSize = sizeMap[aFather];
    int bSize = sizeMap[bFather];

    Element big = aSize > bSize ? aFather : bFather;
    Element small = aSize < bSize ? aFather : bFather;  //将小的集合合并到大的集合上

    fatherMap.insert({small, big});
    sizeMap[big] = aSize + bSize;
    sizeMap.erase(small);

    return 0;
}

template<typename Element>
Element UnionFindSet<Element>::findEleFather(Element n)
{
    stack<Element> stk;
    while (n != fatherMap[n]) {
        stk.push(n);
        n = fatherMap[n];
    }

    while (!stk.empty()) {
        Element top = stk.top();
        fatherMap[top] = n;
        stk.pop();
    }

    return n;
}
 