#include <iostream>
using namespace std;

#define MAX_N 100
#define MAX_DIFF 1000
int n;
int a[MAX_N + 5];


void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    return ;
}

void output() {
    int minDiff = MAX_DIFF;
    for (int i = 1; i <= n; i++) {
        int next = ((i == n) ? 1 : i + 1);
        int diff = abs(a[next] - a[i]);
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    cout << minDiff << endl;
    return ;
}

int main() {
    input();
    output();
    return 0;
}