#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int> &machines) {

        int size = machines.size();
        int sum{accumulate(machines.begin(), machines.end(), 0)};
        int per{sum / size}, ret{0}, prefixSum{0};

        if (sum % size) return -1;
        for (int &num: machines) {
            num -= per;
            prefixSum += num;
            ret = max(ret, max(abs(prefixSum), num));
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> machines{40793,12738,27572,93863,17303,37855,19546,29929,15531,1628,80067,14541,82699,93383,28048,76365,8140,42001,99204,12195,65193,50994,87891,99991,69475,6522,1490,34690,38210,36015,39245,15935,84282,89992,55607,30573,98921,91429,85820,23171,6844,22984,13203,58321,95797,60564,62319,67822,64568,20928,73941,3651,67346,85656,83591,57396,74715,81137,77535,38374,54661,29543,11479,49714,90745,21237,80677,74756,85954,21711,17573,87184,57029,66783,18478,21170,16520,46171,37190,27456,5428,23328,69457,75630,4501,25933,57285,37246,23934,40318,29593,6882,40617,27298,83100,76015,92124,86588,78337,25216};
    int result = solution.findMinMoves(machines);
    cout << result;
    return 0;
}
