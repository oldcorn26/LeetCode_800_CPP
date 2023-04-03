#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int size = arr.size();
        int idx{size-1};
        while (idx-1 >= 0 && arr[idx-1] <= arr[idx])
            idx--;
        if (idx == 0)
            return arr;
        int justBigger{size};
        while (arr[justBigger-1] >= arr[idx-1])
            justBigger--;
        int swapNum{arr[justBigger-1]};
        while (arr[justBigger-1] == swapNum)
            justBigger--;
        swap(arr[idx-1], arr[justBigger]);
        return arr;
    }
};

int main() {
    Solution solution;
    vector<int> values{3,1,1,3};
    vector<int> result = solution.prevPermOpt1(values);
    return 0;
}
