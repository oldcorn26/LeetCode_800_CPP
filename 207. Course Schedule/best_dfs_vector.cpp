#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> map;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map.resize(numCourses);
        for (vector<int> &vec: prerequisites) map[vec[0]].push_back(vec[1]);

        for (int i = 0; i < numCourses; ++i) {
            if (map[i].empty()) continue;
            else if (checkIfLoop(i)) return false;
        }

        return true;
    }

    bool checkIfLoop(int &idx) {
        for (int j = 0; j < map[idx].size(); ++j) {
            if (map[idx][j] >= 0) {
                int temp = map[idx][j];
                map[idx][j] = -1;
                if (checkIfLoop(temp)) return true;
            } else if (map[idx][j] == -1) return true;
        }

        map[idx].clear();
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> pre{{1,4},{2,4},{3,1},{3,2}};
    bool result = solution.canFinish(5, pre);
    cout << result;
    return 0;
}
