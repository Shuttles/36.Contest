/*************************************************************************
	> File Name: 1209.带分数.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月07日 星期三 21时14分18秒
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
#include <cstring>
#include <vector>
using namespace std;

//n = a + b/c 即 c*n = c*a + b
//所以只需枚举a c，就可计算出b

int n;
int ans = 0;
bool used[10];

void input() {
    cin >> n;
    return ;
}


//1.每个数不能为0
//2.每个数不能包含0
//3.1~9分别出现且只出现一次
bool check(int a, int b, int c) {
    if (!a || !b || !c) return false;
    
    bool st[10] = {0};
    memcpy(st, used, sizeof(used));
    while (b) {
        int x = b % 10;
        b /= 10;
        if (!x || st[x]) return false;
        st[x] = true;
    }
    
    for (int i = 1; i < 10; i++) {
        if (!st[i]) return false;
    }
    return true;
}


void dfs_c(int depth, int a, int c) {//对每一个c,计算出b，并检查是否符合条件
    if (depth > n) return ;
    
    if (check(a, c * (n - a), c)) ans++;

    for (int i = 1; i < 10; i++) {
        if (used[i]) continue;
        used[i] = true;
        dfs_c(depth + 1, a, c * 10 + i);
        used[i] = false;
    }
    return ;
}

void dfs_a(int depth, int a) {
    if (a >= n) return ;
    dfs_c(depth, a, 0);//对每一个a, 枚举c
    
    for (int i = 1; i < 10; i++) {
        if (used[i]) continue;
        used[i] = true;
        dfs_a(depth + 1, a * 10 + i);
        used[i] = false;
    }
    return ;
}


int solve() {
    dfs_a(1, 0);//从第一层开始，a初始值为0
    return ans;
}

int main() {
    input();
    cout << solve() << endl;
    return 0;
}
