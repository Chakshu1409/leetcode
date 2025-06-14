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
    TreeNode* recurr(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root==q){
            return root;
        }

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left!=NULL && right!=NULL){
            return root;
        }

        if(left != NULL && right==NULL){
            return left;
        }
        if(left == NULL && right!=NULL){
            return right;
        }
        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* rec=recurr(root,p,q);
        return rec;
    }
};