/*************************************************************************
	> File Name: 2.dfs.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月10日 星期三 17时07分30秒
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

//其实就是求组合数，只不过每次都要输出
#define MAX_N 10000

int n, m;
int price[MAX_N + 5];
int combine[MAX_N + 5], idx = 1;
long long ans = 0;
map<int, int> ind_price, total_price;


void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
        ind_price[price[i]] = i;
    }
    return ;
}
 
void output(int len) {
    for (int i = 1; i <= len; i++) {
        if (i != 1) cout << " ";
        cout << combine[i];
    }
    cout << endl;
    return ;
}

bool is_all_djacent(int len) {
    for (int i = 1; i <= len; i++) {
        if (i == 1) continue;
        if (ind_price[combine[i]] != ind_price[combine[i - 1]] + 1) return false;
    }
    return true;
}

void check(int len) {
    int total = 0;
    for (int i = 1; i <= len; i++) {
        total += combine[i];
        if (total > m) break;
    }
    if (total <= m && is_all_djacent(len)) {
        cout << "后面是可行方案 : ";
        output(len);
        ans += 1;
    }
    return ;
}

void dfs(int depth) { //表示现在站在combine[depth]面前
    int start = 1;
    if (depth > 1) start = ind_price[combine[depth - 1]] + 1;
    for (int i = start; i <= n; i++) {
        combine[depth] = price[i];
        output(depth);
        check(depth);
        dfs(depth + 1);
    }
    return ;
}

long long solve() {
    dfs(1);
    return ans;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
