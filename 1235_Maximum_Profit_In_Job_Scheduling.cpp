#include <iostream>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        if (profit.size() == 0) { return 0; }
        if (profit.size() == 1) { return profit[0]; }

        
    }
};

int main() {
    Solution soln = Solution();

    vector<int> startTime = {1,2,3,3};
    vector<int> endTime = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    cout << soln.jobScheduling(startTime, endTime, profit) << endl;
}
