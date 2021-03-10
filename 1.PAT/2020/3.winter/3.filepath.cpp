/*************************************************************************
	> File Name: 3.filepath.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月10日 星期三 11时33分44秒
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

void input() {
    cin >> n;
    int num = ' ';
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        while (num == ' ') {
            cin >> num;
            if (num == ' ') cnt++;
        }
        cout << "cnt = " << cnt << endl;
        num = ' ';
    }
    return ;
}

void solve() {
    
}

int main() {
    input();
    solve();
    return 0;
}
