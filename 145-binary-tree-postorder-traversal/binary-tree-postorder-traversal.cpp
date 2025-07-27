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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> preOrder,inOrder,postOrder;

        stack<pair<TreeNode*,int>> st;

        if(root==NULL){
            return {};
        }

        st.push({root, 1});

        while(!st.empty()){
            TreeNode* currentNode=st.top().first;
            int level=st.top().second;
            st.pop();

            if(level==1){
                preOrder.push_back(currentNode->val);
                st.push({currentNode, level+1});
                if(currentNode->left != NULL){
                    st.push({currentNode->left, 1});
                }
            }
            else if(level==2){
                inOrder.push_back(currentNode->val);
                st.push({currentNode, level+1});
                if(currentNode->right != NULL){
                    st.push({currentNode->right, 1});
                }
            }
            else{
                postOrder.push_back(currentNode->val);
            }
        }
        return postOrder;
    }
};