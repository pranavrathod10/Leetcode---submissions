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
class RobbedRoot {
public:
    int robbedRoot;
    int skippedRoot;
    RobbedRoot(int a,int b){
        robbedRoot = a;
        skippedRoot = b;
    }
};

class Solution {
private:
    RobbedRoot dfs(TreeNode* root){
        if(root == nullptr){
            return RobbedRoot(0,0);
        }

        RobbedRoot robLeft = dfs(root->left);
        RobbedRoot robRight = dfs(root->right);

        int robThis = root->val + robLeft.skippedRoot + robRight.skippedRoot;
        int skipThis = robLeft.robbedRoot + robRight.robbedRoot;

        return RobbedRoot(robThis,skipThis);

    }
public:
    int rob(TreeNode* root) {
        RobbedRoot res = dfs(root);
        return max(res.robbedRoot , res.skippedRoot);
    }
};