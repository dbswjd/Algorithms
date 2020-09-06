/* BOJ 38709
 * 레이저빔은 어디로
 * https://www.acmicpc.net/problem/3709
 */

#include <iostream>

using namespace std;

int main() {
	int T; cin >> T;
	
	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,1,0,-1 };
	bool board[55][55] = { 0, };
	bool visited[55][55][4] = { 0, };

	while (T--) {
		int n, r;
		cin >> n >> r;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				board[i][j] = 0;
				for (int d = 0; d < 4; d++)
					visited[i][j][d] = 0;
			}
		}
		for (int i = 0; i < r; i++) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}
		
		int x, y, dir;
		cin >> x >> y;
		if (x == 0) dir = 2;
		else if (x == n + 1) dir = 0;
		else if (y == 0) dir = 1;
		else dir = 3;

		for (x += dx[dir], y += dy[dir]; 0 < x && x <= n && 0 < y && y <= n; x += dx[dir], y += dy[dir]) {
			if (visited[x][y][dir]) {
				x = 0; y = 0;
				break;
			}
			visited[x][y][dir] = 1;
			if (board[x][y]) {
				dir = (dir + 1) % 4;
			}
		}
		cout << x << " " << y << '\n';
	}

	return 0;
}
