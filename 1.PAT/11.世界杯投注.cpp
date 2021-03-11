/*************************************************************************
	> File Name: 11.世界杯投注.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月11日 星期四 15时21分26秒
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

double ans = 0;
double max_profit[4];
char max_choice[4];
char choice[4] = {0, 'W', 'T', 'L'};


void input() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            double x;
            cin >> x;
            if (x < max_profit[i]) continue;
            max_profit[i] = x;
            max_choice[i] = choice[j];
        }
    }
    return ;
}

void solve() {
    ans = (max_profit[1] * max_profit[2] * max_profit[3] * 0.65 - 1) * 2;
    cout << max_choice[1] << " " << max_choice[2] << " " << max_choice[3] << " ";
    printf("%.2lf\n", ans);
    return ;
}

int main() {
    input();
    solve();
    return 0;
}
