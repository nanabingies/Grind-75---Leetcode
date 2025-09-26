#include <vector>
#include <iostream>
using namespace std;

void printVec(vector<int>& matrix);

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> u_v{};
        if (matrix.empty()) { return u_v; }

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        
        while (top <= bottom && left <= right) {
            // top -> right
            for (int i = left; i <= right; ++i) {
                u_v.push_back(matrix[left][i]);
            }
            ++top;

            // right -> bottom
            for (int i = top; i <= bottom; ++i) {
                u_v.push_back(matrix[i][right]);
            }
            --right;

            if (top <= bottom) {
                if (right < 0) { continue; }
                // bottom -> left
                for (int i = right; i >= left; --i) {
                    u_v.push_back(matrix[bottom][i]);
                }
                --bottom;
            }

            if (left <= right) {
                // left -> top
                for (int i = bottom; i >= top; --i) {
                    u_v.push_back(matrix[i][left]);
                }
                ++left;
            }
        }

        return u_v;
    }
};

int main() {
    Solution soln = Solution();

    // 1,2,3,4,8,12,11,10,9,5,6,7
    vector<vector<int>> matrix = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
    auto res = soln.spiralOrder(matrix);
    printVec(res);

    // 1,2,3,6,9,8,7,4,5
    matrix = { {1,2,3}, {4,5,6}, {7,8,9} };
    res = soln.spiralOrder(matrix);
    printVec(res);

    matrix = { {3}, {2} };
    res = soln.spiralOrder(matrix);
    printVec(res);

    matrix = { {1,2}, {3,4} };
    res = soln.spiralOrder(matrix);
    printVec(res);

    return 0;
}

void printVec(vector<int>& matrix) {
    for (auto elem : matrix) {
        cout << elem << " ";
    }
    putchar('\n');
}
