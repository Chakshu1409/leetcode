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
    int recurr(TreeNode* root,bool& ans){
        if(root==NULL){
            return 0;
        }

        int left=recurr(root->left,ans);
        int right=recurr(root->right,ans);

        if(abs(left-right) > 1){
            ans=false;
        }

        return 1+max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        bool ans=true;
        int hieghtBalance=recurr(root,ans);
        return ans;
    }
};