#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int rem{0};
        for(int i{0}, j; i < n;){
            for(j = 0; j < n; ++j){
                int &&idx{(i+j) % n};
                rem = rem + gas[idx] - cost[idx];
                if(rem < 0) break;
            }
            if(n == j) return i;
            i = i + j + 1;
            rem = 0;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> gas{1,2,3,4,5}, cost{3,4,5,1,2};
    int result = solution.canCompleteCircuit(gas, cost);
    cout << result;
    return 0;
}