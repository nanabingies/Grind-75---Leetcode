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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)    return nullptr;

        // Swap left & right nodes
        std::swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

    void printTree(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);

        std::cout << "\t ";

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            std::cout << temp->val << " ";

            if (temp->left != nullptr)  q.push(temp->left);
            if (temp->right != nullptr) q.push(temp->right);
        }

        std::cout << std::endl;
    }
};

int main(int argc, char* argv[]) {
    Solution soln{};

    // [4,2,7,1,3,6,9]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    auto node = soln.invertTree(root);
    soln.printTree(node);

    return 0;
}