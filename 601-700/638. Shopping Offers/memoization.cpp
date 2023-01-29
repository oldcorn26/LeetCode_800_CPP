#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, int> memo;
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {

        int cost{checkMinCost(needs)};
        if (cost != -1) return cost;

        cost = 10000;
        for (vector<int> &vec: special) {
            int i{0};
            vector<int> next(needs);
            for (; i < next.size(); ++i) {
                if (vec[i] > next[i]) break;
                next[i] -= vec[i];
            }
            if (i != next.size()) continue;
            cost = min(cost, vec[next.size()] + shoppingOffers(price, special, next));
        }

        int singleCost{0};
        for (int i{0}; i < needs.size(); ++i) {
            singleCost += needs[i] * price[i];
        }
        cost = min(cost, singleCost);
        saveMinCost(needs, cost);
        return cost;
    }

    void saveMinCost(vector<int> &vec, int cost) {
        char str[7]{0,0,0,0,0,0,'\0'};
        for (int i{0}; i < vec.size(); ++i) {
            str[i] = vec[i];
        }
        memo.emplace(string(&str[0], &str[6]), cost);
    }

    int checkMinCost(vector<int> &vec) {
        char str[7]{0,0,0,0,0,0,'\0'};
        for (int i{0}; i < vec.size(); ++i) {
            str[i] = vec[i];
        }
        auto iter = memo.find(string(&str[0], &str[6]));
        return iter == memo.end() ? -1 : iter->second;
    }
};

int main() {
    Solution solution;
    vector<int> price{2,5};
    vector<vector<int>> special{{3,0,5},{1,2,10}};
    vector<int> needs{3,2};
    int result = solution.shoppingOffers(price, special, needs);
    cout << result;
    return 0;
}
