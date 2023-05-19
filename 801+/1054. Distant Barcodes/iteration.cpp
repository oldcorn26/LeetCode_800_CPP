#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if (barcodes.size() == 1)
            return barcodes;
        int pre{};
        unordered_map<int, int> count;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;
        for (int i: barcodes)
            count[i]++;
        for (auto &iter: count)
            pq.emplace(iter.second, iter.first);
        for (int i{}; i < barcodes.size(); ++i) {
            auto st{pq.top()};
            pq.pop();
            auto nd{pq.top()};
            pq.pop();
            barcodes[i++] = st.second != pre ? st.second : nd.second;
            barcodes[i] = st.second != barcodes[i - 1] ? st.second : nd.second;
            pq.emplace(st.first - 1, st.second);
            pq.emplace(nd.first - 1, nd.second);
        }
        if (barcodes.size() % 2)
            barcodes[barcodes.size() - 1] = pq.top().second;
        return barcodes;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1};
    vector<int> result = solution.rearrangeBarcodes(nums);
    return 0;
}
