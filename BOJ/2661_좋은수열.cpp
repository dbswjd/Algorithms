/* BOJ 2661
 * 좋은수열
 * https://www.acmicpc.net/problem/2661
 */
#include <iostream>
#include <string>
using namespace std;

int N;
string answer;

bool subsequence(int e, int k) {
    for (int i = 1; i < k - e; i++) {
        if (answer[e - i] != answer[k - i]) return false;
    }
    return true;
}

bool check(int k) {
    for (int e = k - 1; e >= k / 2; e--) {
        if (answer[e] == answer[k]) {
            if (subsequence(e, k)) {
                return false;
            }
        }
    }
    return true;
}

int sequence(int k) {
    if (k == N) return 1;
    for (int n = 0; n < 3; n++) {
        answer.push_back('1' + n);
        if (check(k)) {
            if (sequence(k + 1)) return 1;
        }
        answer.pop_back();
    }
    return 0;
}

int main() {
    cin >> N;
    answer = "";
    sequence(0);
    cout << answer;
    return 0;
}
