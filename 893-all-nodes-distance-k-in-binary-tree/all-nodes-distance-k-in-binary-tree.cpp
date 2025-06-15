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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int> > map;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();

            if(front->left!=NULL){
                map[front->val].push_back(front->left->val);
                map[front->left->val].push_back(front->val);
                q.push(front->left);
            }
            if(front->right!=NULL){
                map[front->val].push_back(front->right->val);
                map[front->right->val].push_back(front->val);
                q.push(front->right);
            }
        }


        queue<vector<int>> qu;

        qu.push({target->val,-1,0});

        vector<int> ans;

        while(!qu.empty()){
            int size=qu.size();

            for(int i=0; i<size; i++){
                int frontVal=qu.front()[0];
                int frontPar=qu.front()[1];
                int height=qu.front()[2];
                qu.pop();

                if(height==k){
                    ans.push_back(frontVal);
                }

                for(auto it: map[frontVal]){
                    if(it == frontPar){
                        continue;
                    }
                    qu.push({it,frontVal,height+1});
                }
            }
        }
        return ans;
    }
};