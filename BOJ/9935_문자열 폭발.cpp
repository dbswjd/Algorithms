/* BOJ 9935
 * 문자열 폭발
 * https://www.acmicpc.net/problem/9935
 */

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

string str, burst;
deque<pair<int, int>> dq;

int position(char c) {
    for (int i = 0; i < burst.length(); i++) {
        if (c == burst[i])
            return i;
    }
    return -1;
}

string vacate() {
    string tmp;
    while (!dq.empty()) {
        int start = dq.front().first;
        int seq = dq.front().second;
        dq.pop_front();
        tmp.append(burst.substr(start, seq));
    }
    return tmp;
}

void push(int pos) {
    if (dq.empty()) {
        dq.push_back(make_pair(pos, 1));
        if (pos == 0 && burst.length() == 1) {
            dq.pop_back();
        }
        return;
    }

    int& start = dq.back().first;
    int& seq = dq.back().second;
    if (start + seq == pos) {
        seq++;
        if (start == 0 && seq == burst.length()) {
            dq.pop_back();
        }
    }
    else {
        dq.push_back(make_pair(pos, 1));
        if (pos == 0 && burst.length() == 1) {
            dq.pop_back();
        }
    }
}

int main() {
    string answer = "";
    cin >> str;
    cin >> burst;
    
    for (int i = 0; i < str.length(); i++) {
        int pos = position(str[i]);
        if (pos == -1) {
            answer.append(vacate());
            answer.push_back(str[i]);
        }
        else {
            push(pos);
        }
    }
    answer.append(vacate());
    
    

    if (answer.empty())
        cout << "FRULA\n";
    else
        cout << answer << '\n';
    return 0;
}
