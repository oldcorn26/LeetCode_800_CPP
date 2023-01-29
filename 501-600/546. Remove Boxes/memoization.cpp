#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, int> memo;
public:
    int removeBoxes(vector<int> &boxes) {

        if (boxes.empty()) return 0;

        int crtMax{checkMax(boxes)};
        if (crtMax) return crtMax;

        for (int i{0}; i < boxes.size(); ++i) {
            int l{i}, r{i};
            vector<int> next{boxes};
            while (l >= 1 && boxes[l - 1] == boxes[l]) --l;
            while (r + 1 < boxes.size() && boxes[r + 1] == boxes[r]) ++r;
            next.erase(next.begin() + l, next.begin() + r + 1);
            crtMax = max(crtMax, (r - l + 1) * (r - l + 1) + removeBoxes(next));
            i = r;
        }
        recordMemo(boxes, crtMax);

        return crtMax;
    }

    void recordMemo(vector<int> &boxes, int &max) {
        char str[boxes.size() + 1];
        for (int i{0}; i < boxes.size(); ++i) {
            str[i] = boxes[i];
        }
        memo.emplace(string(&str[0], &str[boxes.size()]), max);
    }

    int checkMax(vector<int> &boxes) {
        char str[boxes.size() + 1];
        for (int i{0}; i < boxes.size(); ++i) {
            str[i] = boxes[i];
        }
        auto iter = memo.find(string(&str[0], &str[boxes.size()]));
        return iter == memo.end() ? 0 : iter->second;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,3,2,2,2,3,4,3,1};
    int result = solution.removeBoxes(nums);
    cout << result;
    return 0;
}
