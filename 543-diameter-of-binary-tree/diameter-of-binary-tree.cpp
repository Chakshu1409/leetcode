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
    int recurr(TreeNode* root, int& ans){
        if(root==NULL){
            return 0;
        }

        int left=recurr(root->left,ans);
        int right=recurr(root->right,ans);

        ans= max(ans, left+right);

        return 1+max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        int height=recurr(root,ans);
        return ans;
    }
};