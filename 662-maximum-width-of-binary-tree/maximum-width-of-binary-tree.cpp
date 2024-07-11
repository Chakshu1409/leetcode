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
        
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root,1});
        unsigned long long maxWidth=0;
        while(!q.empty()){
            unsigned long long frontInd=q.front().second;
            unsigned long long backInd=q.back().second;
            maxWidth= max(maxWidth, backInd-frontInd+1);

            int size=q.size();

            while(size--){
                unsigned long long topInd=q.front().second;
                TreeNode* current=q.front().first;
                q.pop();
                if(current->left != NULL){
                    q.push({current->left, 2*topInd});
                }
                if(current->right != NULL){
                    q.push({current->right, 2*topInd+1});
                }

            }

        }
        return maxWidth;


    }
};