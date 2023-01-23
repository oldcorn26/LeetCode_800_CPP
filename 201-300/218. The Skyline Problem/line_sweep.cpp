#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {

        int size = buildings.size();
        int &&doubleSize{size * 2};
        int vecIdx{-1}, preH{-1};
        priority_queue<pair<int, int>> pq{less<pair<int, int>>()};
        vector<int> orderedX(doubleSize);
        vector<vector<int>> ret;

        for (int i{0}; i < size; ++i) {
            orderedX[2 * i] = buildings[i][0];
            orderedX[2 * i + 1] = buildings[i][1];
        }
        sort(orderedX.begin(), orderedX.end());
        pq.emplace(0, INT32_MAX);

        for (int i{0}; i < doubleSize; ++i) {
            if (i && orderedX[i - 1] == orderedX[i]) continue;
            while (vecIdx + 1 < size && buildings[vecIdx + 1][0] <= orderedX[i]) {
                ++vecIdx;
                pq.emplace(buildings[vecIdx][2], buildings[vecIdx][1]);
            }
            while (pq.size() > 1 && pq.top().second <= orderedX[i]) pq.pop();
            if (pq.top().first != preH) ret.push_back({orderedX[i], pq.top().first});
            preH = pq.top().first;
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> buildings{{0,2,3},{2,5,3}};
    vector<vector<int>> result = solution.getSkyline(buildings);
    return 0;
}
