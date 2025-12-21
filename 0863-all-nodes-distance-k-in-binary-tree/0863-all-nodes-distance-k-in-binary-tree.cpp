/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> func(int target,int k,unordered_map<int, vector<int>>& adj,int parent){

        queue<int> q;
        q.push(target);
        int dist = 0;
        unordered_map<int,bool> visited;
        vector<int> ans;
        visited[target] = true;
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                int curr = q.front();q.pop();
                for(int node: adj[curr]){
                    if(visited[node] == false){
                        visited[node] = true;
                        q.push(node);
                    }
                    
                }

            }
            dist++;
            if(dist == k){
                while(!q.empty()){
                    ans.push_back(q.front());
                    q.pop();
                }
                return ans;
            }
        }

        return ans;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adj;
        queue<TreeNode*> q;
        q.push(root);
        if(k==0){
            return {target->val};
        }

        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                auto curr = q.front();
                q.pop();
                if(curr->left ){
                    int childVal = curr->left->val;
                    q.push(curr->left);
                    adj[childVal].push_back(curr->val);
                    adj[curr->val].push_back(childVal);
                }
                if(curr->right ){
                    int childValr = curr->right->val;
                    q.push(curr->right);
                    adj[childValr].push_back(curr->val);
                    adj[curr->val].push_back(childValr);
                }
            }
            
        }

        return func(target->val,k,adj,-1);
    }
};