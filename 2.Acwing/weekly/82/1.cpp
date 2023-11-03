#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000

int n, k;
int arr[MAX_N + 5];

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    return ;
}

void output() {
    sort(arr + 1, arr + 1 + n);
    cout << arr[n - k + 1] << endl;
    return ;
}

int main() {
    input();
    output();
    return 0;
}