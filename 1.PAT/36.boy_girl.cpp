/*************************************************************************
	> File Name: 36.boy_girl.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月19日 星期五 14时47分52秒
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
string g_id, b_id, g_name, b_name;
int g_score, b_score;


void input() {
    cin >> n;
    return ;
}

void solve() {
    string name, id;
    char sex;
    int score;
    for (int i = 1; i <= n; i++) {
        cin >> name >> sex >> id >> score;
        switch (sex) {
            case 'F': {
                if (!g_id.empty() && g_score > score) continue;
                g_id = id, g_name = name, g_score = score;
            } break;
            case 'M': {
                if (!b_id.empty() && b_score < score) continue;
                b_id = id, b_name = name, b_score = score;
            } break;
        }
    }
    
    if (g_id.empty()) cout << "Absent" << endl;
    else {
        cout << g_name << " " << g_id << endl;
    }
    if (b_id.empty()) cout << "Absent" << endl;
    else {
        cout << b_name << " " << b_id << endl;
    }
    if (b_id.empty() || g_id.empty()) cout << "NA" << endl;
    else cout << abs(g_score - b_score) << endl;

}


int main() {
    input();
    solve();
    return 0;
}
