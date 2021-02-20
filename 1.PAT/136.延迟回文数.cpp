/*************************************************************************
	> File Name: 136.延迟回文数.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月20日 星期六 12时43分47秒
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

vector<int> add(vector<int> a, vector<int> b) {
    vector<int> c;
    for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i++) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

int main() {
    vector<int> a;
    vector<int> b;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    b.push_back(9);
    b.push_back(8);
    b.push_back(7);

    vector<int> c = add(a, b);

    for (auto iter : c) {
        cout << iter;
    }
    cout << endl;
    return 0;
}
