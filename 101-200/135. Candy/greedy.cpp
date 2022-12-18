#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        int inc{1}, dec{0}, pre{1}, res{1};
        for (int i{1}; i < size; ++i) {
            if (ratings[i - 1] <= ratings[i]) {
                dec = 0;
                pre = ratings[i - 1] == ratings[i] ? 1 : pre + 1;
                inc = pre;
                res += pre;
            } else {
                ++dec;
                if (dec == inc) ++dec;
                res += dec;
                pre = 1;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> ratings{1,2,2};
    int result = solution.candy(ratings);
    cout << result;
    return 0;
}