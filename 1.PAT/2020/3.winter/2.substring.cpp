/*************************************************************************
	> File Name: 2.substring.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月10日 星期三 10时46分13秒
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

string S, P;
bool flag;

void input() {
    cin>> S >> P;
    return ;
}

string solve() {
    string ans;
    int ind = 1;//对齐到P[ind]
    int min_len = 0x3f3f3f3f;
    if (P.size() == 1) flag = true;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] != P[0]) continue;
        if (flag) return P;
        for (int j = i + 1; j < S.size(); j++) {
            if (S[j] == P[ind]) ind++;
            if (ind == P.size()) {//match successfully
                if (j - i + 1 < min_len) {
                    min_len = j - i + 1;
                    ans = S.substr(i, j - i + 1); 
                }
                ind = 1;
                break;
            } 
        }
    }
    return ans;
}

int main() {
    input();
    cout << solve() << endl;
    return 0;
}
