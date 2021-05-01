/*************************************************************************
	> File Name: 875.快速幂.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年05月01日 星期六 17时38分37秒
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
int a, b, p;

long long solve(int, int, int);

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> p;
        cout << solve(a, b, p) << endl;
    }
    return ;
}

//递归版本
long long q_pow(int a, int n) {
    if (n == 0) return 1;

    if (n & 1) {
        return q_pow(a, n - 1) * a % p;
    } else {
        long long temp = q_pow(a, n / 2) % p;
        return temp * temp % p;
    }
}

//非递归版本
//要想理解，要涉及到二进制
long long qpow(long long a, int n) {
    long long ans = 1;
    while (n) {
        if (n & 1) {
            ans *= a;
        }
        a = a * a; 

        n >>= 1;
    }
    return ans;
}



long long solve(int a, int b, int p) {
    long long ans = qpow(a, b) % p;
    return ans;
}

int main() {
    input();
    return 0;
}
