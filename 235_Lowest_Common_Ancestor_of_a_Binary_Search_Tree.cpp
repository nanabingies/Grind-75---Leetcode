#include <iostream>
using namespace std;

struct TreeNode;
void printNode(TreeNode*);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }

    /*TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> rootNodes{};
        function<void(TreeNode*, TreeNode*, TreeNode*, vector<TreeNode*>&, bool&, bool&)> dfs;

        dfs = [&](TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& rootNodes, bool& lFound, bool& rFound) -> void {
            if (root == nullptr) { return; }
            if (root->left == nullptr && root->right == nullptr) { return; }
            if (rFound && lFound) { return; }

            rootNodes.push_back(root);
            
            if (root->val == p->val) { lFound = true; }
            if (root->val == q->val) { rFound = true; }
            if (rFound && lFound) { return; }

            dfs(root->left, p, q, rootNodes, lFound, rFound);
            if (lFound && rFound) { return; }
            
            dfs(root->right, p, q, rootNodes, lFound, rFound);

            if (!rootNodes.empty()) { rootNodes.pop_back(); }
        };

        bool l = false, r = false;
        dfs(root, p, q, rootNodes, l, r);

        return rootNodes.empty() ? nullptr : rootNodes.back();
    }*/
};

int main() {
    Solution soln = Solution();

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    
    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(8);
    auto res = soln.lowestCommonAncestor(root, p, q);
    cout << res->val << endl;

    delete q;
    q = new TreeNode(4);
    res = soln.lowestCommonAncestor(root, p, q);
    cout << res->val << endl;
    return 0;
}

void printNode(TreeNode* node) {
    if (node == nullptr) { return; }
    queue<TreeNode*> _q{};
    _q.push(node);

    while (!_q.empty()) {
        TreeNode* top = _q.front();
        cout << top->val << " ";
        _q.pop();

        if (top->left != nullptr) { _q.push(top->left); }
        if (top->right != nullptr) { _q.push(top->right); }
    }
    cout << endl;
}
