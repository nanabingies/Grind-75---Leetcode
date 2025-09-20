#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n, 1);

        int prefix = 1;
        for (int idx = 0; idx < n; ++idx) {
            results[idx] = prefix;
            prefix *= nums[idx];
        }

        int suffix = 1;
        for (auto idx = n - 1; idx >= 0; --idx) {
            results[idx] *= suffix;
            suffix *= nums[idx];
        }

        return results;
    }

    /*vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer {};
        
        for (auto idx = 0; idx != nums.size(); ++idx) {
            int left = 0;
            int right = nums.size() - 1;
            int product = 1;

            while (left <= right) {
                if (left == idx) {
                    ++left;
                    if (left > right) {
                        answer.push_back(product);
                    }
                } else if (idx == right) {
                    --right;
                } else if (left == right) {
                    product = product * nums[left];
                    answer.push_back(product);
                    ++left;
                } else {
                    product *= nums[left] * nums[right];
                    ++left;
                    --right;
                    if (left > right) { 
                        answer.push_back(product); 
                    }
                }
            }
        }

        return answer;
    }*/
};

void print_result(vector<int> nums) {
    for (auto num : nums) {
        cout << num << " ";
    }
    putchar('\n');
}

int main() {
    Solution soln = Solution();

    vector<int> nums = { 1,2,3,4 };
    auto res = soln.productExceptSelf(nums);
    print_result(res);

    nums = { -1,1,0,-3,3 };
    res = soln.productExceptSelf(nums);
    print_result(res);

    return 0;
}
