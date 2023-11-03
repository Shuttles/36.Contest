#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//sort特殊关卡，按从大到小排
#define MAX_N 100
int n, m;
long long ans;
vector<int> arr;
vector<long long> special;

void Print() {
    printf("arr = ");
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;
    printf("special = ");
    for (auto x : special) {
        cout << x << " ";
    }
    cout << endl;
    return ;
}

void input() {
    cin >> n >> m;
    int x, ind;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    for (int i = 1; i <= m; i++) {
        cin >> ind;
        special.push_back(arr[ind - 1]);
    }
    //Print();
    return;
}


void output() {
    sort(special.begin(), special.end(), greater<long long>());
    //Print();
    for (auto iter : arr) {
        ans += iter;
    }
    long long sumOfSpec = 0;
    for (auto iter : special) {
        sumOfSpec += iter;
    }
    ans -= sumOfSpec;
    for (auto iter : special) {
        if (ans > iter) {
            ans *= 2;
        } else {
            ans += iter;
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