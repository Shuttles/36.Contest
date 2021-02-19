/*************************************************************************
	> File Name: 5.Spell.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月18日 星期四 12时35分37秒
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

//写不下去了。。我太菜了

#define NUM(a) ((a) - '0')
#define CHAR(a) ((a) + '0')

string N, ans("0");

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
    cin >> N;
    return ;
}

void solve() {
    ans[ans.size() - 1] = NUM(ans[ans.size() - 1]);

    for (int i = N.size() - 1; i > 0; i--) {
        ans[ans.size() - 1] += NUM(N[i]);
        if (ans[ans.size() - 1] < 10) continue;
        ans = char(ans[ans.size() - 1] / 10) + ans;
        ans[ans.size() - 1] %= 10;
    }
    cout << ans << endl;
    return ;
}

int main() {
    input();
    solve();
    return 0;
}
