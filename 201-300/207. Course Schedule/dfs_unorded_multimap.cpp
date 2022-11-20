#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_multimap<int, int> map;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        for (vector<int> &vec: prerequisites) map.insert({vec[0], vec[1]});

        while (!map.empty()) {
            int temp = map.begin()->first;
            if (checkIfLoop(temp)) return false;
            else map.erase(temp);
        }

        return true;
    }

    bool checkIfLoop(int &idx) {
        for (auto [b, e] = map.equal_range(idx); b != e; ++b) {
            if (b->second >= 0) {
                int temp = b->second;
                b->second = -2;
                if (checkIfLoop(temp)) return true;
                else b->second = -1;
            } else if (b->second == -2) return true;
        }

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
