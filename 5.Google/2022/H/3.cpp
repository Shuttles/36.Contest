#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 10000
int T, L, N, ans;
int A[MAX_N + 5];
bool graph[MAX_N + 5][MAX_N + 5];

void input() {
    cin >> T;
    return;
}

int dfs(int x) {
    int res = 0;
    for (int i = 1; i <= N; i++) {
        if (i == x) continue;
        if (graph[x][i] == true) {
            if (A[i] < A[x]) {
                //printf("A[%d]=%lld < A[%d]=%lld\n", i, A[i], x, A[x]);
                res += (1 + dfs(i));
            }
        }
    }
    return res;
}

void output() {
    for (int z = 1; z <= T; z++) {
        cin >> N;
        ans = 0;
        memset(graph, 0, sizeof(graph));
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        for (int i = 1; i < N; i++) {
            int x, y;
            cin >> x >> y;
            graph[x][y] = true;
            graph[y][x] = true;
        }
        for (int i = 1; i <= N; i++) {
            int temp = dfs(i);
            //printf("dfs(%d) = %lld\n", i, temp);
            if (temp > ans) {
                ans = temp;
            }
        }

        printf("Case #%d: %d\n", z, ans + 1);
    }
    return ;
}


int main() {
    input();
    output();
    return 0;
}