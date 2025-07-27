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
    int funct(TreeNode* root, int& ans, int& maxi){
        if(root==NULL){
            return 0;
        }
        maxi=max(maxi, root->val);
        int left= funct(root->left, ans, maxi);

        int right=funct(root->right, ans, maxi);

        ans=max(ans, root->val+left+right);
        ans=max(ans, root->val+max(left, right));
        ans=max(ans, max(left,right));

        return max(0,max(left, right)+root->val);
    }

    int maxPathSum(TreeNode* root) {
        int ans=0;
        int maxi=INT_MIN;
        int maxPriceLeftRight=funct(root, ans,maxi);

        if(ans==0){
            return maxi;
        }
        return ans;
    }
};