#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        // 4,5,6,7,0,1,2
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (nums[middle] == target) {
                return middle;
            }
            for (int i = low; i <= middle; ++i) {
                if (nums[i] == target) { 
                    return i;
                }
            }
            
            low = middle + 1;
        }

        return -1;
    }
};

int main() {
    Solution soln = Solution();

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << soln.search(nums, target) << endl;

    return 0;
}
