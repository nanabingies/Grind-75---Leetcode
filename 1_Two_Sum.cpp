#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::unordered_map<int, int> u_m;
            std::vector<int> results;
            std::printf("Entry!!!\n");

            for (size_t iter = 0; iter != nums.size(); iter++) {
                if (u_m.count(target - nums[iter])) {
                    results.push_back(u_m[target - nums[iter]]);
                    results.push_back(iter);
                    return results;
                }
                u_m[nums[iter]] = iter;
            }
            return results;
        }
};

int main(int argc, char* argv[]) {
    Solution soln;
    int target = 9;

    std::vector<int> nums = { 2, 7, 11, 15 };
    std::vector<int> res = soln.twoSum(nums, target);
    for (auto& num : res) {
        std::cout << num;
    }
    std::putchar('\n');
 
    target = 6;
    nums = { 3,2,4 };
    res = soln.twoSum(nums, target);
    for (auto& num : res) {
        std::cout << num;
    }
    std::putchar('\n');

    return 0;
}
