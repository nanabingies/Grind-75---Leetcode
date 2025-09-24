#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 2,0,0,0,0,1,2,2
        for (int idx = 0; idx != nums.size(); ++idx) {
            int left = idx;
            int right = nums.size() - 1;

            while (left <= right) {
                if (nums[left] > nums[right]) {
                    std::swap(nums[left], nums[right]);
                }
                ++left;
                --right;
            }
        }

        for (int idx = 0; idx != nums.size(); ++idx) {
            int left = 0;
            int right = idx;
            while (left < right) {
                if (nums[left] > nums[right]) {
                    std::swap(nums[left], nums[right]);
                }
                ++left;
                //--right;
            }
        }
    }
};

void printResults(vector<int> vec) {
    for (auto _vec : vec) {
        std::cout << _vec << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution soln = Solution();

    vector<int> nums = {2,0,2,1,1,0};
    soln.sortColors(nums);
    printResults(nums);

    nums = {2,0,1};
    soln.sortColors(nums);
    printResults(nums);

    nums = {2,0,0,0,0,1,2,2};
    soln.sortColors(nums);
    printResults(nums);

    return 0;
}
