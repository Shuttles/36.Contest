/*************************************************************************
	> File Name: 31.U型输出.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月11日 星期四 16时32分14秒
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

//其实这题很简单
//由题意2*n1 = N + 2 - n2　并且 3<=n2<=N
//条件是n1 <= n2
//可以画出n1随n2变化的图像，发现n2越大，n1越小
//所以枚举n2，一直到n1第一次<=n2时就行了
#define MAX_N 80
int n1, n2, n3;
string str;

void input() {
    cin >> str;
    return ;
}


void output() {
    int step = n2 - 2;
    for (int i = 1, j = str.size() - 1; i < n1; i++, j--) {
        cout << str[i];
        for (int k = 0; k < step; k++) cout << " ";
        cout << str[j] << endl;
    }
    for (int i = n1; i < n1 + n2; i++) {
        cout << str[i];
    }
    cout << endl;
    return ;
}

void solve() {
    int N = str.size();
    str = " " + str;//为了方便输出

    //枚举n2直到n1、n3第一次<=n2
    for (int i = 3; i <= N; i++) {
        if ((N + 2 - i) % 2) continue;
        if ((N + 2 - i) / 2 <= i) {
            n1 = n3 = (N + 2 - i) / 2;
            n2 = i;
            break;
        }
    }

    output();
    return ;
}

int main() {
    input();
    solve();
    return 0;
}
