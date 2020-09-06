/* BOJ 1744
 * 수 묶기
 * https://www.acmicpc.net/problem/1744
 */

#include <iostream>
#include <algorithm>
using namespace std;

int p = 0, pos[10001];
int n = 0, neg[10001];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x < 0) neg[n++] = x;
        else if (x > 0) pos[p++] = x;
    }
        
    sort(neg, neg + n);
    sort(pos, pos + p, greater<int>());

    int answer = 0;
    for (int i = 1; i < n; i += 2) {
        answer += (neg[i - 1] * neg[i]);
    }
    if ((n % 2) && (p + n == N)) 
            answer += neg[n - 1];

    while (pos[p - 1] == 1) {
        answer++;
        p--;
    }
    if (p % 2) answer += pos[p - 1];
    for (int i = 1; i < p; i += 2)
        answer += (pos[i - 1] * pos[i]);

    cout << answer << '\n';

    return 0;
}
