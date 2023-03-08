#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> left(size, 1);
        for (int i{1}; i < size; ++i) {
            if (ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
        }
        int ret{max(1, left[size-1])}, pre{1};
        for (int i{size - 2}; i >= 0; --i) {
            int crt{ratings[i] > ratings[i+1] ? pre+1 : 1};
            ret += max(crt, left[i]);
            pre = crt;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> ratings{1,2,2};
    int result = solution.candy(ratings);
    cout << result;
    return 0;
}