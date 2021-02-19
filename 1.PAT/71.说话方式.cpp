/*************************************************************************
	> File Name: 71.说话方式.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月19日 星期五 15时43分32秒
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

string str;

void input() {
    getline(cin, str);
    return ;
}

bool is_letter_or_num(char ch) {
    if (ch >= '0' && ch <= '9') return true;
    if (ch >= 'a' && ch <= 'z') return true;
    if (ch >= 'A' && ch <= 'Z') return true;
    return false;
}

void solve() {
    unordered_map<string, int> hash;//记录出现次数
    for (int i = 0; i < str.size(); i++) {
        if (!is_letter_or_num(str[i])) continue;
        int j = i;//双指针扣单词
        string word;
        while (j < str.size() && is_letter_or_num(str[j])) {
            word += tolower(str[j]);
            j++;
        }
        hash[word] += 1;
        i = j;
    }

    //寻找出现次数最多的单词
    string ans;
    int sum = 0;
    for (auto iter : hash) {
        if ((iter.second > sum) || (iter.second == sum && iter.first < ans)) {
            ans = iter.first;
            sum = iter.second;
        }
    }
    cout << ans << " " << sum << endl;
    return ;
}


int main() {
    input();
    solve();
    return 0;
}
