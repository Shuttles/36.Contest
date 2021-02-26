/*************************************************************************
	> File Name: 826.单链表.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月26日 星期五 11时47分16秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

#define MAX_N 100000

//head表示头结点的下标
//e[i]表示节点i的值
//ne[i]表示节点i的next指针是多少
//idx存储当前已经有了第几个节点
//也就是说，下标代表了使用的顺序，但是并不代表在链表中的顺序！
int head, e[MAX_N + 5], ne[MAX_N + 5], idx;

void init() {
    head = -1;
    idx = 0;
    return ;
}

void add_to_head(int x) {//可能会有插入失败的情况--数组开小了，不够用了
    e[idx] = x, ne[idx] = head, head = idx++;
    return ;
}

//将x插入到下标为k的节点后面
void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
    return ;
}

//将下标是k的点后面的点删掉 其实下标是k就代表这是第k+1个插入的点
//注意：这和删除链表中第k个节点不一样！！！
void remove(int k) {
    ne[k] = ne[ne[k]];
    return ;
}

void output() {
    for (int i = head; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }
    cout << endl;
    return ;
}

int main() {
    int m;
    cin >> m;
    init();
    while (m--) {
        int k, x;
        char op;
        cin >> op;
        switch(op) {
            case 'H': {
                cin >> x;
                add_to_head(x);
            } break;
            case 'D': {
                cin >> k;
                if (k == 0) head = ne[head];
                remove(k - 1);
            } break;
            case 'I': {
                cin >> k >> x;
                add(k - 1, x);
            } break;
        }
    }
    output();
    return 0;
}
