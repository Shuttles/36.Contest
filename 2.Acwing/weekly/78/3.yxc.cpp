#include <iostream>
using namespace std;

// 思路：
// 从后往前，维护一个单调递减栈（可以证明删去的都是用不到的元素），然后用bs来找出最后一个小于当前元素的值
// 时间复杂度nlogn

// 如何想到？
// 看到数据范围是1e9想到时间复杂度必须控制在nlogn以内
// 所以要用到bs，想用bs必须得单调有序，因此想到单调栈
#define MAX_N 200000
int h[MAX_N + 5], stk[MAX_N + 5], ans[MAX_N + 5];
int n;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    return ;
}

void output() {
    int top = -1;
    for (int i = n - 1; i >= 0; i--) {
        // 如果当前单调递减栈为空，表明右边没有小于的元素
        // 如果栈顶（也就是最小值）>= 当前值
        // 赋值-1
        if (top == -1 || h[stk[top]] >= h[i]) {
            ans[i] = -1;
        } else {
            // 000011111找第一个1
            int l = 0, r = top;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (h[stk[mid]] < h[i]) r = mid;
                else l = mid + 1;
            }
            ans[i] = stk[r] - i - 1;
        }
        
        // 维护单调递减栈
        if (top == -1 || h[i] < h[stk[top]]) stk[++top] = i;
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return ;
}

int main() {
    input();
    output();
    return 0;
}