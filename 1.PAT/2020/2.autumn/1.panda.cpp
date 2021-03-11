/*************************************************************************
	> File Name: 1.panda.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月11日 星期四 10时19分10秒
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

//后来发现map存在问题，比如sample case中的多个138
//所以做不下去了
int n;
int w[MAX_N + 5], sorted_w[MAX_N + 5], milk[MAX_N + 5];
map<int, int> w_ind, sorted_w_ind;

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        sorted_w[i] = w[i];
        w_ind[w[i]] = i;//建立索引
    }
    return ;
}

void output() {
    cout << "w: ";
    for (int i = 1; i <= n; i++) {
        (i != 1) && cout << " ";
        cout << w[i];
    }
    cout << endl;

    cout << "sorted_w: ";
    for (int i = 1; i <= n; i++) {
        (i != 1) && cout << " ";
        cout << sorted_w[i];
    }
    cout << endl;
    return ;
}

int left(int ind) {
    int f_ind = w_ind[sorted_w[ind]];
    if (f_ind == 1) return 0;
    return sorted_w_ind[w[f_ind - 1]];
}

int right(int ind) {
    int f_ind = w_ind[sorted_w[ind]];
    if (f_ind == n) return 0;
    return sorted_w_ind[w[f_ind + 1]];
}

long long solve() {
    long long ans = 0;
    sort(sorted_w + 1, sorted_w + 1 + n);
    
    for (int i = 1; i <= n; i++) sorted_w_ind[sorted_w[i]] = i;//建立排序后的索引

    milk[1] = 200;
    output();
    for (int i = 1; i <= n; i++) {
        printf("left(%d) = %d, right(%d) = %d.\n", i, left(i), i, right(i));
    }

    return ans;
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
