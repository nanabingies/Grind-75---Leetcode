#include <vector>
#include <iostream>
#include <functional>
#include <numeric>
using namespace std;

class Solution {
public:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::function<void(int, vector<int>&, vector<int>&, int, vector<vector<int>>&)> getSum;
        vector<vector<int>> sum{};
        vector<int> u_v{};

        std::sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        getSum = [&](int start, vector<int>& candidates, vector<int>& u_v, int target, vector<vector<int>>& sum) -> void {
            if (target == 0) { 
                sum.push_back(u_v);
                return;
            }

            for (auto idx = start; idx != candidates.size(); ++idx) {
                int currVal = candidates[idx];
                if (currVal > target) {
                    break;
                }

                u_v.push_back(currVal);

                getSum(idx, candidates, u_v, target - currVal, sum);

                u_v.pop_back();
            }
        };

        getSum(0, candidates, u_v, target, sum);
        
        return sum;
    }
};

void print_result(vector<vector<int>>& vec) {
    for (auto _ : vec) {
        for (auto __ : _) {
            std::cout << __ << " ";
        }
        putchar('\n');
    }
    putchar('\n');
}

int main() {
    Solution soln = Solution();

    vector<int> candidates = {2,3,6,7};
    int target = 7;

    auto res = soln.combinationSum(candidates, target);
    print_result(res);
}
