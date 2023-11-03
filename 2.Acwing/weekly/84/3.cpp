#include <iostream>
using namespace std;

// single price:
// if (d <= c/n) all in second
// else (c/n < d) buy which sum of price low
int c, d, n ,m, k;
int ans;

void input() {
    cin >> c >> d >> n >> m >> k;
    return ;
}

void output() {
    if (k >= n * m) {
        cout << 0 << endl;
        return ;
    }
    double singlePrice = ((double )c) / n;
    if (d <= singlePrice) {
        ans += (n * m - k) * d;
    } else {
        int sum1 = (n * m - k) / n; //how many boxes
        ans += (sum1 * c);
        int left = n * m - k - sum1 * n;
        ans += (left * d > c ? c : left * d);
    }
    cout << ans << endl;
    return ;
}

int main() {
    input();
    output();
    return 0;
}