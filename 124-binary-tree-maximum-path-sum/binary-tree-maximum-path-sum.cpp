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

        if(root == NULL){
            return 0;
        }

        int left = recurr(root->left, ans);
        int right = recurr(root->right, ans);

        int leftPlusRoot=root->val + left;
        int rightPlusRoot=root->val + right;
        int onlyRoot=root->val;
        int leftPlusRootPlusRight=root->val + left + right;

        ans = max(ans, max(max(onlyRoot, leftPlusRootPlusRight), max(leftPlusRoot, rightPlusRoot)));

        return max(0, max(onlyRoot, max(leftPlusRoot, rightPlusRoot)));
    }

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int x=recurr(root, ans);

        return ans;
    }
};