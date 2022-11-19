#include <iostream>
using namespace std;

long long T, L;

void input() {
    cin >> T;
    return;
}

void output() {
    for (long long z = 1; z <= T; z++) {
        cin >> L;
        long long ans = 0;
        if (L == 5) {
            ans = 5;
        } else {
            ans = 5 + ((L - 5) / 5) * 2 + 4;
        }

        printf("Case #%lld: %lld\n", z, ans);
    }
    return ;
}


int main() {
    input();
    output();
    return 0;
}