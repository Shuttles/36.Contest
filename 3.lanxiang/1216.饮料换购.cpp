/*************************************************************************
	> File Name: 1216.饮料换购.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月11日 星期日 21时39分33秒
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

int n;

void input() {
    cin >> n;
    return ;
}

int solve() {
    int ans = n; //我们把n当成是盖子数量
    while (n >= 3) {
        ans += n / 3;
        n = n / 3 + n % 3;
    }
    return ans;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
