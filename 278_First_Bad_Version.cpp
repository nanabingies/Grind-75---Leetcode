#include <vector>
#include <iostream>
using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version); // { if (version == 3) { return true; } return false; }

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;

        while (start < end) {
            int middle = start + (end - start) / 2;
            if (isBadVersion(middle)) {
                end = middle;
            } else {
                start = middle + 1;
            }
        }

        return start;
    }
};

int main() {
    Solution soln = Solution();

    int n = 5;  // res = 4
    cout << soln.firstBadVersion(n) << endl;

    return 0;
}
