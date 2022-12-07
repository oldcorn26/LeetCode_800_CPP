#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        int idx = -1;
        unordered_map<int, int> hashMap;
        for (int &i: nums) ++hashMap[i];
        vector<pair<int, int>> frequencyMap(hashMap.size());

        for (auto iter = hashMap.begin(); iter != hashMap.end(); ++iter) {
            frequencyMap[++idx] = {iter->second ,iter->first};
        }
        quickSelect(frequencyMap, 0, hashMap.size() - 1, k);
        vector<int> res(k);
        for (int i = 0; i < k; ++i) {
            res[i] = frequencyMap[i].second;
        }

        return res;
    }

    void quickSelect(vector<pair<int, int>> &fre, int &&left, int &&right, int &k) {
        pair<int, int> pivot = fre[left];
        int i = left, j = right;

        while (i < j) {
            while (i < j && fre[j].first < pivot.first) --j;
            if (i < j) fre[i++] = fre[j];
            while (i < j && fre[i].first >= pivot.first) ++i;
            if (i < j) fre[j--] = fre[i];
        }
        fre[i] = pivot;
        if (i + 1 == k) return;
        else if (i + 1 < k) quickSelect(fre, i + 1, move(right), k);
        else quickSelect(fre, move(left), i - 1, k);
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2};
    vector<int> result = solution.topKFrequent(nums, 2);
    return 0;
}