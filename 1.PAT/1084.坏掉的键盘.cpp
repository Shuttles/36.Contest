/*************************************************************************
	> File Name: 1084.坏掉的键盘.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月20日 星期六 15时14分01秒
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

#define MAX_N 128
string a, b;
bool used[MAX_N + 5];//0-9数字 A-Z 65-90  a-z 97-122   _ 95


void input() {
    cin >> a >> b;
    return ;
}

char formatify(char ch) {
    if (ch >= 'a' && ch <= 'z') ch -= 32;
    return ch;
}

void solve() {
    for (int i = 0, j = 0; i < a.size(); ) {
        if (j >= b.size() || a[i] - b[j]) {
            if (used[formatify(a[i])]) {
                i++;
                continue;
            }
            cout << formatify(a[i]);
            used[formatify(a[i])] = true;
            i++;
        
        } else {
            //a[i] == b[j]
            i++;
            j++;
            continue;
        }
    }
    cout << endl;
    return ;
}

int main() {
    input();
    solve();
    return 0;
}
