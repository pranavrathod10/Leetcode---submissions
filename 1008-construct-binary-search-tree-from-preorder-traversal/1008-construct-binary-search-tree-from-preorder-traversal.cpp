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
    TreeNode* func(vector<int>& preorder, int start,int end,int n){
        if(start > end){
            return nullptr;
        }
        int rootVal = preorder[start];
        TreeNode* root = new TreeNode(rootVal);
        if(start == end){
            return root;
        }
        bool flag = false;
        for(int i=start+1;i<=end;i++){
            if(preorder[i] > rootVal){
                flag = true;
                root->left =  func(preorder,start+1,i-1,n);
                root->right = func(preorder,i,end,n);
                break;
            }
        }
        if(flag == false){
            root->left = func(preorder,start+1,end,n);
            root->right = nullptr;
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return func(preorder,0,n-1,n);
    }
};