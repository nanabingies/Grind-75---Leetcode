#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> results{};
        int idx = 0;

        while (idx != intervals.size() && intervals[idx][1] < newInterval[0]) {
            results.push_back(intervals[idx]);
            idx += 1;
        }

        while (idx != intervals.size() && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx += 1;
        }

        results.push_back(newInterval);

        while (idx != intervals.size()) {
            results.push_back(intervals[idx]);
            idx += 1;
        }

        return results;
    }
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

    vector<vector<int>> intervals = {{1,3}, {6,9}};
    vector<int> newInterval = {2,5};
    auto res = soln.insert(intervals, newInterval);
    print_results(res);

    intervals = {{1,5}};
    newInterval = {2,3};
    res = soln.insert(intervals, newInterval);
    print_results(res);

    intervals = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
    newInterval = {4,8};
    res = soln.insert(intervals, newInterval);
    print_results(res);

    intervals = {};
    newInterval = {5,7};
    res = soln.insert(intervals, newInterval);
    print_results(res);

    return 0;
}