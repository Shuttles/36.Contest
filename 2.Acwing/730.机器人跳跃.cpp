/*************************************************************************
	> File Name: 730.机器人跳跃.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年04月08日 星期四 16时45分46秒
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

//典型的二分答案
//00001111找第一个1
//1.枚举区间 H[i]
//2.判断条件：能否完成游戏

//后来发现错了，枚举区间是1 ~ max(H[i])
//又一个bug: energy有时会加了之后溢出int, 改成long long即可
//又又一个bug: 改成long long 还是会溢出，所以得换一个判断条件的实现方法
//　　　　　　　改进之后的实现方法：当energy>=sum(H[i])时，再怎么减也不可能<0，所以可以提前结束判断

#define MAX_N 100000
int n, sum = 0;
int H[MAX_N + 5], num[MAX_N + 5];//num是H的拷贝，用来排序

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> H[i];
        sum += H[i];
    }
    memcpy(num, H, sizeof(H));
    sort(num, num + 1 + n);
    return ;
}

bool is_succ(long long energy) {
    for (int i = 1; i <= n; i++) {
        if (H[i] > energy)
            energy -= (H[i] - energy);
        else 
            energy += (energy - H[i]);

        if (energy >= sum)  
            return true;
        if (energy < 0) 
            return false;

    }
    return true;
}

//00001111找第一个1
int binary_search(int l, int r) {
    int head = l, tail = r + 1;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (is_succ(mid))  
            tail = mid;
        else 
            head = mid + 1;
    }
    return (tail == r + 1 ? -1 : tail);
}

int solve() {
    int ans = binary_search(1, num[n]);
    return ans;
}

int main() {
    input();
    cout << solve() << endl;
    return 0;
}
