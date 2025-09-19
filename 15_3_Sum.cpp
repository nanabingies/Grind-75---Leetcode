#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results{};
        std::sort(nums.begin(), nums.end());

        // -4, -1, -1, 0, 1, 2
        for (int idx = 0; idx != nums.size(); ++idx) {

            if (idx > 0 && nums[idx] == nums[idx - 1]) continue;

            int left = idx + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[idx] + nums[right];
                
                if (sum == 0) {
                    vector<int> s_v = { nums[left], nums[idx], nums[right] };
                    results.push_back(s_v);

                    // Skip duplicates for left & right pointers
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    
                    ++left;
                    --right;
                }
                else if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                }
            }
        }

        return results;

    }

    /*vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results{};

        for (int i = 0; i != nums.size(); ++i) {
            for (int j = i + 1; j != nums.size(); ++j) {
                for (int k = j + 1; k != nums.size(); ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> sum = { nums[i], nums[j], nums[k] };
                        sort(sum.begin(), sum.end());
                        auto it = std::find_if(results.begin(), results.end(), [&](const std::vector<int>& vec) {
                            return vec == sum;
                        });
                        if (it == results.end()) {
                            results.push_back(sum);
                        }
                    }
                }
            }
        }

        return results;
    }*/
};

void print_results(vector<vector<int>>& vec) {
    for (auto _ : vec) {
        for (auto __ : _) {
            cout << __ << " ";
        }
        putchar('\n');
    }
    putchar('\n');
}

int main() {
    Solution soln = Solution();

    std::vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    auto res = soln.threeSum(nums);
    print_results(res);

    nums = { 0,1,1 };
    res = soln.threeSum(nums);
    print_results(res);

    nums = {0,0,0};
    res = soln.threeSum(nums);
    print_results(res);

    return 0;
}
