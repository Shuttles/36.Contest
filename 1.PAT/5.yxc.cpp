/*************************************************************************
	> File Name: 5.yxc.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月19日 星期五 11时06分19秒
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

//这题居然不用高精度。。。吐了　原来如此easy
#define NUM(a) ((a) - '0')
#define CHAR(a) ((a) + '0')

string n;
string num_english[10] = {
    string("zero"),
    string("one"),
    string("two"),
    string("three"),
    string("four"),
    string("five"),
    string("six"),
    string("seven"),
    string("eight"),
    string("nine")
};


void input() {
    cin >> n;
    return;
}

void solve() {
    int sum = 0;
    for (auto iter : n) sum += NUM(iter);//计算每一位的和

    string ans = to_string(sum);
    cout << num_english[NUM(ans[0])];
    for (int i = 1; i < ans.size(); i++) {
        cout << " " << num_english[NUM(ans[i])];
    }
    cout << endl;
    return ;
}

int main() {
    input();
    solve();
    return 0;
}
