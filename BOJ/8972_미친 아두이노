/* BOJ 8972
 * 미친 아두이노
 * https://www.acmicpc.net/problem/8972
 */

#include <iostream>
#include <climits>
using namespace std;

int R, C;
int x, y;
char board[2][101][101];

int dx[] = { 0,1,1,1,0,0,0,-1,-1,-1 };
int dy[] = { 0,-1,0,1,-1,0,1,-1,0,1 };

void print_board(int cur) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[cur][i][j] == 'F')
                board[cur][i][j] = '.';
            cout << board[cur][i][j];
        }
        cout << '\n';
    }
}

int move_R(int next, int r, int c) {
    int nr, nc;
    if (x < r) nr = r - 1;
    else if (x > r) nr = r + 1;
    else nr = r;

    if (y < c) nc = c - 1;
    else if (y > c) nc = c + 1;
    else nc = c;

    if (board[next][nr][nc] == '.')
        board[next][nr][nc] = 'R';
    else if (board[next][nr][nc] == 'R')
        board[next][nr][nc] = 'F';
    else if (board[next][nr][nc] == 'I')
        return 1;
    return 0;
}


int movement(int cur, int dir) {
    int next = 1 - cur;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            board[next][i][j] = '.';
        }
    }

    //move I
    x += dx[dir];
    y += dy[dir];
    if (board[cur][x][y] == 'R')
        return 1;
    board[next][x][y] = 'I';

    //move R
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[cur][i][j] == 'R') {
                if (move_R(next, i, j))
                    return 1;
            }
        }
    }

    return 0;
}

void find_I() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[0][i][j] == 'I') {
                x = i;
                y = j;
                return;
            }
        }
    }
}

int main() {
    int cur = 0;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[cur][i][j];
        }
    }

    string directions;
    cin >> directions;

    find_I();

    for (int i = 0; i < directions.length(); i++) {
        if (movement(cur, directions[i] - '0')) {
            cout << "kraj " << i + 1 << '\n';
            return 0;
        }
        cur = 1 - cur;
    }

    print_board(cur);

    return 0;
}
