#include <iostream>
#include <unordered_map>
using namespace std;
#define MAX_N 100000

int n, h, m;
int minute;
unordered_map<int, int> hashMap;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h >> m;
        minute = h * 60 + m;
        hashMap[minute] += 1;
    }
    return ;
}

void output() {
    int ans = 0;
    for (auto iter : hashMap) {
        if (iter.second > ans) {
            ans = iter.second;
        }
    }
    cout << ans << endl;
    return ;
}

int main() {
    input();
    output();
    return 0;
}