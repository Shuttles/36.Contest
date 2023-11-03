#include <iostream>
using namespace std;

#define MAX_N 3000

int n, ans;
char s[MAX_N + 5];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    return ;
}

bool isComposite(char nowCh, char next) {
    if (nowCh == 'R' && next == 'L') return true;
    return false;
}

void output() {
    int firstInd = 1, lastInd = n;
    char firstCh = '.', lastCh = '.';
    // process left and right
    for (int i = 1; i <= n; i++) {
        if (s[i] != '.') {
            firstInd = i;
            firstCh = s[i];
            break;
        }
    }
    if (firstCh == 'R') {
        ans += (firstInd - 1);
        //printf("left : %d\n", firstInd - 1);
    }
    for (int i = n; i >= 1; i--) {
        if (s[i] != '.') {
            lastInd = i;
            lastCh = s[i];
            break;
        }
    }
    if (lastCh == 'L') {
        ans += (n - lastInd);
        //printf("right : %d\n", n - lastInd);
    }
    //printf("Sum of left and right = %d\n", ans);
    // process mid
    char nowCh = firstCh;
    int temp = 0;
    for (int i = firstInd; i <= lastInd; i++) {
        if (s[i] == '.') {
            temp += 1;
            continue;
        } else if (isComposite(nowCh, s[i])) {
            if (temp % 2) {
                temp = 1;
            } else {
                temp = 0;
            }
        } 
        //printf("i = %d, temp = %d\n", i, temp);
        ans += temp;
        temp = 0;
        nowCh = s[i];
    }
    ans += temp;
    cout << ans << endl;
    return ;
}

int main() {
    input();
    output();
    return 0;
}