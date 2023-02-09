#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>> &courses) {

        auto cmp = [](vector<int> &x, vector<int> &y) {
            if (x[1] != y[1]) return x[1] < y[1];
            else return x[0] < y[0];
        };

        int size = courses.size();
        int crtSum{0}, ret{0};
        priority_queue<int, vector<int>, less<>> q;

        sort(courses.begin(), courses.end(), cmp);
        for (int i{0}; i < size; ++i) {
            if (crtSum + courses[i][0] <= courses[i][1]) {
                crtSum += courses[i][0];
                q.emplace(courses[i][0]);
                ++ret;
            } else if (q.size() && q.top() > courses[i][0] && crtSum - q.top() + courses[i][0] <= courses[i][1]) {
                crtSum += courses[i][0] - q.top();
                q.pop();
                q.emplace(courses[i][0]);
            }
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> courses{{{7,17},{3,12},{10,20},{9,10},{5,20},{10,19},{4,18}}};
    int result = solution.scheduleCourse(courses);
    cout << result;
    return 0;
}
