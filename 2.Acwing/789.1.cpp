#include <iostream>
using namespace std;
#define MAX_N 100000
// 二分的普通防御措施不能解决不存在元素的情况！

int n, q;
int arr[MAX_N + 5];

void input() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return ;
}

// 0000011111
int bsBegin(int *arr, int n, int num) {
    int l = 0, r = n;
    int mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (arr[mid] < num) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    return (r == n ? -1 : r);
}

// 11111100000
int bsEnd(int *arr, int n, int num) {
    int l = -1, r = n - 1;
    int mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (arr[mid] <= num) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return (l == -1 ? -1 : l);
}

void output() {
    int num = 0;
    while (q--) {
        cin >> num;
        int begin = bsBegin(arr, n, num);
        int end = bsEnd(arr, n, num);
        if (arr[begin] != num) {
            begin = -1;
        } 
        if (arr[end] != num) {
            end = -1;
        }
        cout << begin << " " << end << endl;
    }
    return ;
}

int main() {
    input();
    output();
    return 0;
}