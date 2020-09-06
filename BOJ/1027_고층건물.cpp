/* BOJ 1027
 * 고층 건물
 * https://www.acmicpc.net/problem/1027
 */
 
#include <iostream>
using namespace std;

int main() {
	int N;
	int height[51];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}

	int max_num = 0;
	for (int i = 0; i < N; i++) {
		int num = 0;
		double max_slope = -1000000005;
		for (int l = i - 1; l >= 0; l--) {
			double slope = (double)(height[l] - height[i]) / (double)(i - l);
			if (max_slope < slope) {
				max_slope = slope;
				num++;
			}
		}
        
		max_slope = -1000000005;
		for (int r = i + 1; r < N; r++) {
			double slope = (double)(height[r] - height[i]) / (double)(r - i);
			if (max_slope < slope) {
				max_slope = slope;
				num++; 
			}
		}

		if (max_num < num) {
			max_num = num;
		}
	}

	cout << max_num << '\n';

	return 0;
}
