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
    int ans = 0;
    int func(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftSum = 0, rightSum=0;
        if(root->left){
            leftSum = 1 + func(root->left);
        }
        if(root->right){
            rightSum = 1 + func(root->right);
        }
        ans = max(ans,leftSum+ rightSum);
        return max(leftSum,rightSum);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int temp = func(root);
        return ans;
    }
};