#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> u_m{};

        if (nums.size() == 1) {
            return nums[0];
        }
        
        for (int idx = 0; idx != n; ++idx) {
            if (u_m.find(nums[idx]) == u_m.end()) {
                u_m[nums[idx]] = 1;
            } else {
                u_m[nums[idx]] += 1;
                if (u_m[nums[idx]] > (n / 2)) {
                    return nums[idx];
                }
            }
        }

        return 0;
    }
};

void print_vector(vector<int>& arr) {
    for (auto _ : arr) {
        std::cout << _ << " ";
    }
    putchar('\n');
}

int main() {
    Solution soln = Solution();

    vector<int> nums = { 3,2,3 };
    auto res = soln.majorityElement(nums);
    std::cout << res << std::endl;

    nums = { 2,2,1,1,1,2,2 };
    res = soln.majorityElement(nums);
    std::cout << res << std::endl;

    return 0;
}