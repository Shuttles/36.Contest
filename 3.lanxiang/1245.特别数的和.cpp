/*************************************************************************
	> File Name: 1245.特别数的和.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月13日 星期二 16时10分17秒
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

#define MAX_N 10000
int n;

void input() {
    cin >> n;
    return ;
}

bool is_interesting(int x) {
    while (x) {
        int temp = x % 10;
        if (temp == 0 || temp == 1 || temp == 2 || temp == 9) {
            return true;
        }
        x /= 10;
    }
    return false;
}


int solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (is_interesting(i)) ans += i;
    }
    return ans;
}



int main() {
    input();
    cout << solve() << endl;
    return 0;
}
