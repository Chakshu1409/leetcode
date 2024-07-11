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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* current = root;
        vector<int> ans;
        while(current != NULL){
            if(current->left == NULL){
                ans.push_back(current->val);
                current=current->right;
                continue;
            }

            TreeNode* left=current->left;
            while(left->right != NULL && left->right != current){
                left=left->right;
            }
            
            if(left->right == current){
                left->right=NULL;
                ans.push_back(current->val);
                current=current->right;
                continue;
            }
            left->right=current;
            current=current->left;

        }

        return ans;

    }
};