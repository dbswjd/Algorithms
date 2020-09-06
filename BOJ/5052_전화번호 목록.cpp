/* BOJ 5052
 * 전화번호 목록
 * https://www.acmicpc.net/problem/5052
 */

#include <iostream>

using namespace std;

class Trie {
    bool term;
    Trie* child[10];
public:
    Trie() :term(false) {
        for (int i = 0; i < 10; i++)
            child[i] = NULL;
    }
    ~Trie() {
        for (int i = 0; i < 10; i++)
            if (child[i])
                delete child[i];
    }

    bool insert(const char* str) {
        if (*str == '\0') {
            term = true;
            for(int i=0;i<10;i++)
                if (child[i]) return false;
            return true;
        }

        if (term)
            return false;

        int n = *str - '0';
        if (child[n] == NULL)
            child[n] = new Trie();
        return child[n]->insert(str + 1);
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        bool answer = true;
        Trie* root = new Trie();
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            string str;
            cin >> str;
            if (answer) {
                answer = root->insert(str.c_str());
            }
        }

        if (answer)
            cout << "YES\n";
        else
            cout << "NO\n";

        delete root;
    }
    return 0;
}
