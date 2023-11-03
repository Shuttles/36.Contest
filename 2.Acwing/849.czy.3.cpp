// 1.dist[1] = 0, dist[i] = INF
// 2.s :当前已经确定最短距离的点的集合
//   for i 1~n
//      t:不在s中的距离最近的点
//      s.insert(t)
//      update all dist[] by t
// 时间O(n^2) 空间O(n^2)
#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 500
#define INF 0x3f3f3f3f
int n, m;
int graph[MAX_N + 5][MAX_N + 5];
int dist[MAX_N + 5];
bool s[MAX_N + 5];

void init()
{
    memset(graph, 0x3f, sizeof(graph));
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    return;
}

void input()
{
    init();
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }
    return;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        // 查找不在集合s中的最短距离节点
        int max_dist_id = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!s[j] && (max_dist_id == -1 || dist[max_dist_id] > dist[j]))
            {
                max_dist_id = j;
            }
        }
        s[max_dist_id] = true;

        // update all dist[] by dist[max_dist_id]
        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[max_dist_id] + graph[max_dist_id][j]);
        }
    }

    if (dist[n] == INF)
        return -1;
    return dist[n];
}

void output()
{
    int ans = dijkstra();
    cout << ans << endl;
    return;
}

int main()
{
    input();
    output();
    return 0;
}