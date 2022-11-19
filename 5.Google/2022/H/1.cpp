#include <iostream>
using namespace std;

long long T, L, N, D;
char C;

void input() {
    cin >> T;
    return;
}

void output() {
    for (long long z = 1; z <= T; z++) {
        cin >> L >> N;
        char dir = 'C';
        long long now = 0;
        long long ans = 0;
        for (long long i = 1; i <= N; i++) {
            cin >> D >> C;
            if (i == 1) {
                dir = C;
            } 
            long long circles = 0;
            if (dir == C) {
                if (now + D >= L) {
                    circles = (now + D) / L;
                    ans += circles;
                    now = (now + D) % L;
                } else {
                    now += D;
                }
                //printf("now = %d, dir = %c, ans = %d\n", now, dir, ans);
            } else {
                dir = C; // change dir
                circles = (D - now) / L;
                if (circles >= 0) {
                    ans += circles ;
                }
                now = (D - now) % L;
                //printf("now = %d, dir = %c, ans = %d\n", now, dir, ans);                
            }
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