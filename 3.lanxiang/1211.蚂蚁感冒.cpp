/*************************************************************************
	> File Name: 1211.蚂蚁感冒.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月11日 星期日 21时22分39秒
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


//此题的关键就是把相遇掉头看作是相互穿过！
#define MAX_N 100
int n;
int x[MAX_N + 5];

void input() {
    cin >> n;
    for (int i = 1 ; i <= n; i++) {
        cin >> x[i];
    }
    return ;
}

int solve() {
    int left = 0, right = 0; //分别表示左边向右走的蚂蚁数量、右边向左走的蚂蚁数量
    for (int i = 2; i <= n; i++) {
        if (abs(x[i]) < abs(x[1]) && x[i] > 0) left += 1;
        else if (abs(x[i]) > abs(x[1]) && x[i] < 0) right += 1;
    }

    if (x[1] > 0 && right == 0 || x[1] < 0 && left == 0) return 1;
    else return (left + right + 1);
}


int main() {
    input();
    cout << solve() << endl;
    return 0;
}
