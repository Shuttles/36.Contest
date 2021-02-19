/*************************************************************************
	> File Name: 1.a+b.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月18日 星期四 10时39分16秒
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
#include <stdlib.h>
using namespace std;

int a, b, ans;
string s;

void input() {
    cin >> a >> b;
    return ;
}

string solve() {
    ans = a + b;
    string temp = to_string(ans);

    for (int i = temp.size() - 1, cnt = 0; i >= 0; i--) {
        s = temp[i] + s;
        cnt++;
        if (cnt % 3 == 0 && i && temp[i - 1] != '-') {
            s = ',' + s;
        }
    }
    return s;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
