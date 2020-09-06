/* programmers
 * 이중우선순위큐
 * https://programmers.co.kr/learn/courses/30/lessons/42628
 */
#include <string>
#include <vector>
#include <list>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    list<int> num;
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i].compare("D 1") == 0) {
            if (!num.empty())
                num.pop_back();
        }
        else if (operations[i].compare("D -1") == 0) {
            if (!num.empty())
                num.pop_front();
        }
        else {
            int x = stoi(operations[i].substr(2));
            list<int>::iterator it;
            for (it = num.begin(); it != num.end(); it++) {
                if (x < *it) break;
            }
            num.insert(it, x);
        }
    }

    if (num.empty()) {
        answer.push_back(0); 
        answer.push_back(0);
    }
    else {
        answer.push_back(num.back());
        answer.push_back(num.front());
    }
    return answer;
}
