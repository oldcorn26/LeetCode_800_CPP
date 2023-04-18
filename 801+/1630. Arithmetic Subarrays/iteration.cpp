#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int nSize = nums.size(), rSize = l.size();
        vector<bool> ret(rSize);
        for (int i{}; i < rSize; ++i) {
            vector<int> temp(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(temp.begin(), temp.end());
            ret[i] = checkIfValid(temp);
        }
        return ret;
    }

    bool checkIfValid(vector<int> &vec) {
        if (vec.size() < 2) return false;
        int interval{vec[1] - vec[0]};
        for (int i{2}; i < vec.size(); ++i)
            if (vec[i]-vec[i-1] != interval)
                return false;
        return true;
    }
};

int main() {
    Solution solution;
    return 0;
}
