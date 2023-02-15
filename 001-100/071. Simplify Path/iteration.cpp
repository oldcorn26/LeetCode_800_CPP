#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int crtIdx{0};
        deque<string> d;
        string ret{""};
        while (crtIdx < path.size()) {
            while (crtIdx < path.size() && path[crtIdx] == '/') ++crtIdx;
            if (crtIdx == path.size()) break;
            int next{crtIdx + 1};
            while (next < path.size() && path[next] != '/') ++next;
            string &&fileName{path.substr(crtIdx, next - crtIdx)};
            if (fileName == "..") {
                if (d.size()) d.pop_back();
            } else if (fileName != ".") {
                d.emplace_back(fileName);
            }
            crtIdx = next;
        }
        while (d.size()) {
            ret += "/" + d.front();
            d.pop_front();
        }
        return ret.empty() ? "/" : ret;
    }
};

int main() {
    Solution solution;
    string result = solution.simplifyPath("/a/./b/../../c/");
    cout << result;
    return 0;
}
