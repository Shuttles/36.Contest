/*************************************************************************
	> File Name: 6.sign_in_out.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月19日 星期五 11时33分10秒
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

int m;
string id, sign_in, sign_out;
struct Person {
    string id;
    string time;
};

void input() {
    cin >> m;
    return ;
}

void solve() {
    Person first, last;
    first.time = string("23:59:59");
    last.time = string("00:00:00");
    for (int i = 1; i <= m; i++) {
        cin >> id >> sign_in >> sign_out;
        if (sign_in < first.time) {
            first.time = sign_in;
            first.id = id;
        }
        if (sign_out > last.time) {
            last.time = sign_out;
            last.id = id;
        }
    }
    cout << first.id << " " << last.id << endl;
    return ;
}


int main() {
    input();
    solve();
    return 0;
}
