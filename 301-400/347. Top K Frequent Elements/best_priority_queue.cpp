#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct myComparison {
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> pq;
        unordered_map<int, int> hashMap;
        for (int &i: nums) ++hashMap[i];
        for (auto iter = hashMap.begin(); iter != hashMap.end(); ++iter) {
            if (pq.size() < k) pq.emplace(iter->first, iter->second);
            else if (pq.top().second < iter->second) {
                pq.pop();
                pq.emplace(iter->first, iter->second);
            }
        }
        vector<int> res(pq.size());
        for (int &iter: res) {
            iter = pq.top().first;
            pq.pop();
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2};
    vector<int> result = solution.topKFrequent(nums, 2);
    return 0;
}