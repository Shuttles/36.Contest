/*************************************************************************
	> File Name: 895.lcs.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月12日 星期一 11时50分30秒
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

//dp[i]　表示以arr[i]作为结尾的最长上升子序列的长度
//dp[i] = max(dp[j] + 1) 1<=j<=i, arr[j] < arr[i]
//dp[i] = 1, dp[0] = 0
//时间复杂度O(n^2)

#define MAX_N 1000
int n;
int arr[MAX_N + 5];
int dp[MAX_N + 5];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    return ;
}

int solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[j] >= arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
