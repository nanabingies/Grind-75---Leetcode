#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] == target) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution soln = Solution();

    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout << soln.search(nums, target) << endl;

    nums = {-1,0,3,5,9,12};
    target = 2;
    cout << soln.search(nums, target) << endl;

    return 0;
}
