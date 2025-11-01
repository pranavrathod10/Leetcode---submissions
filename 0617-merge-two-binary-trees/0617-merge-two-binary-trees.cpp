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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr){
            return nullptr;
        }
        TreeNode* root = new TreeNode();
        root->val = 0;
        TreeNode *l1,*l2,*r1,*r2;
        if(root1 != nullptr){
            root->val += root1->val;
            l1 = root1->left;
            r1 = root1->right;
        }
        else{
            l1 = nullptr;
            r1 = nullptr;
        }
        if(root2 != nullptr){
            root->val += root2->val;
            l2 = root2->left;
            r2 = root2->right;
        }
        else{
            l2 = nullptr;
            r2 = nullptr;
        }

        root->left = mergeTrees(l1,l2);
        root->right = mergeTrees(r1,r2);

        return root;

    }
};