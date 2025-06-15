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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ans=0;

        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,1});

        while(!q.empty()){
            int size=q.size();
            unsigned long long currentStart=0;
            unsigned long long currentEnd=0;
            for(int i=0; i<size; i++){
                TreeNode* node=q.front().first;
                unsigned long long num=q.front().second;

                q.pop();

                if(i==0){
                    currentStart=num;
                }
                if(i==size-1){
                    currentEnd=num;
                }

                if(node->left != NULL){
                    q.push({node->left, 2*num});
                }
                if(node->right != NULL){
                    q.push({node->right, 2*num+1});
                }
            }
            // cout<<currentEnd<<" "<<currentStart<<endl;
            ans = max(ans, currentEnd-currentStart+1);
        }
        return ans;
    }
};