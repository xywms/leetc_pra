/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    //如何迭代呢？使用栈
    vector<int> res;
    stack<TreeNode*> s;
    //这里的while条件是或者！
    while(root != nullptr || !s.empty()) {
        while(root != nullptr) {
            s.push(root);
            root = root->left;
        }
        //这一步为何
        root = s.top();
        s.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
    }
};
