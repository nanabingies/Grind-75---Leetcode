#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

    int height(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = height(root->left);
        if (leftHeight == -1)   return -1;

        int rightHeight = height(root->right);
        if (rightHeight == -1)  return -1;

        if (std::abs(leftHeight - rightHeight) > 1)
            return -1;

        return std::max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    Solution soln{};

    // [1,2,2,3,3,null,null,4,4]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);

    std::cout << soln.isBalanced(root) << std::endl;

    return 0;
}