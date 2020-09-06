/* programmers
 * 길 찾기 게임
 * https://programmers.co.kr/learn/courses/30/lessons/42892
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
    int id;
    int x;
    Node* left;
    Node* right;
public:
    Node() {}
    Node(int _id, int _x) :id(_id), x(_x) {
        left = NULL;
        right = NULL;
    }
    ~Node() {
        if (left) delete left;
        if (right) delete right;
    }

    void insert(int _id, int _x) {
        if (_x < x) {
            if (left) left->insert(_id, _x);
            else left = new Node(_id, _x);
        }
        else {
            if (right) right->insert(_id, _x);
            else right = new Node(_id, _x);
        }
    }

    void preorder(vector<int> &order) {
        order.push_back(id);
        if (left) left->preorder(order);
        if (right) right->preorder(order);
    }

    void postorder(vector<int>& order) {
        if (left) left->postorder(order);
        if (right) right->postorder(order);
        order.push_back(id);
    }
};

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] > b[1];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    for (int i = 0; i < nodeinfo.size(); i++) 
        nodeinfo[i].push_back(i + 1);
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);

    Node* root = new Node(nodeinfo[0][2], nodeinfo[0][0]);
    for (int i = 1; i < nodeinfo.size(); i++)
        root->insert(nodeinfo[i][2], nodeinfo[i][0]);

    root->preorder(answer[0]);
    root->postorder(answer[1]);

    return answer;
}
