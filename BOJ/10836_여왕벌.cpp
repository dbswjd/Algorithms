/* BOJ 10836 
 * 여왕벌
 * https://www.acmicpc.net/problem/10836
 */
#include <iostream>
#include <algorithm>
using namespace std;

int M, N;
int worms[701][701];
int add[701];

void grow(int zero, int one, int two) {
    int t = M - two;
    if (t < 1) t = 1;
    for (int i = t; i < M; i++) {
        add[i] += 2;
    }
    int o = t - one;
    if (o < 1) o = 1;
    for (int i = o; i < t; i++) {
        add[i]++;
    }
    

    for (int c = M - 1; c >= 0; c--) {
        if (two) {
            worms[0][c] += 2;
            two--;
        }
        else if (one) {
            worms[0][c]++;
            one--;
        }
        else break;
    }

    for (int r = 1; r < M; r++) {
        if (two) {
            worms[r][0] += 2;
            two--;
        }
        else if (one) {
            worms[r][0]++;
            one--;
        }
        else break;
    }
}

void print() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cout << worms[i][j] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        add[i] = 0;
        for (int j = 0; j < M; j++) {
            worms[i][j] = 1;
        }
    }

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        grow(a, b, c);
    }

    for (int c = 1; c < M; c++) {
        add[c]++;
        for (int r = 1; r < M; r++) {
            worms[r][c] = add[c];
        }
    }

    print();
    return 0;
}
