#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int size = temperatures.size();
        stack<int, vector<int>> monStack;
        vector<int> res(size);
        for (int i{0}; i < size; ++i) {
            while (monStack.size() && temperatures[monStack.top()] < temperatures[i]) {
                int &temp{monStack.top()};
                res[temp] = i - temp;
                monStack.pop();
            }
            monStack.emplace(i);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> temperatures{73,74,75,71,69,72,76,73};
    vector<int> result = solution.dailyTemperatures(temperatures);
    return 0;
}