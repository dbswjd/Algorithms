/* programmers
 * 배달
 * https://programmers.co.kr/learn/courses/30/lessons/12978
 */
 
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; 
    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < road.size(); i++) {
        adj[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        adj[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }

    dist[1] = 0;
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        int time = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (time > K) break;
        if (dist[cur] < time) continue;
        answer++;
        
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            int t = time + adj[cur][i].second;
            if (t < dist[next]) {
                dist[next] = t;
                pq.push(make_pair(t, next));
            }   
        }
    }

    return answer;
}
