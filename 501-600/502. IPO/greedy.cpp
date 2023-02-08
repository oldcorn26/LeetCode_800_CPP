#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {

        int size = profits.size();
        int crtIdx{0};
        priority_queue<int, vector<int>, less<>> pq;
        vector<pair<int,int> > arr(size);

        for (int i{0}; i < size; ++i) {
            arr[i] = {capital[i], profits[i]};
        }
        sort(arr.begin(), arr.end());
        for (int i{0}; i < k; ++i) {
            while (crtIdx < size && arr[crtIdx].first <= w) {
                pq.push(arr[crtIdx].second);
                crtIdx++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else {
                break;
            }
        }

        return w;
    }
};

int main() {
    Solution solution;
    vector<int> profits{1,2,3};
    vector<int> capital{0,1,1};
    int result = solution.findMaximizedCapital(2, 0, profits, capital);
    cout << result;
    return 0;
}
