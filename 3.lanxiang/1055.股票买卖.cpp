/*************************************************************************
	> File Name: 1055.股票买卖.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月16日 星期五 20时28分21秒
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
int n;
int price[MAX_N + 5];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    return ;
}

int solve() {
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        int dt = price[i + 1] - price[i];
        if (dt > 0) ans += dt;
    }
    return ans;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
