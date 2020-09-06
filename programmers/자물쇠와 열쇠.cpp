/* programmers
 * 자물쇠와 열쇠
 * https://programmers.co.kr/learn/courses/30/lessons/60059
 */
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate_key(vector<vector<int>>& key) {
    int M = key.size();
    vector<vector<int>> new_key(M, vector<int>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            new_key[j][M - i - 1] = key[i][j];
        }
    }
    return new_key;
}

bool check(int x, int y, const vector<vector<int>> &key, const vector<vector<int>> &lock) {
    int N = lock.size();
    int M = key.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (x <= i && i < x + M && y <= j && j < y + M) {
                if (!(lock[i][j] ^ key[i - x][j - y]))
                    return 0;
            }
            else {
                if (!lock[i][j])
                    return 0;
            }
        }
    }
    return 1;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock.size();
    int M = key.size();
    
    for (int k = 0; k < 4; k++) { //rotate key
        for (int x = 1 - M; x < N; x++) {
            for (int y = 1 - M; y < N; y++) {
                if (check(x, y, key, lock))
                    return 1;
            }
        }
        key = rotate_key(key);
    }

    return 0;
}
