/* BOJ 1005
 * ACM Craft
 * https://www.acmicpc.net/problem/1005
 */
#include <iostream>
#include <vector>
using namespace std;

int N, K, W;
int t[1001];
int comp[1001];
vector<vector<int>> parents;

int max(int a, int b){
    return (a > b) ? a : b;
}

int completion_time(int x) {
    if (comp[x] != -1)
        return comp[x];

    int maxT = 0;
    for (vector<int>::iterator it = parents[x].begin(); it != parents[x].end(); it++) {
        maxT = max(maxT, completion_time(*it));
    }

    comp[x] = maxT + t[x];
    return comp[x];
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> t[i];
            comp[i] = -1;
        }

        parents.assign(N + 1, vector<int>());
        for (int i = 0; i < K; i++) {
            int x, y; cin >> x >> y;
            parents[y].push_back(x);
        }
        cin >> W;

        //cout << "answer: ";
        cout << completion_time(W) << '\n';
        //for (int i = 1; i <= N; i++)
           // cout << comp[i] << " ";
        //cout << endl;
    }
    return 0;
}
