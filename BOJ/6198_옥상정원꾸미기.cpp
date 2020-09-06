/* BOJ 6198
 * 옥상 정원 꾸미기
 * https://www.acmicpc.net/problem/6198
 */
#include <iostream>
#include <stack>
using namespace std;

int N;
int height[80001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}

	long long answer = 0;
	stack<pair<int, int>> s;
	for (int i = N - 1; i >= 0; --i) {
		int n = 0;
		while (!s.empty()) {
			if (s.top().first < height[i]) {
				n += s.top().second;
				s.pop();
			}
			else break;
		}
		answer += n;
		s.push(make_pair(height[i], n + 1));
	}

	cout << answer << endl;

	return 0;
}
