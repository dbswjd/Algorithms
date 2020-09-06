/* BOJ 6549
 * 히스토그램에서 가장 큰 직사각형
 * https://www.acmicpc.net/problem/6549
 */
 
#include <iostream>
#include <stack>
using namespace std;

int N;
int height[100001];

long long max(long long a, long long b) {
	return (a > b) ? a : b;
}

long long max(long long a, long long x, long long y) {
	x *= y;
	return (a > x) ? a : x;
}

int main() {
	for (cin >> N; N > 0; cin >> N) {
		for (int i = 0; i < N; i++) {
			cin >> height[i];
		}

		long long maxArea = 0;
		stack<pair<int, int>> s;
		for (int i = 0; i < N; ++i) {
			int width = 0;
			while (!s.empty()) {
				if (s.top().first < height[i]) break;
				width += s.top().second;
				maxArea = max(maxArea, s.top().first, width);
				s.pop();
			}
			s.push(make_pair(height[i], width + 1));
		}

		int width = 0;
		while (!s.empty()) {
			s.top().second += width;
			width = s.top().second;
			maxArea = max(maxArea, s.top().first, s.top().second);
			s.pop();
		}

		cout << maxArea << '\n';
	}
	return 0;
}
