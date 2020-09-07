/* programmers 
 * 게임 맵 최단거리
 * https://programmers.co.kr/learn/courses/30/lessons/1844
 */
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int x, y, cost;
};

int solution(vector<vector<int>> maps)
{
    int N = maps.size();
    int M = maps[0].size();

    int dx[] = { 0,0,1,-1 };
    int dy[] = { 1,-1,0,0 };

    queue<Node> q;
    vector<vector<bool>> visited(N, vector<bool>(M, 0));
    
    q.push(Node{ 0,0,1 });
    visited[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        q.pop();

        if (x == N - 1 && y == M - 1)
            return cost;

        cost++;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (maps[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                q.push(Node{ nx, ny, cost });
            }
        }
    }
    
    return -1;
}
