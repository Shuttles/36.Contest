/*************************************************************************
	> File Name: 996.大整数加法.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年02月20日 星期六 11时41分30秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char str[205];
int ans[205];

int main() {
    int n;//n代表想输入n个数相加
    int i, j, k;
    scanf("%d\n", &n);

    for (k = 1; k <= n; k++) {
        scanf("%s", str);
        int len = strlen(str);
        if (ans[0] < len) ans[0] = len;//如果上次的和的位数小于这次要加的数，则把用来计数的ans[0]赋值为大的位数；
        for (i = 0; i < len; i++) {
            ans[len - i] += str[i] - '0';//倒过来存储大数
        }
        for (i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);//这一步用来处理最后的进位
        }
    }
    for (i = ans[0]; i > 0; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
