#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000

int n, m;
int a[MAX_N + 5], b[MAX_N + 5];
long long sumOfa[MAX_N + 5], sumOfb[MAX_N + 5];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        sumOfa[i] = sumOfa[i - 1] + a[i];
    }
    return ;
}

void output() {
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        sumOfb[i] = sumOfb[i - 1] + b[i];
    }
    cin >> m;
    int choice, l, r;
    while (m--) {
        cin >> choice >> l >> r;
        if (choice == 1) {
            cout << sumOfa[r] - sumOfa[l - 1] << endl;
        } else if (choice == 2) {
            cout << sumOfb[r] - sumOfb[l - 1] << endl;
        }
    }
    return ;
}

int main() {
    input();
    output();
    return 0;
}