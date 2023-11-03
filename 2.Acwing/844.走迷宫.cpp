#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 100
#define MAX_M 100

typedef pair<int, int> PII;

int n, m;
int grid[MAX_N + 5][MAX_M + 5];
int dir[4][2] = {
    {-1, 0}, {1, 0},
    {0, -1}, {0, 1}
};
//bool visited[MAX_N + 5][MAX_M + 5]; 因为dist可以代替visited
int dist[MAX_N + 5][MAX_M + 5];//dist[i][j]表示i,j距离0,0的步数

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    return ;
}

int bfs() {
    // init dist[][]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;
        }
    }

    queue<PII> q;
    q.push(make_pair(0, 0));
    dist[0][0] = 0;

    while (!q.empty()) {
        PII node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = node.first + dir[i][0];
            int ny = node.second + dir[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != -1 || grid[nx][ny] == 1) continue;

            q.push(make_pair(nx, ny));
            dist[nx][ny] = dist[node.first][node.second] + 1;
        }
    }

    return dist[n - 1][m - 1];
}

void output() {
    cout << bfs() << endl;
    return ;
}


int main() {
    input();
    output();
    return 0;
}