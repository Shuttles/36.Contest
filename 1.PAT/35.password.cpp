/*************************************************************************
	> File Name: 35.password.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月19日 星期五 12时16分40秒
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

#define MAX_N 1000
int n, m = 0;
string user, password;
struct Account {
    string user;
    string pswd;
} account[MAX_N + 5];

void input() {
    cin >> n;
    return ;
}

string change(string &s) {
    string temp = s;
    for (int i = 0; i < temp.size(); i++) {
        switch(temp[i]) {
            case '1':
                temp[i] = '@';
                break;
            case '0':
                temp[i] = '%';
                break;
            case 'l':
                temp[i] = 'L';
                break;
            case 'O':
                temp[i] = 'o';
                break;
            default:
                continue;
        }
    }
    return temp;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        cin >> user >> password;
        string changed_pswd = change(password);
        if (changed_pswd == password) continue;
        m++;
        account[m].user = user, account[m].pswd = changed_pswd;
    }
    
    if (m == 0) {
        if (n == 1)
            cout << "There is 1 account and no account is modified" << endl;
        else 
            printf("There are %d accounts and no account is modified\n", n);
    } else {
        cout << m << endl;
        for (int i = 1; i <= m; i++) {
            cout << account[i].user << " " << account[i].pswd << endl;    
        }
    }

    return ;
}

int main() {
    input();
    solve();
    return 0;
}
