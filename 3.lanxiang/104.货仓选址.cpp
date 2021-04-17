/*************************************************************************
	> File Name: 104.货仓选址.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月16日 星期五 21时10分52秒
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
int arr[MAX_N + 5];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    return ;
}

int solve() {
    sort(arr, arr + n);
    int mid = arr[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) ans += abs(arr[i] - mid);

    return ans;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
