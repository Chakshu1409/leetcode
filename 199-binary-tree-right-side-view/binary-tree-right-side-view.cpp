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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        while(!q.empty()){

            int size=q.size();
            
            for(int i=0; i<size; i++){
                TreeNode* front=q.front();
                q.pop();
                if(i==size-1){
                    ans.push_back(front->val);
                }

                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
        }
        return ans;
    }
};