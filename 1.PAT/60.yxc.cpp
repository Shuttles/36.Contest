/*************************************************************************
	> File Name: 60.yxc.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月11日 星期四 19时40分30秒
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
string a, b;

void input() {
    cin >> n >> a >> b;
    return ;
}

void change(string &str) {
    //首先找到小数点的位置
    int ind = str.find(".");
    if (ind == -1) str += '.', ind = str.find(".");

    //将小数点移到最前面
    //可以先把小数点去掉，最后在加在前面
    str = str.substr(0, ind) + str.substr(ind + 1);

    //删除前导0并改动指数ind
    while (str.size() && str[0] == '0') str = str.substr(1), ind--;

    //如果字符串全是0，那么指数为0
    if (str.empty()) ind = 0;

    //补全或截断为n位
    if (str.size() > n) str = str.substr(0, n);
    else str = str + string(n - str.size(), '0');//还有这种操作？？

    str =  "0." + str + "*10^" + to_string(ind);
    return ;
}


void solve() {
    change(a);
    change(b);

    if (a == b) cout << "YES " << a << endl;
    else cout << "NO " << a << " " << b << endl;
    return ;
}


int main() {
    input();
    solve();
    return 0;
}
