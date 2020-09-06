/* programmers
 * 야근 지수
 * https://programmers.co.kr/learn/courses/30/lessons/12927
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int M = works.size();
    int cur = 0, next = 0;
    
    sort(works.begin(), works.end(), greater<int>());
    while (1) {
        for (next = cur + 1; next < M; next++) {
            if (works[cur] != works[next]) break;
        }

        if (next == M) break;

        int N = n - ((works[cur] - works[next]) * next);
        if (N < 0) break;
        n = N;
        cur = next;
    }

    long long w = works[cur] - (long long)(n / next);
    if (w <= 0) return 0;

    n %= next;
    answer = w * w * (long long)(next - n);
    answer += ((w - 1) * (w - 1) * n);
    for (; next < works.size(); next++) {
        answer += ((long long)works[next] * works[next]);
    }

    return answer;
}
