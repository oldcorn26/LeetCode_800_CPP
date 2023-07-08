#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int finished{};
        unordered_map<int, vector<int>> um;
        vector<int> count(numCourses);
        queue<int> valid;
        for (auto &vec: prerequisites) {
            count[vec[0]]++;
            um[vec[1]].push_back(vec[0]);
        }
        while (finished < numCourses) {
            for (int i{}; i < numCourses; ++i) {
                if (count[i] == 0) {
                    count[i]--;
                    valid.push(i);
                    finished++;
                }
            }
            if(valid.empty())
                return false;
            while (!valid.empty()) {
                auto &edge{um[valid.front()]};
                for (int i: edge)
                    count[i]--;
                valid.pop();
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> pre{{1,4},{2,4},{3,1},{3,2}};
    bool result = solution.canFinish(5, pre);
    cout << result;
    return 0;
}
