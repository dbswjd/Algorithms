/* programmers
 * 튜플
 * https://programmers.co.kr/learn/courses/30/lessons/64065
 */

#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool cmp(const vector<int> &a, const vector<int>& b) {
    return a.size() < b.size();
}

vector<vector<int>> str_to_vec(string s) {
    vector<vector<int>> sets;
    vector<int> v;
    string num = "";
    for (int i = 2; i < s.length(); i++) {
        if (s[i] == '}') {
            v.push_back(stoi(num));
            num = "";
            sets.push_back(v);
            v = vector<int>();
            i += 2;
        }
        else if (s[i] == ',') {
            v.push_back(stoi(num));
            num = "";
        }
        else {
            num.push_back(s[i]);
        }
    }
    return sets;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> sets = str_to_vec(s);
    sort(sets.begin(), sets.end(), cmp);

    set<int> nums;
    for (int i = 0; i < sets.size(); i++) {
        for (int j = 0; j < sets[i].size(); j++) {
            if (nums.insert(sets[i][j]).second) {
                answer.push_back(sets[i][j]);
            }
        }
    }

    return answer;
}
